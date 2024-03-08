// **************************************************************************
// File       [ atpg_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/09/28 created ]
// **************************************************************************

#include <cstdlib>
#include <iomanip>
#include <fstream>
#include<thread>

#include "atpg_cmd.h"
#include "core/pattern_rw.h"
#include "core/simulator.h"

using namespace CommonNs;
using namespace IntfNs;
using namespace CoreNs;
using namespace FanNs;

double rtime;

ReadPatCmd::ReadPatCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	fanMgr_G_ = fanMgr_G;
	fanMgr_H_ = fanMgr_H;
	fanMgr_I_ = fanMgr_I;
	fanMgr_J_ = fanMgr_J;
	fanMgr_K_ = fanMgr_K;
	fanMgr_L_ = fanMgr_L;
	fanMgr_M_ = fanMgr_M;
	fanMgr_N_ = fanMgr_N;
	fanMgr_O_ = fanMgr_O;
	fanMgr_P_ = fanMgr_P;
	fanMgr_Q_ = fanMgr_Q;
	fanMgr_R_ = fanMgr_R;
	fanMgr_S_ = fanMgr_S;
	fanMgr_T_ = fanMgr_T;
	fanMgr_U_ = fanMgr_U;
	fanMgr_V_ = fanMgr_V;
	fanMgr_W_ = fanMgr_W;
	fanMgr_X_ = fanMgr_X;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("read patterns");
	optMgr_.setDes("read pattern form FILE");
	optMgr_.regArg(new Arg(Arg::REQ, "pattern file", "FILE"));
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "verbose on. Default is off", "");
	opt->addFlag("v");
	opt->addFlag("verbose");
	optMgr_.regOpt(opt);
}
ReadPatCmd::~ReadPatCmd() {}

