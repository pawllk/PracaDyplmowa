#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include <queue>
#include <vector>
class Printer;
class ClosField;
class Source;
class System
{
public:
	enum class Algorithm { Point, Group };
	System(Printer*& printer, std::queue<int>& data);
	~System();
	void AlgorithmChoice(int choice);
	void GetFileData(std::queue<int>& data);
	void CreateSourceList(std::queue<int>& data);
	std::vector<Source*> ReturnSourceList();
	Source* ReturnSource(int id);
private:
	Printer* system_printer = nullptr;
	ClosField* clos_field = nullptr;
	Algorithm algorithm;
	std::vector<Source*> source_list;
	int choice;
	int field_columns;
	int field_rows;
	int path_capacity;
	int connection_number;
	int erlang_number;
};

#endif
