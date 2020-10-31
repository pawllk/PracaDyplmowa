#include "Generator.h"
#include <cmath>

Generator::Generator(int seed)
{
	this->seed = seed;
}

Generator::~Generator()
{
}

double Generator::Rand() // rozk�ad r�wnomierny do zrobienia jakiekolwiek rozk�adu potrzebny jest r�wnomierny
{
	int h = seed / kQ;
	seed = kA * (seed - kQ * h) - kR * h;
	if (seed < 0)
	{
		seed = seed + static_cast<int>(kM);
	}
	return seed / kM;
}

double Generator::RandExp(double intens) //rozk�ad wyk�adniczy
{
	auto var = Rand();
	return -(1.0 / intens) * log(var);;
}

int Generator::Rand(int max, int min)
{
	return Rand() * (max - min) + min;
}
