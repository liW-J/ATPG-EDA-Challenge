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
         ReadPatCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReadPatCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};


class AddFaultCmd : public CommonNs::Cmd {
public:
         AddFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~AddFaultCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    void   addAllFault();
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class ReportFaultCmd : public CommonNs::Cmd {
public:
         ReportFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReportFaultCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    void   ShowFaultList(FanMgr *fanMgr, bool stateSet,  CoreNs::Fault::FAULT_STATE state);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_;
};

class ReportCircuitCmd : public CommonNs::Cmd {
public:
         ReportCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReportCircuitCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class ReportGateCmd : public CommonNs::Cmd {
public:
         ReportGateCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReportGateCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    void   reportGate(const int &i) const;
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class RunFaultSimCmd : public CommonNs::Cmd {
public:
         RunFaultSimCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~RunFaultSimCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};


};

#endif