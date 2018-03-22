#ifndef MATH_H
#define MATH_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

struct Point
{
	int x;
	int y;
};

struct MathVector
{
	int x1;
	int y1;

	int x2;
	int y2;
};

class CostumMath
{
private:
	

public:
	CostumMath();

	static int getRandom(int, int);

	static float getVectorLenght(int, int, int, int);
	static float getVectorLenght(MathVector);

	static double getPower(double, int);
};

#endif // !MATH_H