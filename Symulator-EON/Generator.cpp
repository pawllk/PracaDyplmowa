#include "Generator.h"
#include <cmath>

Generator::Generator(int seed)
{
	this->seed = seed;
}

Generator::~Generator()
{
}

double Generator::Rand() // rozk³ad równomierny do zrobienia jakiekolwiek rozk³adu potrzebny jest równomierny
{
	int h = seed / kQ;
	seed = kA * (seed - kQ * h) - kR * h;
	if (seed < 0)
	{
		seed = seed + static_cast<int>(kM);
	}
	return seed / kM;
}

double Generator::RandExp(double intens) //rozk³ad wyk³adniczy
{
	auto var = Rand();
	return -(1.0 / intens) * log(var);;
}

int Generator::Rand(int max, int min)
{
	return Rand() * (max - min) + min;
}
