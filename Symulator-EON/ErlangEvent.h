#pragma once
#ifndef ERLANGEVENT_H
#define ERLANGEVENT_H
#include "Event.h"
class Printer;
class System;
class ErlangEvent : public Event
{
public:
	ErlangEvent(Printer*& printer, System* system, int cost, int source, double service, int goal, Agenda* agenda);
	~ErlangEvent();
	void Execute() override;
	
private:
	Printer* erlang_printer = nullptr;
	System* erlang_system = nullptr;
	bool work;
	Phase erlang_phase;
};
#endif