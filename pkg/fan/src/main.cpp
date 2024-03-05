// **************************************************************************
// File       [ main.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/07/05 created ]
// **************************************************************************

#include <cstdlib>

#include "common/sys_cmd.h"
#include "setup_cmd.h"
#include "atpg_cmd.h"
#include "misc_cmd.h"

using namespace CommonNs;
using namespace IntfNs;
using namespace CoreNs;
using namespace FanNs;

void printWelcome();
void initOpt(OptMgr &mgr);
void initCmd(CmdMgr &cmdMgr, FanMgr &fanMgr_A, FanMgr &fanMgr_B, FanMgr &fanMgr_C);
void printGoodbye(TmUsage &tmusg);

int main(int argc, char **argv)
{

	// start calculating resource usage
	TmUsage tmusg;
	tmusg.totalStart();

	// initialize option manager
	OptMgr optMgr;
	initOpt(optMgr);

	optMgr.parse(argc, argv);
	if (optMgr.isFlagSet("h"))
	{
		optMgr.usage();
		exit(0);
	}

	// initialize command manager and FAN manager
	FanMgr fanMgr_A;
	FanMgr fanMgr_B;
	FanMgr fanMgr_C;
	CmdMgr cmdMgr;
	initCmd(cmdMgr, fanMgr_A, fanMgr_B, fanMgr_C);
	CmdMgr::Result res = CmdMgr::SUCCESS;

	// welcome message
	printWelcome();

	// run startup commands
	if (optMgr.isFlagSet("f"))
	{
		std::string cmd = "source " + optMgr.getFlagVar("f");
		res = cmdMgr.exec(cmd);
	}

	// enter user interface
	while (res != CmdMgr::EXIT)
	{
		res = cmdMgr.read();
		if (res == CmdMgr::NOT_EXIST)
		{
			std::cerr << "**ERROR main(): command `" << cmdMgr.getErrorStr();
			std::cerr << "' not found" << "\n";
			continue;
		}
	}

	// goodbye
	printGoodbye(tmusg);
	return 0;
}

void printWelcome()
{
	std::cout << "#  ==========================================================================" << "\n";
	std::cout << "#" << "\n";
	std::cout << "#                                   FAN ATPG" << "\n";
	std::cout << "#" << "\n";
	std::cout << "#                Copyright(c) Laboratory of Dependable Systems," << "\n";
	std::cout << "#                Graduate Institute of Electronics Engineering," << "\n";
	std::cout << "#                          National Taiwan University" << "\n";
	std::cout << "#                             All Rights Reserved." << "\n";
	std::cout << "#" << "\n";
	std::cout << "#  ==========================================================================" << "\n";
	std::cout << "#" << "\n";

	// system information
	// OS kernel
	FILE *systemOutput;
	systemOutput = popen("uname -s 2> /dev/null", "r");
	char buf[128];
	std::cout << "#  Kernel:   ";
	if (!systemOutput)
		std::cout << "UNKNOWN" << "\n";
	else
	{
		if (fgets(buf, sizeof(buf), systemOutput))
			std::cout << buf;
		else
			std::cout << "UNKNOWN" << "\n";
		pclose(systemOutput);
	}

	// platform
	systemOutput = popen("uname -i 2> /dev/null", "r");
	std::cout << "#  Platform: ";
	if (!systemOutput)
		std::cout << "UNKNOWN" << "\n";
	else
	{
		if (fgets(buf, sizeof(buf), systemOutput))
			std::cout << buf;
		else
			std::cout << "UNKNOWN" << "\n";
		pclose(systemOutput);
	}

	// memory
	FILE *meminfo = fopen("/proc/meminfo", "r");
	std::cout << "#  Memory:   ";
	if (!meminfo)
		std::cout << "UNKNOWN" << "\n";
	else
	{
		while (fgets(buf, 128, meminfo))
		{
			char *ch;
			if ((ch = strstr(buf, "MemTotal:")))
			{
				std::cout << (double)atol(ch + 9) / 1024.0 << " MB" << "\n";
				break;
			}
		}
		fclose(meminfo);
	}

	std::cout << "#" << "\n";
}

