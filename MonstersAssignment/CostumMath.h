#ifndef MATH_H
#define MATH_H

#include<iostream>
#include<cstdlib>
#include<ctime>

class CostumMath
{
private:
	struct Vector
	{
		int x1;
		int y1;

		int x2;
		int y2;
	};

public:
	CostumMath();

	int getRandom(int, int);

	float getVectorLenght(int, int, int, int);
};

#endif // !MATH_H