bool ReadPatCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadPatCmd::exec(): pattern file needed\n";
		return false;
	}

	switch (cut_)
	{
	case 24:exec_once(fanMgr_X_);
	case 23:exec_once(fanMgr_W_);
	case 22:exec_once(fanMgr_V_);
	case 21:exec_once(fanMgr_U_);
	case 20:exec_once(fanMgr_T_);
	case 19:exec_once(fanMgr_S_);
	case 18:exec_once(fanMgr_R_);
	case 17:exec_once(fanMgr_Q_);
	case 16:exec_once(fanMgr_P_);
	case 15:exec_once(fanMgr_O_);
	case 14:exec_once(fanMgr_N_);
	case 13:exec_once(fanMgr_M_);
	case 12:exec_once(fanMgr_L_);
	case 11:exec_once(fanMgr_K_);
	case 10:exec_once(fanMgr_J_);
	case 9:exec_once(fanMgr_I_);
	case 8:exec_once(fanMgr_H_);
	case 7:exec_once(fanMgr_G_);
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

bool ReadPatCmd::exec_once(FanMgr *fanMgr)
{
	fanMgr_ = fanMgr;

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR ReadPatCmd::exec(): circuit needed\n";
		return false;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadPatCmd::exec(): pattern file needed\n";
		return false;
	}

	// create pattern and pattern builder
	delete fanMgr_->pcoll;
	fanMgr_->pcoll = new PatternProcessor;
	PatFile *patBlder = new PatternReader(fanMgr_->pcoll, fanMgr_->cir);

	// read pattern
	fanMgr_->tmusg.periodStart();
	std::cout << "#  Reading pattern ...\n";
	bool verbose = optMgr_.isFlagSet("v");
	if (!patBlder->read(optMgr_.getParsedArg(0).c_str(), verbose))
	{
		std::cerr << "**ERROR ReadPatCmd()::exec(): pattern builder error\n";
		delete fanMgr_->pcoll;
		delete patBlder;
		fanMgr_->pcoll = NULL;
		patBlder = NULL;
		return false;
	}

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished reading pattern `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";

	delete patBlder;
	patBlder = NULL;
	return true;
}

AddFaultCmd::AddFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	fanMgr_G_ = fanMgr_G;
	fanMgr_H_ = fanMgr_H;
	fanMgr_I_ = fanMgr_I;
	fanMgr_J_ = fanMgr_J;
	fanMgr_K_ = fanMgr_K;
	fanMgr_L_ = fanMgr_L;
	fanMgr_M_ = fanMgr_M;
	fanMgr_N_ = fanMgr_N;
	fanMgr_O_ = fanMgr_O;
	fanMgr_P_ = fanMgr_P;
	fanMgr_Q_ = fanMgr_Q;
	fanMgr_R_ = fanMgr_R;
	fanMgr_S_ = fanMgr_S;
	fanMgr_T_ = fanMgr_T;
	fanMgr_U_ = fanMgr_U;
	fanMgr_V_ = fanMgr_V;
	fanMgr_W_ = fanMgr_W;
	fanMgr_X_ = fanMgr_X;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("add faults");
	optMgr_.setDes("adds faults either by extract from circuit or from file");
	Arg *arg = new Arg(Arg::OPT, "fault type. Can be SA0, SA1, STR, STF", "TYPE");
	optMgr_.regArg(arg);
	arg = new Arg(Arg::OPT, "pin location. Hierarchy separated by '/'", "PIN");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "custom fault file", "FILE");
	opt->addFlag("f");
	opt->addFlag("file");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "add all faults", "");
	opt->addFlag("a");
	opt->addFlag("all");
	optMgr_.regOpt(opt);
}

AddFaultCmd::~AddFaultCmd() {}

bool AddFaultCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	switch (cut_)
	{
	case 24:exec_once(fanMgr_X_, 23, cut_);
	case 23:exec_once(fanMgr_W_, 22, cut_);
	case 22:exec_once(fanMgr_V_, 21, cut_);
	case 21:exec_once(fanMgr_U_, 20, cut_);
	case 20:exec_once(fanMgr_T_, 19, cut_);
	case 19:exec_once(fanMgr_S_, 18, cut_);
	case 18:exec_once(fanMgr_R_, 17, cut_);
	case 17:exec_once(fanMgr_Q_, 16, cut_);
	case 16:exec_once(fanMgr_P_, 15, cut_);
	case 15:exec_once(fanMgr_O_, 14, cut_);
	case 14:exec_once(fanMgr_N_, 13, cut_);
	case 13:exec_once(fanMgr_M_, 12, cut_);
	case 12:exec_once(fanMgr_L_, 11, cut_);
	case 11:exec_once(fanMgr_K_, 10, cut_);
	case 10:exec_once(fanMgr_J_, 9, cut_);
	case 9:exec_once(fanMgr_I_, 8, cut_);
	case 8:exec_once(fanMgr_H_, 7, cut_);
	case 7:exec_once(fanMgr_G_, 6, cut_);
	case 6:exec_once(fanMgr_F_, 5, cut_);
	case 5:exec_once(fanMgr_E_, 4, cut_);
	case 4:exec_once(fanMgr_D_, 3, cut_);
	case 3:exec_once(fanMgr_C_, 2, cut_);
	case 2:exec_once(fanMgr_B_, 1, cut_);
	case 1:exec_once(fanMgr_A_, 0, cut_);
	default:break;
	}
	
	return true;
}

bool AddFaultCmd::exec_once(FanMgr *fanMgr, int fanMgrTYPE, int cut){
	fanMgr_ = fanMgr;
	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR AddFaultCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->fListExtract)
	{
		fanMgr_->fListExtract = new FaultListExtract;
	}

	fanMgr_->fListExtract->extractFaultFromCircuit(fanMgr_->cir, fanMgrTYPE, cut);

	// add all faults
	if (optMgr_.isFlagSet("a"))
	{
		addAllFault();
	}
	
	return true;
}

void AddFaultCmd::addAllFault()
{
	std::cout << "#  Building fault list ...\n";
	fanMgr_->tmusg.periodStart();

	fanMgr_->fListExtract->faultsInCircuit_.resize(fanMgr_->fListExtract->extractedFaults_.size());
	
	FaultPtrListIter it = fanMgr_->fListExtract->faultsInCircuit_.begin();
	for (int i = 0; i < fanMgr_->fListExtract->extractedFaults_.size(); ++i, ++it)
	{
		(*it) = &fanMgr_->fListExtract->extractedFaults_[i];
	}


	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished building fault list";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";
}

ReportFaultCmd::ReportFaultCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	fanMgr_G_ = fanMgr_G;
	fanMgr_H_ = fanMgr_H;
	fanMgr_I_ = fanMgr_I;
	fanMgr_J_ = fanMgr_J;
	fanMgr_K_ = fanMgr_K;
	fanMgr_L_ = fanMgr_L;
	fanMgr_M_ = fanMgr_M;
	fanMgr_N_ = fanMgr_N;
	fanMgr_O_ = fanMgr_O;
	fanMgr_P_ = fanMgr_P;
	fanMgr_Q_ = fanMgr_Q;
	fanMgr_R_ = fanMgr_R;
	fanMgr_S_ = fanMgr_S;
	fanMgr_T_ = fanMgr_T;
	fanMgr_U_ = fanMgr_U;
	fanMgr_V_ = fanMgr_V;
	fanMgr_W_ = fanMgr_W;
	fanMgr_X_ = fanMgr_X;
	optMgr_.setName(name);
	optMgr_.setShortDes("report fault");
	optMgr_.setDes("report fault information");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "print only faults with state STATE", "STATE");
	opt->addFlag("s");
	opt->addFlag("state");
	optMgr_.regOpt(opt);
}

ReportFaultCmd::~ReportFaultCmd() {}

bool ReportFaultCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_A_->fListExtract || !fanMgr_B_->fListExtract || !fanMgr_C_->fListExtract || !fanMgr_D_->fListExtract)
	{
		std::cerr << "**ERROR ReportFaultCmd::exec(): fault list needed\n";
		return false;
	}

	bool stateSet = false;
	Fault::FAULT_STATE state = Fault::UD;
	if (optMgr_.isFlagSet("s"))
	{
		stateSet = true;
		std::string stateStr = optMgr_.getFlagVar("s");
		if (stateStr == "ud" || stateStr == "UD")
		{
			state = Fault::UD;
		}
		else if (stateStr == "dt" || stateStr == "DT")
		{
			state = Fault::DT;
		}
		else if (stateStr == "au" || stateStr == "AU")
		{
			state = Fault::AU;
		}
		else if (stateStr == "ti" || stateStr == "TI")
		{
			state = Fault::TI;
		}
		else if (stateStr == "re" || stateStr == "RE")
		{
			state = Fault::RE;
		}
		else if (stateStr == "ab" || stateStr == "AB")
		{
			state = Fault::AB;
		}
		else
		{
			stateSet = true;
			std::cerr << "**WARN ReportFaultCmd::exec(): fault state `";
			std::cerr << stateStr << "' is not supported\n";
		}
	}

	std::cout << "#  fault information\n";
	std::cout << "#    fault type:       ";
	switch (fanMgr_A_->fListExtract->faultListType_)
	{
		case FaultListExtract::SAF:
			std::cout << "stuck-at fault\n";
			break;
		case FaultListExtract::TDF:
			std::cout << "transition delay fault\n";
			break;
		case FaultListExtract::BRF:
			std::cout << "bridging fault\n";
			break;
		default:
			std::cout << "\n";
			break;
	}
	std::cout << "#    number of faults: " << fanMgr_A_->fListExtract->faultsInCircuit_.size()+fanMgr_B_->fListExtract->faultsInCircuit_.size()+fanMgr_C_->fListExtract->faultsInCircuit_.size()+fanMgr_D_->fListExtract->faultsInCircuit_.size()+fanMgr_E_->fListExtract->faultsInCircuit_.size()+fanMgr_F_->fListExtract->faultsInCircuit_.size()+fanMgr_G_->fListExtract->faultsInCircuit_.size()+fanMgr_H_->fListExtract->faultsInCircuit_.size()+fanMgr_I_->fListExtract->faultsInCircuit_.size()+fanMgr_J_->fListExtract->faultsInCircuit_.size()+fanMgr_K_->fListExtract->faultsInCircuit_.size()+fanMgr_L_->fListExtract->faultsInCircuit_.size()+fanMgr_M_->fListExtract->faultsInCircuit_.size()+fanMgr_N_->fListExtract->faultsInCircuit_.size()+fanMgr_O_->fListExtract->faultsInCircuit_.size()+fanMgr_P_->fListExtract->faultsInCircuit_.size()+fanMgr_Q_->fListExtract->faultsInCircuit_.size()+fanMgr_R_->fListExtract->faultsInCircuit_.size()+fanMgr_S_->fListExtract->faultsInCircuit_.size()+fanMgr_T_->fListExtract->faultsInCircuit_.size()+fanMgr_U_->fListExtract->faultsInCircuit_.size()+fanMgr_V_->fListExtract->faultsInCircuit_.size()+fanMgr_W_->fListExtract->faultsInCircuit_.size()+fanMgr_X_->fListExtract->faultsInCircuit_.size();
	std::cerr << fanMgr_A_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_B_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_C_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_D_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_E_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_F_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_G_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_H_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_I_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_J_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_K_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_L_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_M_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_N_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_O_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_P_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_Q_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_R_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_S_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_T_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_U_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_V_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_W_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cerr << fanMgr_X_->fListExtract->faultsInCircuit_.size() << "\n";
	std::cout << "\n";
	std::cout << "#    type    code    pin (cell)\n";
	std::cout << "#    ----    ----    ----------------------------------\n";	
	ShowFaultList(fanMgr_A_, stateSet, state);
	ShowFaultList(fanMgr_B_, stateSet, state);
	ShowFaultList(fanMgr_C_, stateSet, state);
	ShowFaultList(fanMgr_D_, stateSet, state);
	ShowFaultList(fanMgr_E_, stateSet, state);
	ShowFaultList(fanMgr_F_, stateSet, state);
	ShowFaultList(fanMgr_G_, stateSet, state);
	ShowFaultList(fanMgr_H_, stateSet, state);
	ShowFaultList(fanMgr_I_, stateSet, state);
	ShowFaultList(fanMgr_J_, stateSet, state);
	ShowFaultList(fanMgr_K_, stateSet, state);
	ShowFaultList(fanMgr_L_, stateSet, state);
	ShowFaultList(fanMgr_M_, stateSet, state);
	ShowFaultList(fanMgr_N_, stateSet, state);
	ShowFaultList(fanMgr_O_, stateSet, state);
	ShowFaultList(fanMgr_P_, stateSet, state);
	ShowFaultList(fanMgr_Q_, stateSet, state);
	ShowFaultList(fanMgr_R_, stateSet, state);
	ShowFaultList(fanMgr_S_, stateSet, state);
	ShowFaultList(fanMgr_T_, stateSet, state);
	ShowFaultList(fanMgr_U_, stateSet, state);
	ShowFaultList(fanMgr_V_, stateSet, state);
	ShowFaultList(fanMgr_W_, stateSet, state);
	ShowFaultList(fanMgr_X_, stateSet, state);


	std::cout << "\n";

	return true;
}

