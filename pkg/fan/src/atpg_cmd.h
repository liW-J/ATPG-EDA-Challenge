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
         ReadPatCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, int *cut);
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
    FanMgr *fanMgr_;
    int cut_;
};

class AddFaultCmd : public CommonNs::Cmd {
public:
         AddFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, int *cut);
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
    FanMgr *fanMgr_;
    int cut_;
};

class ReportFaultCmd : public CommonNs::Cmd {
public:
         ReportFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K); 
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
    FanMgr *fanMgr_;
};

class ReportCircuitCmd : public CommonNs::Cmd {
public:
         ReportCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K);
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
    FanMgr *fanMgr_;
};

class ReportStatsCmd : public CommonNs::Cmd {
public:
         ReportStatsCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K);
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
    FanMgr *fanMgr_;
};

class RunFaultSimCmd : public CommonNs::Cmd {
public:
         RunFaultSimCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, int *cut);
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
    FanMgr *fanMgr_;
    int cut_;
};
};

#endif