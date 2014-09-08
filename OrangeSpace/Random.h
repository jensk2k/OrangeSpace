#pragma once
#include <cstdlib>
#include <ctime>

class Random
{
public:
	static void Seed();
	static float Range(float min, float max);
	static float ZeroOne();
};

