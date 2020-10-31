#include <fstream>
#include <string>
#include <queue>
#include "System.h"
#include "Printer.h"
#include "Simulator.h"

int main(int argc, char* argv[]) {

    std::string line;
    std::fstream file;
    std::queue<int> file_data;
    file.open("input.txt", std::ios::in);
    if (file.good() == true)
    {
        std::string helper = "";
        while (!file.eof())
        {
            std::getline(file, line);
            for (int i = 0; i < line.length(); ++i)
            {
                if (line[i] != '#')
                {
                    helper += line[i];
                }
                else if (line[i] == '#')
                {
                    int var = std::stoi(helper);
                    file_data.push(var);
                    helper = "";
                }
            }
        }
        file.close();
    }
    Printer* new_printer = new Printer();
    System* new_system = new System(new_printer, file_data);
    Simulator* new_simulator = new Simulator(new_printer, new_system);
    new_simulator->Run();
    delete new_simulator;
    return(0);
}