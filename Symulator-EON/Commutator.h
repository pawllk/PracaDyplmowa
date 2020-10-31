#pragma once
#ifndef COMMUTATOR_H
#define COMMUTATOR_H
#include<vector>
class Printer;
class Commutator
{
public:
	Commutator(Printer*& printer, int section, int id,int connection_number, int path_capacity);
	~Commutator();
private:
	Printer* commutator_printer = nullptr;
	const int input_section = 0;
	int section_number;
	int commutator_id;
	std::vector<int> input_path;
	std::vector<int> output_path;
};
#endif