#include "System.h"
#include "Printer.h"
#include "ClosField.h"
#include "Source.h"

System::System(Printer*& printer, std::queue<int>& data)
{
	system_printer = printer;
	system_printer->Print("Creating new simulation system...");
	GetFileData(data);
	AlgorithmChoice(choice);
	clos_field = new ClosField(system_printer, field_rows, field_columns, connection_number, path_capacity);
	CreateSourceList(data);
}

System::~System()
{
	delete clos_field;
	system_printer->Print("Deleting simulation system...");
	for (Source*& element : source_list)
	{
		delete element;
	}
}

void System::AlgorithmChoice(int choice)
{
	if (choice == 0)
	{
		algorithm = Algorithm::Point;
		system_printer->Print("ALGORITHM: Point-to-Point");
	}
	else if (choice == 1)
	{
		algorithm = Algorithm::Group;
		system_printer->Print("ALGORITHM: Point-to-Group");
	}
}

void System::GetFileData(std::queue<int>& data)
{
	choice = data.front();
	data.pop();
	field_rows = data.front();
	data.pop();
	field_columns = data.front();
	data.pop();
	path_capacity = data.front();
	data.pop();
	erlang_number = data.front();
	data.pop();
	connection_number = field_rows;
}

void System::CreateSourceList(std::queue<int>& data)
{
	for (int i = 0; i < erlang_number; ++i)
	{
		int event_cost = data.front();
		data.pop();
		int mi_value = data.front();
		data.pop();
		int path_seed = data.front();
		data.pop();
		int time_seed = data.front();
		data.pop();
		source_list.push_back(new Source(system_printer, this, Source::SourceType::Erlang, i, event_cost, mi_value,connection_number
								, path_seed, time_seed, path_capacity, erlang_number));
	}
}

std::vector<Source*> System::ReturnSourceList()
{
	return source_list;
}

Source* System::ReturnSource(int id)
{
	return source_list.at(id);
}
