// **************************************************************************
// File       [ setup_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/08/30 created ]
// **************************************************************************

#include "interface/netlist_builder.h"
#include "interface/techlib_builder.h"

#include "setup_cmd.h"

using namespace CommonNs;
using namespace IntfNs;
using namespace CoreNs;
using namespace FanNs;

ReadLibCmd::ReadLibCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("read mentor technology library");
	optMgr_.setDes("read mentor technology library");
	optMgr_.regArg(new Arg(Arg::REQ, "mentor technology library file",
												 "lib_file"));
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "verbose on. Default is off", "");
	opt->addFlag("v");
	opt->addFlag("verbose");
	optMgr_.regOpt(opt);
}

ReadLibCmd::~ReadLibCmd() {}

bool ReadLibCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadLibCmd::exec(): library file needed";
		std::cerr << "\n";
		return false;
	}

	switch (cut_)
	{
	case 6:exec_once(fanMgr_F_);
	case 5:exec_once(fanMgr_E_);
	case 4:exec_once(fanMgr_D_);
	case 3:exec_once(fanMgr_C_);
	case 2:exec_once(fanMgr_B_);
	case 1:exec_once(fanMgr_A_);
	default:break;
	}

	return true;
}

bool ReadLibCmd::exec_once(FanMgr *fanMgr)
{
	fanMgr_ = fanMgr;
	delete fanMgr_->lib;
	fanMgr_->lib = new Techlib;
	MdtFile *libBlder = new MdtLibBuilder(fanMgr_->lib);

	// read library
	fanMgr_->tmusg.periodStart();
	std::cout << "#  Reading technology library ..."<< "\n";

	bool verbose = optMgr_.isFlagSet("v");

	if (!libBlder->read(optMgr_.getParsedArg(0).c_str(), verbose))
	{
		std::cerr << "**ERROR ReadLibCmd::exec(): MDT lib builder error"
							<< "\n";
		delete libBlder;
		delete fanMgr_->lib;
		libBlder = NULL;
		fanMgr_->lib = NULL;
		return false;
	}

	// check library
	if (!fanMgr_->lib->check(verbose))
	{
		std::cerr << "**ERROR ReadLibCmd::exec(): MDT lib error"
							<< "\n";
		delete libBlder;
		delete fanMgr_->lib;
		libBlder = NULL;
		fanMgr_->lib = NULL;
		return false;
	}

	TmStat stat;
	if (!fanMgr_->tmusg.getPeriodUsage(stat))
	{
		std::cout << "fishy ...\n";
	}
	std::cout << "#  Finished reading library `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";

	delete libBlder;
	libBlder = NULL;
	return true;
}

ReadNlCmd::ReadNlCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("read verilog gate level netlist");
	optMgr_.setDes("read verilog gate level netlist");
	optMgr_.regArg(new Arg(Arg::REQ, "verilog gate level netlist file",
												 "netlist_file"));
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "verbose on. Default is off", "");
	opt->addFlag("v");
	opt->addFlag("verbose");
	optMgr_.regOpt(opt);
}
ReadNlCmd::~ReadNlCmd() {}

bool ReadNlCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}


	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadNlCmd::exec(): netlist file needed";
		std::cerr << "\n";
		return false;
	}

	switch (cut_)
	{
	case 6:exec_once(fanMgr_F_);
	case 5:exec_once(fanMgr_E_);
	case 4:exec_once(fanMgr_D_);
	case 3:exec_once(fanMgr_C_);
	case 2:exec_once(fanMgr_B_);
	case 1:exec_once(fanMgr_A_);
	default:break;
	}

	return true;
}

bool ReadNlCmd::exec_once(FanMgr *fanMgr)
{
	fanMgr_ = fanMgr;
	if (!fanMgr_->lib)
	{
		std::cerr << "**ERROR ReadNlCmd::exec(): technology library needed";
		std::cerr << "\n";
		return false;
	}

	// create netlist and netlist builder
	delete fanMgr_->nl;
	fanMgr_->nl = new Netlist;
	fanMgr_->nl->setTechlib(fanMgr_->lib);
	VlogFile *nlBlder = new VlogNlBuilder(fanMgr_->nl);

	// read netlist
	fanMgr_->tmusg.periodStart();
	std::cout << "#  Reading netlist ..."
						<< "\n";
	bool verbose = optMgr_.isFlagSet("v");
	if (!nlBlder->read(optMgr_.getParsedArg(0).c_str(), verbose))
	{
		std::cerr << "**ERROR ReadNlCmd()::exec(): verilog builder error"
							<< "\n";
		delete fanMgr_->nl;
		delete nlBlder;
		fanMgr_->nl = NULL;
		nlBlder = NULL;
		return false;
	}

	// check netlist
	if (!fanMgr_->nl->check(verbose))
	{
		std::cerr << "**ERROR ReadNlCmd()::exec(): netlist error"
							<< "\n";
		delete fanMgr_->nl;
		delete nlBlder;
		fanMgr_->nl = NULL;
		nlBlder = NULL;
		return false;
	}

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished reading netlist `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB"
						<< "\n";

	delete nlBlder;
	nlBlder = NULL;
	return true;
}

SetFaultTypeCmd::SetFaultTypeCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	optMgr_.setName(name);
	optMgr_.setShortDes("set fault type");
	optMgr_.setDes("set fault type. Currently supports stuck-at fault and transition delay fault");
	optMgr_.regArg(new Arg(Arg::REQ, "either saf or tdf",
												 "fault_type"));
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
SetFaultTypeCmd::~SetFaultTypeCmd() {}

bool SetFaultTypeCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR SetFaultTypeCmd::exec(): fault type needed";
		std::cerr << "\n";
		return false;
	}

	exec_once(fanMgr_A_);
	exec_once(fanMgr_B_);
	exec_once(fanMgr_C_);
	exec_once(fanMgr_D_);
	exec_once(fanMgr_E_);
	exec_once(fanMgr_F_);

	return true;
}

bool SetFaultTypeCmd::exec_once(FanMgr *fanMgr){
	fanMgr_ = fanMgr;
	
	if (!fanMgr_->fListExtract)
	{
		fanMgr_->fListExtract = new FaultListExtract;
	}

	if (optMgr_.getParsedArg(0) == "saf")
	{
		std::cout << "#  fault type set to stuck-at fault"
							<< "\n";
		fanMgr_->fListExtract->faultListType_ = FaultListExtract::SAF;
	}
	else if (optMgr_.getParsedArg(0) == "tdf")
	{
		std::cout << "#  fault type set to transition delay fault"
							<< "\n";
		fanMgr_->fListExtract->faultListType_ = FaultListExtract::TDF;
	}
	else
	{
		std::cerr << "**ERROR SetFaultTypeCmd::exec(): unknown fault type `";
		std::cerr << optMgr_.getParsedArg(0) << "'"
							<< "\n";
		return false;
	}

	return true;

}

