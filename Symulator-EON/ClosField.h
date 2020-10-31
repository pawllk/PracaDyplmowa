#pragma once
#ifndef CLOSFIELD_H
#define CLOSFIELD_H
#include <vector>
class Printer;
class Commutator;
class ClosField
{
public:
	ClosField(Printer*& printer, int rows, int columns, int connection_number, int capacity);
	~ClosField();
private:
	Printer* field_printer = nullptr;
	std::vector<Commutator*> commutator_list;
	int field_rows;
	int field_columns;
	int path_capacity;
};
#endif