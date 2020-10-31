#pragma once
#ifndef SOURCE_H
#define SOURCE_H
#include "Event.h"
class Printer;
class Generator;
class System;
class Source
{
public:
	enum class SourceType { Erlang, Engset, Pascal };
	Source(Printer*& printer, System* system, SourceType source_type, int id, int event_cost, int mi_value, int path_number, 
			int path_seed, int time_seed, int path_capacity, int source_number);
	~Source();
	void GenerateEvent(double time, Event::Agenda* agenda);
	
private:
	const int a = 3;
	Printer* source_printer = nullptr;
	System* source_system = nullptr;
	Generator* path_generator = nullptr; //generator do wyboru sciezek oraz ustalania sciezki docelowej
	Generator* time_generator = nullptr; //generator do generowania czasu trwania zgloszenia
	SourceType type;
	int source_id;
	int notification_price;
	int mi;
	int possible_path;
	double lambda; //intesywnosc zrodla;
};
#endif