void ReportFaultCmd::ShowFaultList(FanMgr *fanMgr, bool stateSet, Fault::FAULT_STATE state){
	fanMgr_ = fanMgr;
	FaultPtrListIter it = fanMgr_->fListExtract->faultsInCircuit_.begin();
	for (; it != fanMgr_->fListExtract->faultsInCircuit_.end(); ++it)
	{
		if (!stateSet || (*it)->faultState_ != state)
		{
			continue;
		}
		std::cout << "#    ";
		switch ((*it)->faultType_)
		{			
			case Fault::SA0:
				std::cout << "SA0     ";
				break;
			case Fault::SA1:
				std::cout << "SA1     ";
				break;
			case Fault::STR:
				std::cout << "STR     ";
				break;
			case Fault::STF:
				std::cout << "STF     ";
				break;
			case Fault::BR:
				std::cout << "BR      ";
				break;
		}
		switch ((*it)->faultState_)
		{
			case Fault::UD:
				std::cout << " UD     ";
				break;
			case Fault::DT:
				std::cout << " DT     ";
				break;
			case Fault::PT:
				std::cout << " PT     ";
				break;
			case Fault::AU:
				std::cout << " AU     ";
				break;
			case Fault::TI:
				std::cout << " TI     ";
				break;
			case Fault::RE:
				std::cout << " RE     ";
				break;
			case Fault::AB:
				std::cout << " AB     ";
				break;
		}
		int cid = fanMgr_->cir->circuitGates_[(*it)->gateID_].cellId_;
		int pid = (*it)->faultyLine_;
		int pmtid = fanMgr_->cir->circuitGates_[(*it)->gateID_].primitiveId_;
		if ((*it)->gateID_ == -1)
		{ // CK
			std::cout << "CK";
		}
		else if ((*it)->gateID_ == -2)
		{ // test_si
			std::cout << "test_si";
		}
		else if ((*it)->gateID_ == -3)
		{ // test_so
			std::cout << "test_so";
		}
		else if ((*it)->gateID_ == -4)
		{ // test_se
			std::cout << "test_se";
		}
		else if (fanMgr_->cir->circuitGates_[(*it)->gateID_].gateType_ == Gate::PI)
		{
			std::cout << fanMgr_->nl->getTop()->getPort(cid)->name_ << " ";
			std::cout << "(primary input)";
		}
		else if (fanMgr_->cir->circuitGates_[(*it)->gateID_].gateType_ == Gate::PO)
		{
			std::cout << fanMgr_->nl->getTop()->getPort(cid)->name_ << " ";
			std::cout << "(primary output)";
		}
		else
		{
			Cell *c = fanMgr_->nl->getTop()->getCell(cid);
			// std::cout << "test" << c->name_<< " " << cid << "\n";
			Cell *libc = c->libc_;
			Cell *pmt = libc->getCell(pmtid);
			Port *p = NULL;
			if (pid < 0)
			{ // must be CK,SE,SI pins on FF
				if (pid == -1)
				{
					std::cout << c->name_ << "/CK ";
				}
				else if (pid == -2)
				{
					std::cout << c->name_ << "/SE ";
				}
				else if (pid == -3)
				{
					std::cout << c->name_ << "/SI ";
				}
				else
				{
					std::cout << c->name_ << "/QN ";
				}
			}
			else if (pid == 0)
			{ // output
				if (!strcmp(libc->name_, "SDFFXL"))
				{
					std::cout << c->name_ << "/Q ";
				}
				else
				{
					for (int i = 0; i < pmt->getNPort(); ++i)
					{
						if (pmt->getPort(i)->type_ != Port::OUTPUT)
						{
							continue;
						}
						Net *n = pmt->getPort(i)->exNet_;
						if (!n)
						{
							continue;
						}
						PortSet pset = libc->getNetPorts(n->id_);
						PortSet::iterator pit = pset.begin();
						for (; pit != pset.end(); ++pit)
						{
							if ((*pit)->top_ != libc)
							{
								continue;
							}
							p = (*pit);
							break;
						}
						if (p)
						{
							break;
						}
					}
				}
			}
			else
			{ // input
				int inCount = 0;
				for (int i = 0; i < pmt->getNPort(); ++i)
				{
					if (pmt->getPort(i)->type_ == Port::INPUT)
					{
						++inCount;
					}
					if (inCount != pid)
					{
						continue;
					}
					Net *n = pmt->getPort(i)->exNet_;
					if (!n)
					{
						continue;
					}
					PortSet pset = libc->getNetPorts(n->id_);
					PortSet::iterator pit = pset.begin();
					for (; pit != pset.end(); ++pit)
					{
						if ((*pit)->top_ != libc)
						{
							continue;
						}
						p = (*pit);
						break;
					}
					if (p)
					{
						break;
					}
				}
			}
			if (p)
			{
				std::cout << c->name_ << "/" << p->name_ << " ";
			}
			std::cout << "(" << libc->name_ << ")";
		}
		std::cout << "\n";
	}

}

