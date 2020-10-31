#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Event.h"
#include <vector>
class System;
class Printer;
class Source;
class Simulator
{
public:
	Simulator(Printer*& printer, System*& system);
	~Simulator();
	void Run();
	
private:
	Printer* simulator_printer = nullptr;
	System* simulator_system = nullptr;
	std::vector<Source*> simulation_source_list;
	double simulation_timer;                         
};
#endif