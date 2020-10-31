#pragma once
#ifndef PRINTER_H
#define PRINTER_H
#include <string>
class Printer
{
public:
	Printer();
	~Printer();
	void Print(std::string msg);   // Function that get comunicate that will be printed on screen
};
#endif