ReportCircuitCmd::ReportCircuitCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	fanMgr_G_ = fanMgr_G;
	fanMgr_H_ = fanMgr_H;
	fanMgr_I_ = fanMgr_I;
	fanMgr_J_ = fanMgr_J;
	fanMgr_K_ = fanMgr_K;
	fanMgr_L_ = fanMgr_L;
	fanMgr_M_ = fanMgr_M;
	fanMgr_N_ = fanMgr_N;
	fanMgr_O_ = fanMgr_O;
	fanMgr_P_ = fanMgr_P;
	fanMgr_Q_ = fanMgr_Q;
	fanMgr_R_ = fanMgr_R;
	fanMgr_S_ = fanMgr_S;
	fanMgr_T_ = fanMgr_T;
	fanMgr_U_ = fanMgr_U;
	fanMgr_V_ = fanMgr_V;
	fanMgr_W_ = fanMgr_W;
	fanMgr_X_ = fanMgr_X;
	optMgr_.setName(name);
	optMgr_.setShortDes("report circuit");
	optMgr_.setDes("report circuit information");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportCircuitCmd::~ReportCircuitCmd() {}

bool ReportCircuitCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	// TODO:B!!!!!!!!!!!!!!!!!!!
	if (!fanMgr_A_->cir)
	{
		std::cerr << "**ERROR ReportCircuitCmd::exec(): circuit needed\n";
		return false;
	}

	Cell *top = fanMgr_A_->cir->pNetlist_->getTop();
	std::cout << "#  circuit information\n";
	std::cout << "#    netlist:         " << top->name_ << "\n";
	std::cout << "#    number of PIs:   " << fanMgr_A_->cir->numPI_ << "\n";
	std::cout << "#    number of PPIs:  " << fanMgr_A_->cir->numPPI_ << "\n";
	std::cout << "#    number of POs:   " << fanMgr_A_->cir->numPO_ << "\n";
	std::cout << "#    number of combs: " << fanMgr_A_->cir->numComb_ << "\n";
	std::cout << "#    number of gates: " << fanMgr_A_->cir->numGate_ << "\n";
	std::cout << "#    number of nets:  " << fanMgr_A_->cir->numNet_ << "\n";

	return true;
}

