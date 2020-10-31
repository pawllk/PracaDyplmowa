#include "Simulator.h"
#include "Printer.h"
#include "System.h"
#include "Source.h"

Simulator::Simulator(Printer*& printer, System*& system)
{
	simulator_printer = printer;
	simulator_system = system;
	simulation_source_list = simulator_system->ReturnSourceList();
	simulation_timer = 0;
}

Simulator::~Simulator()
{
	delete simulator_system;
	delete simulator_printer;
}

void Simulator::Run()
{
	simulator_printer->Print("Starting a new simulation");
	auto cmp = [](Event* left, Event* right) { return left->ReturnGenerationTime() > right->ReturnGenerationTime(); };
	Event::Agenda agenda(cmp);
	for (int i = 0; i < simulation_source_list.size(); ++i)
	{
		simulation_source_list.at(i)->GenerateEvent(simulation_timer, &agenda);
	}
	
	while(!agenda.empty())
	{
		Event* helper = agenda.top();
		agenda.pop();
		simulation_timer = helper->ReturnGenerationTime();
		//simulator_printer->Print(std::to_string(simulation_timer));
		helper->Execute();
		if (helper->ReturnStatus())
		{
			delete helper;
		}
	}
}
