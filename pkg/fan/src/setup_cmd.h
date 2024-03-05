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
         ReadLibCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReadLibCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class ReadNlCmd : public CommonNs::Cmd {
public:
         ReadNlCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReadNlCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class SetFaultTypeCmd : public CommonNs::Cmd {
public:
         SetFaultTypeCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~SetFaultTypeCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class ReportNetlistCmd : public CommonNs::Cmd {
public:
         ReportNetlistCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~ReportNetlistCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};

class BuildCircuitCmd : public CommonNs::Cmd {
public:
         BuildCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B);
         ~BuildCircuitCmd();

    bool exec(const std::vector<std::string> &argv);

private:
    FanMgr *fanMgr_A_;
    FanMgr *fanMgr_B_;
};



};

#endif