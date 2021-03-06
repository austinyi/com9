/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Thu May  4 14:26:44 KST 2017
 * 
 */

/* Generation options: */
#ifndef __mkProc_h__
#define __mkProc_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkCop.h"
#include "mkDMemory.h"
#include "mkIMemory.h"
#include "mkRFile.h"


/* Class declaration for the mkProc module */
class MOD_mkProc : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_condFlag;
  MOD_mkCop INST_cop;
  MOD_mkDMemory INST_dMem;
  MOD_Reg<tUWide> INST_e2m;
  MOD_Reg<tUInt64> INST_f2e;
  MOD_mkIMemory INST_iMem;
  MOD_Reg<tUInt32> INST_pc;
  MOD_mkRFile INST_rf;
  MOD_Reg<tUInt8> INST_stage;
  MOD_Reg<tUInt8> INST_stat;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_rl;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_rl;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_rl;
 
 /* Constructor */
 public:
  MOD_mkProc(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_cpuToHost;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_cop_started____d22;
  tUWide DEF_e2m___d567;
  tUInt8 DEF_upd__h10889;
  tUInt8 DEF_upd__h12220;
  tUInt8 DEF_upd__h12278;
  tUInt8 DEF_statRedirect_deqP_dummy2_1__h11009;
  tUInt8 DEF_statRedirect_deqP_dummy2_0__h10996;
  tUInt8 DEF_statRedirect_enqP_dummy2_1__h12246;
  tUInt8 DEF_statRedirect_enqP_dummy2_0__h10815;
  tUInt8 DEF_e2m_67_BIT_278___d609;
  tUInt8 DEF_e2m_67_BIT_272___d613;
  tUInt8 DEF_y__h11042;
  tUInt8 DEF_x__h11041;
  tUInt8 DEF_IF_statRedirect_enqP_lat_0_whas__0_THEN_statRe_ETC___d13;
 
 /* Local definitions */
 private:
  tUInt32 DEF_pc__h5765;
  tUInt8 DEF_statRedirect_data_0_rl__h1679;
  tUWide DEF_e2m_67_BITS_134_TO_66___d631;
  tUInt32 DEF_e2m_67_BITS_265_TO_234___d617;
  tUInt32 DEF_x__h10448;
  tUInt32 DEF_x__h10533;
  tUInt8 DEF_e2m_67_BITS_277_TO_273___d610;
  tUInt8 DEF_e2m_67_BITS_282_TO_279___d568;
  tUInt8 DEF_e2m_67_BIT_266___d616;
  tUInt8 DEF_e2m_67_BIT_167___d624;
  tUInt8 DEF_e2m_67_BIT_65___d632;
  tUInt32 DEF_IF_e2m_67_BIT_266_16_THEN_e2m_67_BITS_265_TO_2_ETC___d618;
  tUInt8 DEF_IF_statRedirect_data_0_lat_0_whas_THEN_statRed_ETC___d6;
  tUWide DEF_e2m_67_BITS_282_TO_279_68_CONCAT_e2m_67_BIT_27_ETC___d649;
  tUInt8 DEF_e2m_67_BIT_278_09_CONCAT_IF_e2m_67_BIT_278_09__ETC___d612;
  tUWide DEF_e2m_67_BIT_272_13_CONCAT_IF_e2m_67_BIT_272_13__ETC___d648;
  tUWide DEF_IF_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_OR_f2e_51_ETC___d559;
  tUWide DEF_IF_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_OR_f2e_51_ETC___d558;
  tUWide DEF_NOT_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_93_AND_N_ETC___d557;
  tUWide DEF_e2m_67_BIT_233_88_CONCAT_IF_e2m_67_BIT_233_88__ETC___d647;
  tUWide DEF_e2m_67_BITS_282_TO_279_68_EQ_4_69_OR_e2m_67_BI_ETC___d646;
  tUWide DEF_DONTCARE_CONCAT_IF_f2e_51_BITS_47_TO_44_52_EQ__ETC___d556;
  tUWide DEF_IF_IF_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_OR_f2e_ETC___d555;
  tUWide DEF_IF_e2m_67_BITS_282_TO_279_68_EQ_4_69_OR_e2m_67_ETC___d645;
  tUWide DEF_IF_IF_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_OR_f2e_ETC___d554;
  tUWide DEF_IF_IF_f2e_51_BITS_47_TO_44_52_EQ_0b0_53_OR_f2e_ETC___d553;
  tUWide DEF_NOT_e2m_67_BITS_282_TO_279_68_EQ_4_69_80_AND_N_ETC___d600;
 
 /* Rules */
 public:
  void RL_statRedirect_data_0_canon();
  void RL_statRedirect_enqP_canon();
  void RL_statRedirect_deqP_canon();
  void RL_doFetch();
  void RL_doExecute();
  void RL_doMemory();
  void RL_doWriteBack();
  void RL_upd_Stat();
  void RL_statHLT();
  void RL_statINS();
 
 /* Methods */
 public:
  tUWide METH_cpuToHost();
  tUInt8 METH_RDY_cpuToHost();
  void METH_hostToCpu(tUInt32 ARG_hostToCpu_startpc);
  tUInt8 METH_RDY_hostToCpu();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
};

#endif /* ifndef __mkProc_h__ */
