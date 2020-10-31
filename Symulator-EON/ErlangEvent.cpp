#include "ErlangEvent.h"
#include "Printer.h"
#include "System.h"
#include "Source.h"

ErlangEvent::ErlangEvent(Printer*& printer, System* system, int cost, int source, double service, int goal, Agenda* agenda)
	: Event(cost, source, service, goal, agenda)
{
	erlang_printer = printer;
	erlang_system = system;
	erlang_phase = Phase::Creating;
}

ErlangEvent::~ErlangEvent()
{
	//erlang_printer->Print("DLETING EVNET ");
}

void ErlangEvent::Execute()
{
	work = true;
	while(work)
	{
		switch (erlang_phase)
		{
		case Phase::Creating:
			erlang_system->ReturnSource(ReturnEventSource())->GenerateEvent(ReturnServiceTime(), ReturnAgenda());
			erlang_phase=Phase::Check;
			break;
		case Phase::Check:
			Completed();
			work = false;
			break;
		case Phase::Sending:
			break;
		case Phase::Collecting:
			break;
		}
	}
}
