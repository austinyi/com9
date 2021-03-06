/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Tue May 30 23:22:01 KST 2017
 * 
 */

/* Generation options: */
#ifndef __mkBypassRFile_h__
#define __mkBypassRFile_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkBypassRFile module */
class MOD_mkBypassRFile : public Module {
 
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
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_0_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_0_lat_0;
  MOD_Wire<tUInt32> INST_rFile_0_lat_1;
  MOD_Wire<tUInt32> INST_rFile_0_lat_2;
  MOD_Reg<tUInt32> INST_rFile_0_rl;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_1_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_1_lat_0;
  MOD_Wire<tUInt32> INST_rFile_1_lat_1;
  MOD_Wire<tUInt32> INST_rFile_1_lat_2;
  MOD_Reg<tUInt32> INST_rFile_1_rl;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_2_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_2_lat_0;
  MOD_Wire<tUInt32> INST_rFile_2_lat_1;
  MOD_Wire<tUInt32> INST_rFile_2_lat_2;
  MOD_Reg<tUInt32> INST_rFile_2_rl;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_3_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_3_lat_0;
  MOD_Wire<tUInt32> INST_rFile_3_lat_1;
  MOD_Wire<tUInt32> INST_rFile_3_lat_2;
  MOD_Reg<tUInt32> INST_rFile_3_rl;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_4_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_4_lat_0;
  MOD_Wire<tUInt32> INST_rFile_4_lat_1;
  MOD_Wire<tUInt32> INST_rFile_4_lat_2;
  MOD_Reg<tUInt32> INST_rFile_4_rl;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_5_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_5_lat_0;
  MOD_Wire<tUInt32> INST_rFile_5_lat_1;
  MOD_Wire<tUInt32> INST_rFile_5_lat_2;
  MOD_Reg<tUInt32> INST_rFile_5_rl;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_6_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_6_lat_0;
  MOD_Wire<tUInt32> INST_rFile_6_lat_1;
  MOD_Wire<tUInt32> INST_rFile_6_lat_2;
  MOD_Reg<tUInt32> INST_rFile_6_rl;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_2;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_0_0;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_0_1;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_0_2;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_1_0;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_1_1;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_1_2;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_2_0;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_2_1;
  MOD_Wire<tUInt64> INST_rFile_7_dummy_2_2;
  MOD_Wire<tUInt32> INST_rFile_7_lat_0;
  MOD_Wire<tUInt32> INST_rFile_7_lat_1;
  MOD_Wire<tUInt32> INST_rFile_7_lat_2;
  MOD_Reg<tUInt32> INST_rFile_7_rl;
 
 /* Constructor */
 public:
  MOD_mkBypassRFile(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
  tUInt32 DEF_upd__h18559;
  tUInt32 DEF_upd__h18628;
  tUInt32 DEF_upd__h18661;
  tUInt32 DEF_upd__h18436;
  tUInt32 DEF_upd__h18505;
  tUInt32 DEF_upd__h18538;
  tUInt32 DEF_upd__h18313;
  tUInt32 DEF_upd__h18382;
  tUInt32 DEF_upd__h18415;
  tUInt32 DEF_upd__h18190;
  tUInt32 DEF_upd__h18259;
  tUInt32 DEF_upd__h18292;
  tUInt32 DEF_upd__h18067;
  tUInt32 DEF_upd__h18136;
  tUInt32 DEF_upd__h18169;
  tUInt32 DEF_upd__h17944;
  tUInt32 DEF_upd__h18013;
  tUInt32 DEF_upd__h18046;
  tUInt32 DEF_upd__h17821;
  tUInt32 DEF_upd__h17890;
  tUInt32 DEF_upd__h17923;
  tUInt32 DEF_upd__h17698;
  tUInt32 DEF_upd__h17767;
  tUInt32 DEF_upd__h17800;
  tUInt8 DEF_rFile_7_dummy2_2__h18589;
  tUInt8 DEF_rFile_7_lat_0_whas____d75;
  tUInt8 DEF_rFile_6_dummy2_2__h18466;
  tUInt8 DEF_rFile_6_lat_0_whas____d65;
  tUInt8 DEF_rFile_5_dummy2_2__h18343;
  tUInt8 DEF_rFile_5_lat_0_whas____d55;
  tUInt8 DEF_rFile_4_dummy2_2__h18220;
  tUInt8 DEF_rFile_4_lat_0_whas____d45;
  tUInt8 DEF_rFile_3_dummy2_2__h18097;
  tUInt8 DEF_rFile_3_lat_0_whas____d35;
  tUInt8 DEF_rFile_2_dummy2_2__h17974;
  tUInt8 DEF_rFile_2_lat_0_whas____d25;
  tUInt8 DEF_rFile_1_dummy2_2__h17851;
  tUInt8 DEF_rFile_1_lat_0_whas____d15;
  tUInt8 DEF_rFile_0_dummy2_2__h17728;
  tUInt8 DEF_rFile_0_lat_0_whas____d5;
  tUInt32 DEF_n__read__h17696;
  tUInt32 DEF_IF_rFile_7_lat_1_whas__3_THEN_rFile_7_lat_1_wg_ETC___d79;
  tUInt32 DEF_n__read__h17694;
  tUInt32 DEF_IF_rFile_6_lat_1_whas__3_THEN_rFile_6_lat_1_wg_ETC___d69;
  tUInt32 DEF_n__read__h17692;
  tUInt32 DEF_IF_rFile_5_lat_1_whas__3_THEN_rFile_5_lat_1_wg_ETC___d59;
  tUInt32 DEF_n__read__h17690;
  tUInt32 DEF_IF_rFile_4_lat_1_whas__3_THEN_rFile_4_lat_1_wg_ETC___d49;
  tUInt32 DEF_n__read__h17688;
  tUInt32 DEF_IF_rFile_3_lat_1_whas__3_THEN_rFile_3_lat_1_wg_ETC___d39;
  tUInt32 DEF_n__read__h17686;
  tUInt32 DEF_IF_rFile_2_lat_1_whas__3_THEN_rFile_2_lat_1_wg_ETC___d29;
  tUInt32 DEF_n__read__h17684;
  tUInt32 DEF_IF_rFile_1_lat_1_whas__3_THEN_rFile_1_lat_1_wg_ETC___d19;
  tUInt32 DEF_n__read__h17682;
  tUInt32 DEF_IF_rFile_0_lat_1_whas_THEN_rFile_0_lat_1_wget__ETC___d9;
 
 /* Rules */
 public:
  void RL_rFile_0_canon();
  void RL_rFile_1_canon();
  void RL_rFile_2_canon();
  void RL_rFile_3_canon();
  void RL_rFile_4_canon();
  void RL_rFile_5_canon();
  void RL_rFile_6_canon();
  void RL_rFile_7_canon();
 
 /* Methods */
 public:
  void METH_wrE(tUInt8 ARG_wrE_rIdx, tUInt32 ARG_wrE_data);
  tUInt8 METH_RDY_wrE();
  void METH_wrM(tUInt8 ARG_wrM_rIdx, tUInt32 ARG_wrM_data);
  tUInt8 METH_RDY_wrM();
  tUInt32 METH_rdA(tUInt8 ARG_rdA_rIdx);
  tUInt8 METH_RDY_rdA();
  tUInt32 METH_rdB(tUInt8 ARG_rdB_rIdx);
  tUInt8 METH_RDY_rdB();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBypassRFile &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBypassRFile &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBypassRFile &backing);
};

#endif /* ifndef __mkBypassRFile_h__ */
