import Types::*;
import ProcTypes::*;
import MemTypes::*;
//import RFile::*;

import BypassRFile::*;
//import BypassRFile::*; 
import IMemory::*;
import DMemory::*;
import Decode::*;
import Exec::*;
import Cop::*;
import Fifo::*;
import Scoreboard::*;

typedef struct {
	Inst inst;
	Addr pc;
	Addr ppc;
	Bool epoch;
} Fetch2Decode deriving(Bits, Eq);

typedef struct {
	DecodedInst dInst;
	Addr ppc;
	Bool epoch;
} Decode2Exec deriving(Bits, Eq);


(*synthesize*)
module mkProc(Proc);
	Reg#(Addr)    pc  <- mkRegU;
//	RFile         rf  <- mkRFile;
	RFile		  rf  <- mkBypassRFile;
	IMemory     iMem  <- mkIMemory;	
	DMemory     dMem  <- mkDMemory;
	Cop          cop  <- mkCop;

	Reg#(CondFlag) 	 	condFlag	<- mkRegU;
	Reg#(ProcStatus)   	stat		<- mkRegU;

	Fifo#(1,Addr)       execRedirect <- mkBypassFifo;
	Fifo#(1,Addr)		memRedirect  <- mkBypassFifo;
	Fifo#(1,ProcStatus) statRedirect <- mkBypassFifo;

	Fifo#(1,Fetch2Decode) f2d        <- mkPipelineFifo;
	Fifo#(1,Decode2Exec) d2e        <- mkPipelineFifo;
	Fifo#(1,Maybe#(ExecInst)) e2m        <- mkPipelineFifo;
	Fifo#(1,Maybe#(ExecInst)) m2w        <- mkPipelineFifo;

	Scoreboard#(4) sb <- mkPipelineScoreboard;

	Reg#(Bool) fEpoch <- mkRegU;
	Reg#(Bool) eEpoch <- mkRegU;

	rule doFetch(cop.started && stat == AOK);

		let epoch = fEpoch;
		let p = pc;

		if(execRedirect.notEmpty)
		begin
			epoch = !epoch;
	//		fEpoch <= !fEpoch;
			execRedirect.deq;
			p = execRedirect.first;
		end		 
//		else
//		begin

		fEpoch <= epoch;

		let inst = iMem.req(p);
		let ppc = nextAddr(p, getICode(inst));

			$display("Fetch : from Pc %d , expanded inst : %x, \n", pc, inst, showInst(inst)); 

			pc <= ppc;
			f2d.enq(Fetch2Decode{inst:inst, pc:pc, ppc:ppc, epoch:epoch});
//		end

	endrule

	rule doDecode(cop.started && stat == AOK);
		let inst   = f2d.first.inst;
		let ipc 	 = f2d.first.pc;
		let ppc    = f2d.first.ppc;
		let iEpoch = f2d.first.epoch;

		//Decode 
		let dInst = decode(inst, ipc);
		$display("Decode : from Pc %d , expanded inst : %x, \n", ipc, inst, showInst(inst)); 


		let stall = sb.search1(dInst.regA) || sb.search2(dInst.regB) || sb.search3(dInst.dstE) || sb.search4(dInst.dstM);


		if(!stall)
		begin
			sb.insertE(dInst.dstE); 
			sb.insertM(dInst.dstM);

			dInst.valA   = isValid(dInst.regA)? tagged Valid rf.rdA(validRegValue(dInst.regA)) : Invalid;
			dInst.valB   = isValid(dInst.regB)? tagged Valid rf.rdB(validRegValue(dInst.regB)) : Invalid;
			dInst.copVal = isValid(dInst.regA)? tagged Valid cop.rd(validRegValue(dInst.regA)) : Invalid;
		
			d2e.enq(Decode2Exec{dInst:dInst, ppc:ppc, epoch:iEpoch});
			f2d.deq;
		end
	endrule

			//Exec
	rule doExecute(cop.started && stat == AOK);
    	let dInst   = d2e.first.dInst;
    	let iEpoch   = d2e.first.epoch;
    	let ppc    = d2e.first.ppc;

		if(memRedirect.notEmpty)
		begin
			memRedirect.deq;
			eEpoch <= !eEpoch;
			execRedirect.enq(memRedirect.first);
			e2m.enq(Invalid);
		end
		else if(iEpoch == eEpoch)
		begin
			let eInst = exec(dInst, condFlag, ppc);
			condFlag <= eInst.condFlag;

