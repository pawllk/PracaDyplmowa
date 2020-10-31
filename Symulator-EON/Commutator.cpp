#include "Commutator.h"
#include "Printer.h"

Commutator::Commutator(Printer*& printer, int section, int id, int connection_number, int path_capacity)
{
	commutator_printer = printer;
	section_number = section;
	commutator_id = id;
	for (int i = 0; i < connection_number; ++i)
	{
		output_path.push_back(path_capacity);
		if (section_number == input_section)
		{
			input_path.push_back(path_capacity);
		}
	}
	//commutator_printer->Print("COMMUTATOR ID: " + std::to_string(commutator_id) + " SECTION: " + std::to_string(section_number));
}

Commutator::~Commutator()
{
	//commutator_printer->Print("Deleting commutator");
}
