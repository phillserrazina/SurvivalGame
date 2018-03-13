#include "GridManager.h"

Grid::Grid()
{
	gridWidth = 20;
	gridHeight = 20;

	startingX = 0;
	startingY = 0;
}

void Grid::setGridWidth(int i)
{
	gridWidth = i;
}

int Grid::getGridWidth()
{
	return gridWidth;
}

void Grid::setGridHeight(int i)
{
	gridHeight = i;
}

int Grid::getGridHeight()
{
	return gridHeight;
}

void Grid::setGridStartX(int i)
{
	startingX = i;
}

int Grid::getGridStartX()
{
	return startingX;
}

void Grid::setGridStartY(int i)
{
	startingY = i;
}

int Grid::getGridStartY()
{
	return startingY;
}

void Grid::drawGrid()
{
	// TOP EDGE
	Console::setCursorPosition(startingY, startingX);
	Console::drawLineH(gridWidth, 'X');

	// BOTTOM EDGE
	Console::setCursorPosition(startingY + gridHeight, startingX + 1);
	Console::drawLineH(gridWidth, 'X');

	// LEFT EDGE
	Console::setCursorPosition(startingY + 1, startingX);
	Console::drawLineV(gridHeight, 'X');

	// RIGHT EDGE
	Console::setCursorPosition(startingY, startingX + gridWidth);
	Console::drawLineV(gridHeight, 'X');
}