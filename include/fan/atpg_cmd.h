// **************************************************************************
// File       [ atpg_cmd.h ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/09/28 created ]
// **************************************************************************

#ifndef _FAN_ATPG_CMD_H_
#define _FAN_ATPG_CMD_H_

#include "common/cmd.h"

#include "fan_mgr.h"

namespace FanNs {

// ATPG commands
class ReadPatCmd : public CommonNs::Cmd {
public:
         ReadPatCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut);
         ~ReadPatCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
    int cut_;
};

class AddFaultCmd : public CommonNs::Cmd {
public:
         AddFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut);
         ~AddFaultCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    void   addAllFault();
    bool exec_once(FanMgr *fanMgr, int fanMgrTYPE, int cut);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
    int cut_;
};

class ReportFaultCmd : public CommonNs::Cmd {
public:
         ReportFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X); 
         ~ReportFaultCmd();
         

    bool exec(const std::vector<std::string> &argv);

private:
    void   ShowFaultList(FanMgr *fanMgr, bool stateSet,  CoreNs::Fault::FAULT_STATE state);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
};

class ReportCircuitCmd : public CommonNs::Cmd {
public:
         ReportCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X);
         ~ReportCircuitCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
};

class ReportStatsCmd : public CommonNs::Cmd {
public:
         ReportStatsCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X);
         ~ReportStatsCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr, int &numCollapsedFaults, int &fu, int &ud, int &dt, int &pt, int &au, int &ti, int &re, int &ab );
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
};

class RunFaultSimCmd : public CommonNs::Cmd {
public:
         RunFaultSimCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut);
         ~RunFaultSimCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool pre_exec(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_G_;
    FanMgr *fanMgr_H_;
    FanMgr *fanMgr_I_;
    FanMgr *fanMgr_J_;
    FanMgr *fanMgr_K_;
    FanMgr *fanMgr_L_;
    FanMgr *fanMgr_M_;
    FanMgr *fanMgr_N_;
    FanMgr *fanMgr_O_;
    FanMgr *fanMgr_P_;
    FanMgr *fanMgr_Q_;
    FanMgr *fanMgr_R_;
    FanMgr *fanMgr_S_;
    FanMgr *fanMgr_T_;
    FanMgr *fanMgr_U_;
    FanMgr *fanMgr_V_;
    FanMgr *fanMgr_W_;
    FanMgr *fanMgr_X_;
    FanMgr *fanMgr_;
    int cut_;
};
};

#endif