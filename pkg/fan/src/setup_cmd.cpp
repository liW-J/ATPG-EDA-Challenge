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

ReadLibCmd::ReadLibCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
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

	// create library and library builder
	delete fanMgr_A_->lib;	delete fanMgr_B_->lib;	delete fanMgr_C_->lib;	delete fanMgr_D_->lib;
	fanMgr_A_->lib = new Techlib;  fanMgr_B_->lib = new Techlib;  fanMgr_C_->lib = new Techlib;  fanMgr_D_->lib = new Techlib;
	MdtFile *libBlder_A = new MdtLibBuilder(fanMgr_A_->lib);
	MdtFile *libBlder_B = new MdtLibBuilder(fanMgr_B_->lib);
	MdtFile *libBlder_C = new MdtLibBuilder(fanMgr_C_->lib);
	MdtFile *libBlder_D = new MdtLibBuilder(fanMgr_D_->lib);
	// read library
	fanMgr_A_->tmusg.periodStart();
	fanMgr_B_->tmusg.periodStart();
	fanMgr_C_->tmusg.periodStart();
	fanMgr_D_->tmusg.periodStart();
	std::cout << "#  Reading technology library ..."
						<< "\n";
	bool verbose = optMgr_.isFlagSet("v");
	if (!libBlder_A->read(optMgr_.getParsedArg(0).c_str(), verbose) || !libBlder_B->read(optMgr_.getParsedArg(0).c_str(), verbose) || !libBlder_C->read(optMgr_.getParsedArg(0).c_str(), verbose) || !libBlder_D->read(optMgr_.getParsedArg(0).c_str(), verbose))
	{
		std::cerr << "**ERROR ReadLibCmd::exec(): MDT lib builder error"
							<< "\n";
		delete libBlder_A;  delete libBlder_B;  delete libBlder_C;  delete libBlder_D;
		delete fanMgr_A_->lib;  delete fanMgr_B_->lib;  delete fanMgr_C_->lib;  delete fanMgr_D_->lib;
		libBlder_A = NULL;  libBlder_B = NULL;  libBlder_C = NULL;  libBlder_D = NULL;
		fanMgr_A_->lib = NULL;  fanMgr_B_->lib = NULL;  fanMgr_C_->lib = NULL;  fanMgr_D_->lib = NULL;
		return false;
	}

	// check library
	if (!fanMgr_A_->lib->check(verbose) || !fanMgr_B_->lib->check(verbose) || !fanMgr_C_->lib->check(verbose) || !fanMgr_D_->lib->check(verbose))
	{
		std::cerr << "**ERROR ReadLibCmd::exec(): MDT lib error"
							<< "\n";
		delete libBlder_A;  delete libBlder_B;  delete libBlder_C;  delete libBlder_D;
		delete fanMgr_A_->lib;  delete fanMgr_B_->lib;  delete fanMgr_C_->lib; delete fanMgr_D_->lib;
		libBlder_A = NULL;  libBlder_B = NULL;  libBlder_C = NULL;  libBlder_D = NULL;
		fanMgr_A_->lib = NULL;  fanMgr_B_->lib = NULL;  fanMgr_C_->lib = NULL;  fanMgr_D_->lib = NULL;
		return false;
	}

	// TODO:B
	TmStat stat_A, stat_B, stat_C, stat_D;
	if (!fanMgr_A_->tmusg.getPeriodUsage(stat_A) || !fanMgr_B_->tmusg.getPeriodUsage(stat_B) || !fanMgr_C_->tmusg.getPeriodUsage(stat_C) || !fanMgr_D_->tmusg.getPeriodUsage(stat_D))
	{
		std::cout << "fishy ...\n";
	}
	std::cout << "#  Finished reading library `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat_A.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat_A.vmSize / 1024.0 << " MB\n";

	delete libBlder_A;  delete libBlder_B;  delete libBlder_C;  delete libBlder_D;  
	libBlder_A = NULL;  libBlder_B = NULL;  libBlder_C = NULL;  libBlder_D = NULL;
	return true;
}

