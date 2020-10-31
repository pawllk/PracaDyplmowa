#include "ClosField.h"
#include "Printer.h"
#include "Commutator.h"

ClosField::ClosField(Printer*& printer, int rows, int columns, int connection_number, int capacity)
{
	field_printer = printer;
	field_rows = rows;
	field_columns = columns;
	path_capacity = capacity;
	for (int i = 0; i < columns; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			commutator_list.push_back(new Commutator(field_printer, i, j, connection_number, path_capacity));
		}
	}
	field_printer->Print("Creating CLOS structure of size " + std::to_string(field_rows) + "x" + std::to_string(field_columns));
	field_printer->Print("Capacity of each connection: " + std::to_string(path_capacity));
}

ClosField::~ClosField()
{
	//field_printer->Print("Deleting Clos structure");
	for (Commutator*& element : commutator_list)
	{
		delete element;
	}
}
