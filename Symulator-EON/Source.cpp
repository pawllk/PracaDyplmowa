#include "Source.h"
#include "Printer.h"
#include "Generator.h"
#include "ErlangEvent.h"

Source::Source(Printer*& printer, System* system, SourceType source_type, int id, int event_cost, int mi_value, int path_number, int path_seed, int time_seed
				, int path_capacity, int source_number)
{
	source_printer = printer;
	source_system = system;
	type = source_type;
	source_id = id;
	notification_price = event_cost;
	mi = mi_value;
	possible_path = path_number;
	path_generator = new Generator(path_seed);
	time_generator = new Generator(time_seed);
	lambda = (a * 1 * path_capacity) / static_cast<double>((source_number * mi * notification_price));
	int val = source_number * mi * notification_price;
	source_printer->Print("INTENSITY: " + std::to_string(lambda));
	//source_printer->Print("Erlang source ID: " + std::to_string(source_id));
}

Source::~Source()
{
	//source_printer->Print("Deleting erlang source ID: " + std::to_string(source_id));
}

void Source::GenerateEvent(double time, Event::Agenda* agenda)
{
	if (type == SourceType::Erlang)
	{
		double service_time = time + time_generator->RandExp(lambda);
		auto* helper = new ErlangEvent(source_printer, source_system, notification_price, source_id, service_time,
										path_generator->Rand(possible_path), agenda);
		if (time == 0)
		{
			helper->Activate(time, false);
		}
		else
		{
			helper->Activate(time, false);
		}
	}
}
