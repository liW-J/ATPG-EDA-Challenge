// **************************************************************************
// File       [ setup_cmd.h ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/08/30 created ]
// **************************************************************************

#ifndef _FAN_SETUP_CMD_H_
#define _FAN_SETUP_CMD_H_

#include "common/cmd.h"

#include "fan_mgr.h"

namespace FanNs {

// SETUP commands
class ReadLibCmd : public CommonNs::Cmd {
public:
         ReadLibCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C);
         ~ReadLibCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
};

class ReadNlCmd : public CommonNs::Cmd {
public:
         ReadNlCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C);
         ~ReadNlCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
};

class SetFaultTypeCmd : public CommonNs::Cmd {
public:
         SetFaultTypeCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C);
         ~SetFaultTypeCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
};

class ReportNetlistCmd : public CommonNs::Cmd {
public:
         ReportNetlistCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C);
         ~ReportNetlistCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
};

class BuildCircuitCmd : public CommonNs::Cmd {
public:
         BuildCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C);
         ~BuildCircuitCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
};



};

#endif