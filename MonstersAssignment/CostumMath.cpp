#include "CostumMath.h"

CostumMath::CostumMath()
{
	srand(static_cast<unsigned int>(time(NULL)));
	rand();
}

// Get a Random number in between a set minimum and maximum value
int CostumMath::getRandom(int minValue, int maxValue)
{
	int x = rand() % (maxValue - minValue) + minValue;

	return x;
}

// Vector Lenght
// ||AB|| = squareRoot((Ax - Bx)^2 + (Ay - By)^2)
float CostumMath::getVectorLenght(int xV1, int yV1, int xV2, int yV2)
{
	float ABx = xV2 - xV1;
	float ABy = yV2 - yV1;

	float lenght = sqrt((ABx * ABx) + (ABy * ABy));

	return lenght;
}

// Powers
// base ^ exponent
double CostumMath::getPower(double base, int exponent)
{
	double result = 1;

	for (int i = 0; i < exponent; i++)
	{
		result = result * base;
	}

	return result;
}