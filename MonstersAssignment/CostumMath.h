#ifndef MATH_H
#define MATH_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

class CostumMath
{
public:
	CostumMath();

	static int getRandom(int, int);

	static float getVectorLenght(int, int, int, int);

	static double getPower(double, int);
};

#endif // !MATH_H