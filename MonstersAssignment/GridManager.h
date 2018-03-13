#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include<iostream>
#include "console.h"

class Grid
{
private:
	int gridWidth;
	int gridHeight;

	int startingX;
	int startingY;

public:
	Grid();

	void setGridWidth(int);
	int getGridWidth();

	void setGridHeight(int);
	int getGridHeight();

	void setGridStartX(int);
	int getGridStartX();

	void setGridStartY(int);
	int getGridStartY();

	void drawGrid();
};

#endif // !GRIDMANAGER_H