void printGoodbye(TmUsage &tmusg)
{
	TmStat stat;
	tmusg.getTotalUsage(stat);
	std::cout << "#  Goodbye" << "\n";
	std::cout << "#  Runtime        ";
	std::cout << "real " << (double)stat.rTime / 1000000.0 << " s        ";
	std::cout << "user " << (double)stat.uTime / 1000000.0 << " s        ";
	std::cout << "sys " << (double)stat.sTime / 1000000.0 << " s" << "\n";
	std::cout << "#  Memory         ";
	std::cout << "peak " << (double)stat.vmPeak / 1024.0 << " MB" << "\n";
}

void initOpt(OptMgr &mgr)
{
	// set program information
	mgr.setName("fan");
	mgr.setShortDes("FAN based ATPG");
	mgr.setDes("FAN based ATPG");

	// register options
	Opt *opt = new Opt(Opt::BOOL, "print this usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	mgr.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "execute command file at startup", "file");
	opt->addFlag("f");
	mgr.regOpt(opt);
}

void initCmd(CmdMgr &cmdMgr, FanMgr &fanMgr_A, FanMgr &fanMgr_B, FanMgr &fanMgr_C)
{
	// system commands
	Cmd *listCmd = new SysListCmd("ls");
	Cmd *cdCmd = new SysCdCmd("cd");
	Cmd *catCmd = new SysCatCmd("cat");
	Cmd *pwdCmd = new SysPwdCmd("pwd");
	Cmd *setCmd = new SysSetCmd("set", &cmdMgr);
	Cmd *exitCmd = new SysExitCmd("exit", &cmdMgr);
	Cmd *quitCmd = new SysExitCmd("quit", &cmdMgr);
	Cmd *sourceCmd = new SysSourceCmd("source", &cmdMgr);
	Cmd *helpCmd = new SysHelpCmd("help", &cmdMgr);
	cmdMgr.regCmd("SYSTEM", listCmd);
	cmdMgr.regCmd("SYSTEM", cdCmd);
	cmdMgr.regCmd("SYSTEM", catCmd);
	cmdMgr.regCmd("SYSTEM", pwdCmd);
	cmdMgr.regCmd("SYSTEM", setCmd);
	cmdMgr.regCmd("SYSTEM", exitCmd);
	cmdMgr.regCmd("SYSTEM", quitCmd);
	cmdMgr.regCmd("SYSTEM", sourceCmd);
	cmdMgr.regCmd("SYSTEM", helpCmd);

	// setup commands
	Cmd *readLibCmd = new ReadLibCmd("read_lib", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *readNlCmd = new ReadNlCmd("read_netlist", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *setFaultTypeCmd = new SetFaultTypeCmd("set_fault_type", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *buildCirCmd = new BuildCircuitCmd("build_circuit", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *reportNlCmd = new ReportNetlistCmd("report_netlist", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	cmdMgr.regCmd("SETUP", readLibCmd);
	cmdMgr.regCmd("SETUP", readNlCmd);
	cmdMgr.regCmd("SETUP", setFaultTypeCmd);
	cmdMgr.regCmd("SETUP", buildCirCmd);
	cmdMgr.regCmd("SETUP", reportNlCmd);

	// ATPG commands
	Cmd *readPatCmd = new ReadPatCmd("read_pattern", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *addFaultCmd = new AddFaultCmd("add_fault", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *reportFaultCmd = new ReportFaultCmd("report_fault", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *runFaultSimCmd = new RunFaultSimCmd("run_fault_sim", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	Cmd *reportCircuitCmd = new ReportCircuitCmd("report_circuit", &fanMgr_A, &fanMgr_B, &fanMgr_C);
	cmdMgr.regCmd("ATPG", readPatCmd);
	cmdMgr.regCmd("ATPG", addFaultCmd);
	cmdMgr.regCmd("ATPG", reportFaultCmd);
	cmdMgr.regCmd("ATPG", runFaultSimCmd);
	cmdMgr.regCmd("ATPG", reportCircuitCmd);


	// misc commands
	Cmd *reportPatFormatCmd = new ReportPatFormatCmd("report_pattern_format");
	Cmd *reportMemUsgCmd = new ReportMemUsgCmd("report_memory_usage");
	cmdMgr.regCmd("MISC", reportPatFormatCmd);
	cmdMgr.regCmd("MISC", reportMemUsgCmd);

	// user interface
	cmdMgr.setComment('#');
	cmdMgr.setPrompt("fan> ");
	cmdMgr.setColor(CmdMgr::YELLOW);
}
