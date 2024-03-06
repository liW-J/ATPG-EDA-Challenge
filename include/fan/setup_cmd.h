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
         ReadLibCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F);
         ~ReadLibCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_;
};

class ReadNlCmd : public CommonNs::Cmd {
public:
         ReadNlCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F);
         ~ReadNlCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_;
};

class SetFaultTypeCmd : public CommonNs::Cmd {
public:
         SetFaultTypeCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F);
         ~SetFaultTypeCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_;
};

class ReportNetlistCmd : public CommonNs::Cmd {
public:
         ReportNetlistCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F);
         ~ReportNetlistCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_;
};

class BuildCircuitCmd : public CommonNs::Cmd {
public:
         BuildCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F);
         ~BuildCircuitCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    bool exec_once(FanMgr *fanMgr);
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
    FanMgr *fanMgr_C_;
    FanMgr *fanMgr_D_;
    FanMgr *fanMgr_E_;
    FanMgr *fanMgr_F_;
    FanMgr *fanMgr_;
};



};

#endif