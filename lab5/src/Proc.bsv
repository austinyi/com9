import Types::*;
import ProcTypes::*;
import MemTypes::*;
import RFile::*;
import IMemory::*;
import DMemory::*;
import Decode::*;
import Exec::*;
import Cop::*;
import Fifo::*;

typedef struct {
	Inst inst;
	Addr pc;
	Addr ppc;
	Bool epoch;
} Fetch2Decode deriving(Bits, Eq);

typedef struct {
	DecodedInst inst;
	Addr pc;
	Addr ppc;
	Bool epoch;
} Decode2Rest deriving(Bits, Eq);
	
(*synthesize*)
module mkProc(Proc);
  Reg#(Addr)    pc  <- mkRegU;
  RFile         rf  <- mkRFile;
  IMemory     iMem  <- mkIMemory;
  DMemory     dMem  <- mkDMemory;
  Cop          cop  <- mkCop;

  Reg#(CondFlag) 	    condFlag	 <- mkRegU;
  Reg#(ProcStatus)      stat		 <- mkRegU;

  Fifo#(1,Addr)         execRedirect <- mkCFFifo;
  Fifo#(1,ProcStatus)   statRedirect <- mkBypassFifo;

  Fifo#(2,Fetch2Decode)	f2d    	     <- mkCFFifo;
  Fifo#(2,Decode2Rest) d2r			<- mkCFFifo;

  Reg#(Bool) fEpoch <- mkRegU;
  Reg#(Bool) eEpoch <- mkRegU;

  rule doFetch(cop.started && stat == AOK);	
	  let inst = iMem.req(pc);
	  let iCode = getICode(inst);
	  let ppc = nextAddr(pc,iCode);
	
	  if(eEpoch == fEpoch)	
		  pc <= ppc;

	  f2d.enq(Fetch2Decode{inst:inst, pc:pc, ppc:ppc, epoch:fEpoch});
	  $display("Fetch : from Pc %d , expanded inst : %x, \n", pc, inst, showInst(inst)); 
  endrule

  rule doDecode(cop.started && stat == AOK);
	  let inst   = f2d.first.inst;
	  let pc 	 = f2d.first.pc;
	  let ppc    = f2d.first.ppc;
	  let iEpoch = f2d.first.epoch;
	  f2d.deq;

	  if(iEpoch == eEpoch)
	  begin
		  //Decode 
		  let dInst = decode(inst, pc);
		  d2r.enq(Decode2Rest{inst:dInst, pc:pc, ppc:ppc, epoch:iEpoch});
	end

  endrule  	  

  rule doRest(cop.started && stat == AOK);
	  let dInst   = d2r.first.inst;
	  let pc2 	 = d2r.first.pc;
	  let ppc    = d2r.first.ppc;
	  let iEpoch = d2r.first.epoch;
	  d2r.deq;

	  if(iEpoch == eEpoch)
	  begin
		  //Decode 
		  dInst.valA   = isValid(dInst.regA)? tagged Valid rf.rdA(validRegValue(dInst.regA)) : Invalid;
   		  dInst.valB   = isValid(dInst.regB)? tagged Valid rf.rdB(validRegValue(dInst.regB)) : Invalid;
		  dInst.copVal = isValid(dInst.regA)? tagged Valid cop.rd(validRegValue(dInst.regA)) : Invalid;
		  
		  //Exec
		  let eInst = exec(dInst, condFlag, ppc);
		  condFlag <= eInst.condFlag;

		  //Memory 
	      let iType = eInst.iType;
	      case(iType)
	 		MRmov, Pop, Ret :
   	 		begin
	   			let ldData <- (dMem.req(MemReq{op: Ld, addr: eInst.memAddr, data:?}));
		   		eInst.valM = Valid(little2BigEndian(ldData));
				if(iType == Ret)//Return address is known here
				begin
					eInst.nextPc = eInst.valM;
				end
	   		end

			RMmov, Call, Push :
			begin
				let stData = (iType == Call)? eInst.valP : validValue(eInst.valA); 
		  		let dummy <- dMem.req(MemReq{op: St, addr: eInst.memAddr, data: big2LittleEndian(stData)});
			end
	  	  endcase

		  case(iType)
        	Call, Jmp, Ret :
          		cop.incInstTypeCnt(Ctr);
        	RMmov, MRmov, Push, Pop :
          		cop.incInstTypeCnt(Mem);
       	  endcase

		  //Update Status
		  let newStatus = case(iType)
		  				      Unsupported : INS;
							  Hlt 		  : HLT;
							  default     : AOK;
						  endcase;

		  if(eInst.mispredict)			
		  begin
		  	  eEpoch <= !eEpoch;
			  let redirPc = validValue(eInst.nextPc);
			  $display("mispredicted, redirect %d ", redirPc);
			  cop.incBPMissCnt();
			  pc <= redirPc;
			  fEpoch <= !fEpoch;
        	case(iType)
          		Call:
            		cop.incMissInstTypeCnt(MTCallMiss);
          		Jmp:
            		cop.incMissInstTypeCnt(MTJmpMiss);
          		Ret :
            		cop.incMissInstTypeCnt(MTRetMiss);
        	endcase
      	  end
      	  else
      		begin
        		case(iType)
          			Call:
            			cop.incMissInstTypeCnt(MTCall);
          			Jmp:
            			cop.incMissInstTypeCnt(MTJmp);
          			Ret :
            			cop.incMissInstTypeCnt(MTRet);
        		endcase
      		end
	 	  

		statRedirect.enq(newStatus);

		  //WriteBack
		if(isValid(eInst.dstE))
		begin
			rf.wrE(validRegValue(eInst.dstE), validValue(eInst.valE));
		end
		if(isValid(eInst.dstM))
		begin
			rf.wrM(validRegValue(eInst.dstM), validValue(eInst.valM));
		end
		cop.wr(eInst.dstE, validValue(eInst.valE));


		/*	Exercise 3
			1. Use cop.incInstTypeCnt(instType) to count number of each instruciton type
			   - instType list
				Ctr(Control) 	 : call, ret, jump
				Mov(Move)		 : mrmovl, rmmovl, push, call
            
			2. Use cop.incBPMissCnt() to count number of mispredictions.
			
			Excercise 4
			1. Implement incInstTypeCnt(InstCntType inst) method in Cop.bsv
			2. Use cop.incInstTypeCnt(inst) to count number of mispredictions for each instruction types.
			
		*/
	end
  endrule



  rule upd_Stat(cop.started);
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

