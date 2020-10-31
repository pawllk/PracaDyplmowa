#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
class Generator
{
public:
    Generator(int seed);
    ~Generator();
    double Rand();                     //równomierny
    double RandExp(double intens);     //wyk³adniczy
    int Rand(int max, int min = 0);

private:
    int seed;
    const double kM = 2147483647.0;
    static const int kA = 16807;
    static const int kQ = 127773;
    static const int kR = 2836;
};
#endif