//		if(!memRedirect.notEmpty && eInst.mispredict)
      	if(eInst.mispredict)
		begin
        	let redirPc = validValue(eInst.nextPc);
        	eEpoch <= !eEpoch;
        	execRedirect.enq(redirPc);
			$display("mispredicted, redirect %d ", redirPc);
      	end

      	e2m.enq(Valid(eInst));
    end
    else
    begin
      	e2m.enq(Invalid);
    end
    d2e.deq;

  endrule

  rule doMemory(cop.started && stat == AOK);
    	if (isValid(e2m.first))
    	begin
      		let eInst   = validValue(e2m.first);

			//Memory 
			let iType = eInst.iType;
			case(iType)
				MRmov, Pop, Ret :
				begin
					let ldData <- (dMem.req(MemReq{op: Ld, addr: eInst.memAddr, data:?}));
					eInst.valM = Valid(little2BigEndian(ldData));
					$display("Loaded %d from %d",little2BigEndian(ldData), eInst.memAddr);
					if(iType == Ret)
					begin
						eInst.nextPc = eInst.valM;
			            memRedirect.enq(validValue(eInst.nextPc));
            
					end
				end

				RMmov, Call, Push :
				begin
					let stData = (iType == Call)? eInst.valP : validValue(eInst.valA); 
					let dummy <- dMem.req(MemReq{op: St, addr: eInst.memAddr, data: big2LittleEndian(stData)});
					$display("Stored %d into %d",stData, eInst.memAddr);
				end
			endcase

    		m2w.enq(Valid(eInst));
    	end
    	else
    	begin
      		m2w.enq(Invalid);
    	end
    	e2m.deq;

  endrule


 rule doWriteBack(cop.started && stat == AOK);
    if (isValid(m2w.first))
    begin

      let eInst   = validValue(m2w.first);

			//Update Status
			let newStatus = case(eInst.iType)
								Unsupported : INS;
								Hlt 		  : HLT;
								default     : AOK;
							endcase;
			statRedirect.enq(newStatus);

//			if(eInst.mispredict)			
//			begin
//				eEpoch <= !eEpoch;
//				let redirPc = validValue(eInst.nextPc);
//				$display("mispredicted, redirect %d ", redirPc);
//				execRedirect.enq(redirPc);
//			end
	
			//WriteBack
			if(isValid(eInst.dstE))
			begin
				$display("On %d, writes %d   (wrE)",validRegValue(eInst.dstE), validValue(eInst.valE));
				rf.wrE(validRegValue(eInst.dstE), validValue(eInst.valE));
			end
			if(isValid(eInst.dstM))
			begin
				$display("On %d, writes %d   (wrM)",validRegValue(eInst.dstM), validValue(eInst.valM));
				rf.wrM(validRegValue(eInst.dstM), validValue(eInst.valM));
			end
	
			cop.wr(eInst.dstE, validValue(eInst.valE));
		end

		m2w.deq;
		sb.remove;
	endrule

	rule upd_Stat(cop.started);
		$display("Stat update");
		statRedirect.deq;
		stat <= statRedirect.first;
	endrule

	rule statHLT(cop.started && stat == HLT);
		$fwrite(stderr,"Program Finished by halt\n");
		$finish;
	endrule 

	rule statINS(cop.started && stat == INS);
		$fwrite(stderr,"Executed unsupported instruction. Exiting\n");
		$finish;
	endrule

	method ActionValue#(Tuple3#(RIndx, Data, Data)) cpuToHost;
		let retV <- cop.cpuToHost;
		return retV;
	endmethod

	method Action hostToCpu(Bit#(32) startpc) if (!cop.started);
		cop.start;
		eEpoch <= False;
		fEpoch <= False;
		pc <= startpc;
		stat <= AOK;
	endmethod
endmodule