RunFaultSimCmd::RunFaultSimCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X, int *cut) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	fanMgr_E_ = fanMgr_E;
	fanMgr_F_ = fanMgr_F;
	fanMgr_G_ = fanMgr_G;
	fanMgr_H_ = fanMgr_H;
	fanMgr_I_ = fanMgr_I;
	fanMgr_J_ = fanMgr_J;
	fanMgr_K_ = fanMgr_K;
	fanMgr_L_ = fanMgr_L;
	fanMgr_M_ = fanMgr_M;
	fanMgr_N_ = fanMgr_N;
	fanMgr_O_ = fanMgr_O;
	fanMgr_P_ = fanMgr_P;
	fanMgr_Q_ = fanMgr_Q;
	fanMgr_R_ = fanMgr_R;
	fanMgr_S_ = fanMgr_S;
	fanMgr_T_ = fanMgr_T;
	fanMgr_U_ = fanMgr_U;
	fanMgr_V_ = fanMgr_V;
	fanMgr_W_ = fanMgr_W;
	fanMgr_X_ = fanMgr_X;
	cut_ = *cut;
	optMgr_.setName(name);
	optMgr_.setShortDes("run fault simulation");
	optMgr_.setDes("run fault simulation on the given pattern");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "simulation METHOD. Choose either pp (parallel pattern) or pf (parallel fault)", "METHOD");
	opt->addFlag("m");
	opt->addFlag("method");
	optMgr_.regOpt(opt);
}
RunFaultSimCmd::~RunFaultSimCmd() {}