ReportNetlistCmd::ReportNetlistCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	optMgr_.setName(name);
	optMgr_.setShortDes("report netlist");
	optMgr_.setDes("report netlist information");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "print more detailed information", "");
	opt->addFlag("more");
	optMgr_.regOpt(opt);
}
ReportNetlistCmd::~ReportNetlistCmd() {}

bool ReportNetlistCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	exec_once(fanMgr_E_);

	return true;
}

bool ReportNetlistCmd::exec_once(FanMgr *fanMgr)
{
	fanMgr_ = fanMgr;
	if (!fanMgr_->nl)
	{
		std::cerr << "**ERROR ReportNetlistCmd::exec(): netlist needed"
							<< "\n";
		return false;
	}

	std::cout << "#  netlist information"
						<< "\n";
	std::cout << "#    number of modules: " << fanMgr_->nl->getNModule() << "\n";
	std::cout << "#    modules:          ";
	for (size_t i = 0; i < fanMgr_->nl->getNModule(); ++i)
	{
		std::cout << " " << fanMgr_->nl->getModule(i)->name_;
	}
	std::cout << "\n";
	Cell *top = fanMgr_->nl->getTop();
	std::cout << "#    current module:    " << top->name_ << "\n";
	std::cout << "#    number of ports:   " << top->getNPort() << "\n";
	std::cout << "#    number of cells:   " << top->getNCell() << "\n";
	std::cout << "#    number of nets:    " << top->getNNet() << "\n";
	if (!optMgr_.isFlagSet("more"))
	{
		return true;
	}
	std::cout << "#    ports:            ";
	for (size_t i = 0; i < top->getNPort(); ++i)
	{
		std::cout << " " << top->getPort(i)->name_;
	}
	std::cout << "\n";
	std::cout << "#    cells:            ";
	for (size_t i = 0; i < top->getNCell(); ++i)
	{
		std::cout << " " << top->getCell(i)->name_;
	}
	std::cout << "\n";
	std::cout << "#    nets:             ";
	for (size_t i = 0; i < top->getNNet(); ++i)
	{
		std::cout << " " << top->getNet(i)->name_;
	}
	std::cout << "\n";

	return true;
}

BuildCircuitCmd::BuildCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("build circuit");
	optMgr_.setDes("build netlist into internal circuit data structure");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "number of frames", "NUM");
	opt->addFlag("f");
	opt->addFlag("frame");
	optMgr_.regOpt(opt);
}

BuildCircuitCmd::~BuildCircuitCmd() {}

bool BuildCircuitCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	switch (cut_)
	{
	case 6:exec_once(fanMgr_F_);
	case 5:exec_once(fanMgr_E_);
	case 4:exec_once(fanMgr_D_);
	case 3:exec_once(fanMgr_C_);
	case 2:exec_once(fanMgr_B_);
	case 1:exec_once(fanMgr_A_);
	default:break;
	}

	return true;
}

bool BuildCircuitCmd::exec_once(FanMgr *fanMgr)
{
	fanMgr_ = fanMgr;

	if (!fanMgr_->nl)
	{
		std::cerr << "**ERROR BuildCirucitCmd::exec(): netlist needed"
							<< "\n";
		return false;
	}

	int nframe = 1;
	if (optMgr_.isFlagSet("f"))
	{
		nframe = atoi(optMgr_.getFlagVar("f").c_str());
		nframe = nframe < 1 ? 1 : nframe;
	}

	fanMgr_->cir = new Circuit;
	// build circuit
	fanMgr_->tmusg.periodStart();
	std::cout << "#  Building circuit ..."
						<< "\n";
	if (fanMgr_->pcoll && fanMgr_->pcoll->type_ == PatternProcessor::LAUNCH_SHIFT) // launch on shift pattern
	{
		fanMgr_->cir->buildCircuit(fanMgr_->nl, nframe, Circuit::SHIFT);
	}
	else
	{
		fanMgr_->cir->buildCircuit(fanMgr_->nl, nframe);
	}

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished building circuit";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB"
						<< "\n";

	return true;
}