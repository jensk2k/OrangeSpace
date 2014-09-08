#include "Random.h"

void Random::Seed()
{
	srand(time(0));
}

float Random::Range(float min, float max)
{
	float range = max - min;
	float zeroOne = Random::ZeroOne();

	float result = min + (zeroOne * range);

	return result;
}

float Random::ZeroOne()
{
	return (float)rand() / (float)RAND_MAX;
}