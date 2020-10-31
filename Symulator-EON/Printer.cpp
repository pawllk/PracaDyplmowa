#include "Printer.h"
#include <iostream>

Printer::Printer()
{
}

Printer::~Printer()
{
}

void Printer::Print(std::string msg)
{
	std::cout << " [SYSTEM MSG] " + msg << std::endl;
}
