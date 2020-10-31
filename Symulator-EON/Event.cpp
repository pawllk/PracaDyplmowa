#include "Event.h"

Event::Event(int cost, int source, double service, int goal, Agenda* agenda)
{
	event_cost = cost;
	event_source = source;
	service_time = service;
	event_goal = goal;
	event_agenda = agenda;
	status = false;
}

Event::~Event()
{
}

void Event::Activate(double jump, bool do_jump)
{
	if (do_jump)
	{
		generation_time += jump;
	}
	else
	{
		generation_time = jump;
	}
	event_agenda->push(this);
}

void Event::Completed()
{
	status = true;
}

double Event::ReturnGenerationTime()
{
	return generation_time;
}

double Event::ReturnServiceTime()
{
	return service_time;
}

int Event::ReturnEventSource()
{
	return event_source;
}

bool Event::ReturnStatus()
{
	return status;
}

Event::Agenda* Event::ReturnAgenda()
{
	return event_agenda;
}