bool RunFaultSimCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	std::cout << "#  Performing fault simulation ...\n";
	
	if (optMgr_.isFlagSet("m") && optMgr_.getFlagVar("m") == "pf")
	{
		// fanMgr_A_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_A_->pcoll, fanMgr_A_->fListExtract);
		fanMgr_A_->sim->parallelPatternFaultSimWithAllPattern(fanMgr_A_->pcoll, fanMgr_A_->fListExtract);
	}
	else
	{
		// #pragma omp parallel for
		#pragma omp parallel sections
	{
		#pragma omp section
		printf("BEGIN:A-----------\n");
		if(cut_ > 0){
			fanMgr_A_->sim = new Simulator(*fanMgr_A_->cir);
			fanMgr_A_->tmusg.periodStart();
			fanMgr_A_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_A_->pcoll, fanMgr_A_->fListExtract);
		}
		printf("END:A-----------\n");
		#pragma omp section
		printf("BEGIN:B-----------\n");
		if(cut_ > 1){
			fanMgr_B_->sim = new Simulator(*fanMgr_B_->cir);
			fanMgr_B_->tmusg.periodStart();
			fanMgr_B_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_B_->pcoll, fanMgr_B_->fListExtract);
		}
		printf("END:B-----------\n");
		#pragma omp section
		printf("BEGIN:C-----------\n");
		if(cut_ > 2){
			fanMgr_C_->sim = new Simulator(*fanMgr_C_->cir);
			fanMgr_C_->tmusg.periodStart();
			fanMgr_C_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_C_->pcoll, fanMgr_C_->fListExtract);
		}
		printf("END:C-----------\n");
		#pragma omp section
		printf("BEGIN:D-----------\n");
		if(cut_ > 3){
			fanMgr_D_->sim = new Simulator(*fanMgr_D_->cir);
			fanMgr_D_->tmusg.periodStart();
			fanMgr_D_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_D_->pcoll, fanMgr_D_->fListExtract);
		}
		printf("END:D-----------\n");
		#pragma omp section
		printf("BEGIN:E-----------\n");
		if(cut_ > 4){
			fanMgr_E_->sim = new Simulator(*fanMgr_E_->cir);
			fanMgr_E_->tmusg.periodStart();
			fanMgr_E_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_E_->pcoll, fanMgr_E_->fListExtract);
		}
		printf("END:E-----------\n");
		#pragma omp section
		printf("BEGIN:F-----------\n");
		if(cut_ > 5){
			fanMgr_F_->sim = new Simulator(*fanMgr_F_->cir);
			fanMgr_F_->tmusg.periodStart();
			fanMgr_F_->sim->parallelPatternFaultSimWithAllPattern(fanMgr_F_->pcoll, fanMgr_F_->fListExtract);
		}
		printf("END:F-----------\n");
		#pragma omp section
		printf("BEGIN:G-----------\n");
		if(cut_ > 6){
			fanMgr_G_->sim = new Simulator(*fanMgr_G_->cir);
			fanMgr_G_->tmusg.periodStart();
			fanMgr_G_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_G_->pcoll, fanMgr_G_->fListExtract);
		}
		printf("END:G-----------\n");
		#pragma omp section
		printf("BEGIN:H-----------\n");
		if(cut_ > 7){
			fanMgr_H_->sim = new Simulator(*fanMgr_H_->cir);
			fanMgr_H_->tmusg.periodStart();
			fanMgr_H_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_H_->pcoll, fanMgr_H_->fListExtract);
		}
		printf("END:H-----------\n");
		#pragma omp section
		printf("BEGIN:I-----------\n");
		if(cut_ > 8){
			fanMgr_I_->sim = new Simulator(*fanMgr_I_->cir);
			fanMgr_I_->tmusg.periodStart();
			fanMgr_I_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_I_->pcoll, fanMgr_I_->fListExtract);
		}
		printf("END:I-----------\n");
		#pragma omp section
		printf("BEGIN:J-----------\n");
		if(cut_ > 9){
			fanMgr_J_->sim = new Simulator(*fanMgr_J_->cir);
			fanMgr_J_->tmusg.periodStart();
			fanMgr_J_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_J_->pcoll, fanMgr_J_->fListExtract);
		}
		printf("END:J-----------\n");
		#pragma omp section
		printf("BEGIN:K-----------\n");
		if(cut_ > 10){
			fanMgr_K_->sim = new Simulator(*fanMgr_K_->cir);
			fanMgr_K_->tmusg.periodStart();
			fanMgr_K_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_K_->pcoll, fanMgr_K_->fListExtract);
		}
		printf("END:K-----------\n");
		#pragma omp section
		printf("BEGIN:L-----------\n");
		if(cut_ > 11){
			fanMgr_L_->sim = new Simulator(*fanMgr_L_->cir);
			fanMgr_L_->tmusg.periodStart();
			fanMgr_L_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_L_->pcoll, fanMgr_L_->fListExtract);
		}
		printf("END:L-----------\n");
		#pragma omp section
		printf("BEGIN:M-----------\n");
		if(cut_ > 12){
			fanMgr_M_->sim = new Simulator(*fanMgr_M_->cir);
			fanMgr_M_->tmusg.periodStart();
			fanMgr_M_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_M_->pcoll, fanMgr_M_->fListExtract);
		}
		printf("END:M-----------\n");
		#pragma omp section
		printf("BEGIN:N-----------\n");
		if(cut_ > 13){
			fanMgr_N_->sim = new Simulator(*fanMgr_N_->cir);
			fanMgr_N_->tmusg.periodStart();
			fanMgr_N_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_N_->pcoll, fanMgr_N_->fListExtract);
		}
		printf("END:N-----------\n");
		#pragma omp section
		printf("BEGIN:O-----------\n");
		if(cut_ > 14){
			fanMgr_O_->sim = new Simulator(*fanMgr_O_->cir);
			fanMgr_O_->tmusg.periodStart();
			fanMgr_O_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_O_->pcoll, fanMgr_O_->fListExtract);
		}
		printf("END:O-----------\n");
		#pragma omp section
		printf("BEGIN:P-----------\n");
		if(cut_ > 15){
			fanMgr_P_->sim = new Simulator(*fanMgr_P_->cir);
			fanMgr_P_->tmusg.periodStart();
			fanMgr_P_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_P_->pcoll, fanMgr_P_->fListExtract);
		}
		printf("END:P-----------\n");
		#pragma omp section
		printf("BEGIN:Q-----------\n");
		if(cut_ > 16){
			fanMgr_Q_->sim = new Simulator(*fanMgr_Q_->cir);
			fanMgr_Q_->tmusg.periodStart();
			fanMgr_Q_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_Q_->pcoll, fanMgr_Q_->fListExtract);
		}
		printf("END:Q-----------\n");
		#pragma omp section
		printf("BEGIN:R-----------\n");
		if(cut_ > 17){
			fanMgr_R_->sim = new Simulator(*fanMgr_R_->cir);
			fanMgr_R_->tmusg.periodStart();
			fanMgr_R_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_R_->pcoll, fanMgr_R_->fListExtract);
		}
		printf("END:R-----------\n");
		#pragma omp section
		printf("BEGIN:S-----------\n");
		if(cut_ > 18){
			fanMgr_S_->sim = new Simulator(*fanMgr_S_->cir);
			fanMgr_S_->tmusg.periodStart();
			fanMgr_S_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_S_->pcoll, fanMgr_S_->fListExtract);
		}
		printf("END:S-----------\n");
		#pragma omp section
		printf("BEGIN:T-----------\n");
		if(cut_ > 19){
			fanMgr_T_->sim = new Simulator(*fanMgr_T_->cir);
			fanMgr_T_->tmusg.periodStart();
			fanMgr_T_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_T_->pcoll, fanMgr_T_->fListExtract);
		}
		printf("END:T-----------\n");
		#pragma omp section
		printf("BEGIN:U-----------\n");
		if(cut_ > 20){
			fanMgr_U_->sim = new Simulator(*fanMgr_U_->cir);
			fanMgr_U_->tmusg.periodStart();
			fanMgr_U_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_U_->pcoll, fanMgr_U_->fListExtract);
		}
		printf("END:U-----------\n");
		#pragma omp section
		printf("BEGIN:V-----------\n");
		if(cut_ > 21){
			fanMgr_V_->sim = new Simulator(*fanMgr_V_->cir);
			fanMgr_V_->tmusg.periodStart();
			fanMgr_V_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_V_->pcoll, fanMgr_V_->fListExtract);
		}
		printf("END:V-----------\n");
		#pragma omp section
		printf("BEGIN:W-----------\n");
		if(cut_ > 22){
			fanMgr_W_->sim = new Simulator(*fanMgr_W_->cir);
			fanMgr_W_->tmusg.periodStart();
			fanMgr_W_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_W_->pcoll, fanMgr_W_->fListExtract);
		}
		printf("END:W-----------\n");
		#pragma omp section
		printf("BEGIN:X-----------\n");
		if(cut_ > 23){
			fanMgr_X_->sim = new Simulator(*fanMgr_X_->cir);
			fanMgr_X_->tmusg.periodStart();
			fanMgr_X_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_X_->pcoll, fanMgr_X_->fListExtract);
		}
		printf("END:X-----------\n");
	}
	}

	TmStat stat_A;
	fanMgr_A_->tmusg.getPeriodUsage(stat_A);
	std::cout << "#  Finished fault simulation\n";
	std::cout << "#  A:";
	std::cout << "    " << (double)stat_A.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat_A.vmSize / 1024.0 << " MB\n";
	rtime = (double)stat_A.rTime / 1000000.0;

	return true;
}