ReadNlCmd::ReadNlCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
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

	if (!fanMgr_A_->lib || !fanMgr_B_->lib || !fanMgr_C_->lib || !fanMgr_D_->lib)
	{
		std::cerr << "**ERROR ReadNlCmd::exec(): technology library needed";
		std::cerr << "\n";
		return false;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadNlCmd::exec(): netlist file needed";
		std::cerr << "\n";
		return false;
	}

	// create netlist and netlist builder
	delete fanMgr_A_->nl;  delete fanMgr_B_->nl;  delete fanMgr_C_->nl;  delete fanMgr_D_->nl;
	fanMgr_A_->nl = new Netlist;  fanMgr_B_->nl = new Netlist;  fanMgr_C_->nl = new Netlist;  fanMgr_D_->nl = new Netlist;
	fanMgr_A_->nl->setTechlib(fanMgr_A_->lib);  fanMgr_B_->nl->setTechlib(fanMgr_B_->lib);  fanMgr_C_->nl->setTechlib(fanMgr_C_->lib);  fanMgr_D_->nl->setTechlib(fanMgr_D_->lib);
	VlogFile *nlBlder_A = new VlogNlBuilder(fanMgr_A_->nl);
	VlogFile *nlBlder_B = new VlogNlBuilder(fanMgr_B_->nl);
	VlogFile *nlBlder_C = new VlogNlBuilder(fanMgr_C_->nl);
	VlogFile *nlBlder_D = new VlogNlBuilder(fanMgr_D_->nl);
	// read netlist
	fanMgr_A_->tmusg.periodStart();  fanMgr_B_->tmusg.periodStart();  fanMgr_C_->tmusg.periodStart(); fanMgr_D_->tmusg.periodStart();
	std::cout << "#  Reading netlist ..."
						<< "\n";
	bool verbose = optMgr_.isFlagSet("v");
	if (!nlBlder_A->read(optMgr_.getParsedArg(0).c_str(), verbose) || !nlBlder_B->read(optMgr_.getParsedArg(0).c_str(), verbose) || !nlBlder_C->read(optMgr_.getParsedArg(0).c_str(), verbose) || !nlBlder_D->read(optMgr_.getParsedArg(0).c_str(), verbose))
	{
		std::cerr << "**ERROR ReadNlCmd()::exec(): verilog builder error"
							<< "\n";
		delete fanMgr_A_->nl;  delete fanMgr_B_->nl;  delete fanMgr_C_->nl;  delete fanMgr_D_->nl;
		delete nlBlder_A;  delete nlBlder_B;  delete nlBlder_C;  delete nlBlder_D;
		fanMgr_A_->nl = NULL;  fanMgr_B_->nl = NULL;  fanMgr_C_->nl = NULL; fanMgr_D_->nl = NULL;
		nlBlder_A = NULL;  nlBlder_B = NULL;  nlBlder_C = NULL;  nlBlder_D = NULL; 
		return false;
	}

	// check netlist
	if (!fanMgr_A_->nl->check(verbose) || !fanMgr_B_->nl->check(verbose) || !fanMgr_C_->nl->check(verbose) || !fanMgr_D_->nl->check(verbose))
	{
		std::cerr << "**ERROR ReadNlCmd()::exec(): netlist error"
							<< "\n";
		delete fanMgr_A_->nl;  delete fanMgr_B_->nl;  delete fanMgr_C_->nl;  delete fanMgr_D_->nl;
		delete nlBlder_A;  delete nlBlder_B;    delete nlBlder_C;  delete nlBlder_D;  
		fanMgr_A_->nl = NULL;  fanMgr_B_->nl = NULL;  fanMgr_C_->nl = NULL;  fanMgr_D_->nl = NULL;
		nlBlder_A = NULL;  nlBlder_B = NULL;  nlBlder_C = NULL;  nlBlder_D = NULL;
		return false;
	}

	TmStat stat;
	fanMgr_A_->tmusg.getPeriodUsage(stat);
	fanMgr_B_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished reading netlist `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB"
						<< "\n";

	delete nlBlder_A;  delete nlBlder_B;  delete nlBlder_C;
	nlBlder_A = NULL;  nlBlder_B = NULL;  nlBlder_C = NULL;
	return true;
}

SetFaultTypeCmd::SetFaultTypeCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
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

	// TODO:B
	if (!fanMgr_A_->fListExtract || !fanMgr_B_->fListExtract || !fanMgr_C_->fListExtract || !fanMgr_D_->fListExtract)
	{
		fanMgr_A_->fListExtract = new FaultListExtract;
		fanMgr_B_->fListExtract = new FaultListExtract;
		fanMgr_C_->fListExtract = new FaultListExtract;
		fanMgr_D_->fListExtract = new FaultListExtract;
	}

	if (optMgr_.getParsedArg(0) == "saf")
	{
		std::cout << "#  fault type set to stuck-at fault"
							<< "\n";
		fanMgr_A_->fListExtract->faultListType_ = FaultListExtract::SAF;
		fanMgr_B_->fListExtract->faultListType_ = FaultListExtract::SAF;
		fanMgr_C_->fListExtract->faultListType_ = FaultListExtract::SAF;
		fanMgr_D_->fListExtract->faultListType_ = FaultListExtract::SAF;
	}
	else if (optMgr_.getParsedArg(0) == "tdf")
	{
		std::cout << "#  fault type set to transition delay fault"
							<< "\n";
		fanMgr_A_->fListExtract->faultListType_ = FaultListExtract::TDF;
		fanMgr_B_->fListExtract->faultListType_ = FaultListExtract::TDF;
		fanMgr_C_->fListExtract->faultListType_ = FaultListExtract::TDF;
		fanMgr_D_->fListExtract->faultListType_ = FaultListExtract::TDF;
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

ReportNetlistCmd::ReportNetlistCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
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

	if (!fanMgr_A_->nl || !fanMgr_B_->nl || !fanMgr_C_->nl || !fanMgr_D_->nl)
	{
		std::cerr << "**ERROR ReportNetlistCmd::exec(): netlist needed"
							<< "\n";
		return false;
	}

	// TODO:B
	std::cout << "#  netlist information"
						<< "\n";
	std::cout << "#    number of modules: " << fanMgr_B_->nl->getNModule() << "\n";
	std::cout << "#    modules:          ";
	for (size_t i = 0; i < fanMgr_B_->nl->getNModule(); ++i)
	{
		std::cout << " " << fanMgr_B_->nl->getModule(i)->name_;
	}
	std::cout << "\n";
	Cell *top = fanMgr_B_->nl->getTop();
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

BuildCircuitCmd::BuildCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
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

	// TODO:B
	if (!fanMgr_A_->nl || !fanMgr_B_->nl || !fanMgr_C_->nl || !fanMgr_D_->nl)
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

	fanMgr_A_->cir = new Circuit;
	fanMgr_B_->cir = new Circuit;
	fanMgr_C_->cir = new Circuit;
	fanMgr_D_->cir = new Circuit;
	// build circuit
	fanMgr_A_->tmusg.periodStart();
	fanMgr_B_->tmusg.periodStart();
	fanMgr_C_->tmusg.periodStart();
	fanMgr_D_->tmusg.periodStart();
	std::cout << "#  Building circuit ..."
						<< "\n";
	if (fanMgr_A_->pcoll && fanMgr_A_->pcoll->type_ == PatternProcessor::LAUNCH_SHIFT \
	&& fanMgr_B_->pcoll && fanMgr_B_->pcoll->type_ == PatternProcessor::LAUNCH_SHIFT \
	&& fanMgr_C_->pcoll && fanMgr_C_->pcoll->type_ == PatternProcessor::LAUNCH_SHIFT \
	&& fanMgr_D_->pcoll && fanMgr_D_->pcoll->type_ == PatternProcessor::LAUNCH_SHIFT) // launch on shift pattern
	{
		fanMgr_A_->cir->buildCircuit(fanMgr_A_->nl, nframe, Circuit::SHIFT);
		fanMgr_B_->cir->buildCircuit(fanMgr_B_->nl, nframe, Circuit::SHIFT);
		fanMgr_C_->cir->buildCircuit(fanMgr_C_->nl, nframe, Circuit::SHIFT);
		fanMgr_D_->cir->buildCircuit(fanMgr_D_->nl, nframe, Circuit::SHIFT);
	}
	else
	{
		fanMgr_A_->cir->buildCircuit(fanMgr_A_->nl, nframe);
		fanMgr_B_->cir->buildCircuit(fanMgr_B_->nl, nframe);
		fanMgr_C_->cir->buildCircuit(fanMgr_C_->nl, nframe);
		fanMgr_D_->cir->buildCircuit(fanMgr_D_->nl, nframe);
	}

	TmStat stat_A, stat_B;
	fanMgr_A_->tmusg.getPeriodUsage(stat_A);
	fanMgr_B_->tmusg.getPeriodUsage(stat_B);
	std::cout << "#  Finished building circuit";
	std::cout << "    " << (double)stat_A.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat_A.vmSize / 1024.0 << " MB"
						<< "\n";

	return true;
}