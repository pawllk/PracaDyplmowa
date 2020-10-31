#pragma once
#ifndef EVENT_H
#define EVENT_H
#include <functional>
#include <queue>
#include <vector>

class Event
{
public:
	enum class Phase { Creating, Check, Sending, Collecting };
	typedef std::priority_queue<Event*, std::vector<Event*>, std::function<bool(Event*, Event*)>> Agenda;
	Event(int cost, int source, double service, int goal, Agenda* agenda);
	virtual ~Event();
	virtual void Execute() = 0;
	void Activate(double jump, bool do_jump = true);
	void Completed();
	double ReturnGenerationTime();
	double ReturnServiceTime();
	int ReturnEventSource();
	bool ReturnStatus();
	Agenda* ReturnAgenda();
	
private:
	double generation_time;
	double service_time;
	int event_cost;
	int event_source;
	int event_goal;
	bool status;
	Agenda* event_agenda = nullptr;
};
#endif