ReportStatsCmd::ReportStatsCmd(const std::string &name, FanMgr *fanMgr_A, FanMgr *fanMgr_B, FanMgr *fanMgr_C, FanMgr *fanMgr_D, FanMgr *fanMgr_E, FanMgr *fanMgr_F, FanMgr *fanMgr_G, FanMgr *fanMgr_H, FanMgr *fanMgr_I, FanMgr *fanMgr_J, FanMgr *fanMgr_K, FanMgr *fanMgr_L, FanMgr *fanMgr_M, FanMgr *fanMgr_N, FanMgr *fanMgr_O, FanMgr *fanMgr_P, FanMgr *fanMgr_Q, FanMgr *fanMgr_R, FanMgr *fanMgr_S, FanMgr *fanMgr_T, FanMgr *fanMgr_U, FanMgr *fanMgr_V, FanMgr *fanMgr_W, FanMgr *fanMgr_X) : Cmd(name)
{
	fanMgr_A_ = fanMgr_A;
	fanMgr_B_ = fanMgr_B;
	fanMgr_C_ = fanMgr_C;
	fanMgr_D_ = fanMgr_D;
	optMgr_.setName(name);
	optMgr_.setShortDes("report statistics");
	optMgr_.setDes("reports statistics on fault coverage");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportStatsCmd::~ReportStatsCmd() {}

bool ReportStatsCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_A_->fListExtract || fanMgr_A_->fListExtract->faultsInCircuit_.size() == 0)
	{
		std::cerr << "**WARN ReportStatsCmd::exec(): no statistics\n";
		return false;
	}

	// determine fault model
	std::string ftype = "";
	switch (fanMgr_A_->fListExtract->faultListType_)
	{
		case FaultListExtract::SAF:
			ftype = "SAF";
			break;
		case FaultListExtract::TDF:
			ftype = "TDF";
			break;
		case FaultListExtract::BRF:
			ftype = "BRF";
			break;
	}

	// determine pattern type
	std::string ptype = "";
	switch (fanMgr_A_->pcoll->type_)
	{
		case PatternProcessor::BASIC_SCAN:
			ptype = "BASIC";
			break;
		case PatternProcessor::LAUNCH_CAPTURE:
			ptype = "LOC";
			break;
		case PatternProcessor::LAUNCH_SHIFT:
			ptype = "LOS";
			break;
	}

	// determine atpg runtime
	// float rtime = (double)fanMgr_->atpgStat.rTime / 1000000.0;

	size_t npat = 0;

	if (fanMgr_A_->pcoll)
	{
		npat = fanMgr_A_->pcoll->patternVector_.size();
	}

	size_t numCollapsedFaults = 0;
	size_t fu = 0;
	size_t ud = 0;
	size_t dt = 0;
	size_t pt = 0;
	size_t au = 0;
	size_t ti = 0;
	size_t re = 0;
	size_t ab = 0;

	FaultPtrListIter it_A = fanMgr_A_->fListExtract->faultsInCircuit_.begin();
	for (; it_A != fanMgr_A_->fListExtract->faultsInCircuit_.end(); ++it_A)
	{
		++numCollapsedFaults;
		int eq = (*it_A)->equivalent_;
		fu += eq;
		switch ((*it_A)->faultState_)
		{
			case Fault::UD:
				ud += eq;
				break;
			case Fault::DT:
				dt += eq;
				break;
			case Fault::PT:
				pt += eq;
				break;
			case Fault::AU:
				au += eq;
				break;
			case Fault::TI:
				ti += eq;
				break;
			case Fault::RE:
				re += eq;
				break;
			case Fault::AB:
				ab += eq;
				break;
		}
	}

	FaultPtrListIter it_B = fanMgr_B_->fListExtract->faultsInCircuit_.begin();
	for (; it_B != fanMgr_B_->fListExtract->faultsInCircuit_.end(); ++it_B)
	{
		++numCollapsedFaults;
		int eq = (*it_B)->equivalent_;
		fu += eq;
		switch ((*it_B)->faultState_)
		{
			case Fault::UD:
				ud += eq;
				break;
			case Fault::DT:
				dt += eq;
				break;
			case Fault::PT:
				pt += eq;
				break;
			case Fault::AU:
				au += eq;
				break;
			case Fault::TI:
				ti += eq;
				break;
			case Fault::RE:
				re += eq;
				break;
			case Fault::AB:
				ab += eq;
				break;
		}
	}

	FaultPtrListIter it_C = fanMgr_C_->fListExtract->faultsInCircuit_.begin();
	for (; it_C != fanMgr_C_->fListExtract->faultsInCircuit_.end(); ++it_C)
	{
		++numCollapsedFaults;
		int eq = (*it_C)->equivalent_;
		fu += eq;
		switch ((*it_C)->faultState_)
		{
			case Fault::UD:
				ud += eq;
				break;
			case Fault::DT:
				dt += eq;
				break;
			case Fault::PT:
				pt += eq;
				break;
			case Fault::AU:
				au += eq;
				break;
			case Fault::TI:
				ti += eq;
				break;
			case Fault::RE:
				re += eq;
				break;
			case Fault::AB:
				ab += eq;
				break;
		}
	}

	FaultPtrListIter it_D = fanMgr_D_->fListExtract->faultsInCircuit_.begin();
	for (; it_D != fanMgr_D_->fListExtract->faultsInCircuit_.end(); ++it_D)
	{
		++numCollapsedFaults;
		int eq = (*it_D)->equivalent_;
		fu += eq;
		switch ((*it_D)->faultState_)
		{
			case Fault::UD:
				ud += eq;
				break;
			case Fault::DT:
				dt += eq;
				break;
			case Fault::PT:
				pt += eq;
				break;
			case Fault::AU:
				au += eq;
				break;
			case Fault::TI:
				ti += eq;
				break;
			case Fault::RE:
				re += eq;
				break;
			case Fault::AB:
				ab += eq;
				break;
		}
	}

	float fc = (float)dt / (float)fu * 100;
	float tc = (float)dt / (float)(ud + dt + pt + ab) * 100;
	float ae = (float)(dt + au + ti + re) / (float)fu * 100;

	std::cout << std::right;
	std::cout << std::setprecision(4);
	std::cout << "#                 Statistics Report\n";
	std::cout << "#  Circuit name                  " << std::setw(19);
	std::cout << fanMgr_A_->nl->getTop()->name_ << "\n";
	std::cout << "#  Fault model                   " << std::setw(19) << ftype << "\n";
	std::cout << "#  Pattern type                  " << std::setw(19) << ptype << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  Fault classes                             #faults\n";
	std::cout << "#  ----------------------------  -------------------\n";
	std::cout << "#    FU (full)                   " << std::setw(19) << fu << "\n";
	std::cout << "#    FU (collapsed)              " << std::setw(19) << numCollapsedFaults << "\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    UD (undetected)             " << std::setw(19) << ud << "\n";
	std::cout << "#    PT (possibly testable)      " << std::setw(19) << pt << "\n";
	std::cout << "#    AU (atpg untestable)        " << std::setw(19) << au << "\n";
	std::cout << "#    RE (redundant)              " << std::setw(19) << re << "\n";
	std::cout << "#    AB (atpg abort)             " << std::setw(19) << ab << "\n";
	std::cout << "#    TI (tied)                   " << std::setw(19) << ti << "\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    DT (detected)               " << std::setw(19) << dt << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  Coverage                               percentage\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    test coverage                            ";
	std::cout << std::setw(5) << tc << "%\n";
	std::cout << "#    fault coverage                           ";
	std::cout << std::setw(5) << fc << "%\n";
	std::cout << "#    atpg effectiveness                       ";
	std::cout << std::setw(5) << ae << "%\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  #Patterns                     " << std::setw(19) << npat << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  ATPG runtime                  " << std::setw(17) << rtime;
	std::cout << " s\n";
	std::cout << "#  -------------------------------------------------\n";

	return true;
}
