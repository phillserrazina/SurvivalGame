#include "Character.h"

Character::Character()
{
	name = "Default Name";
	avatar = 'C';
	xPos = 1;
	yPos = 1;
}

Character::Character(std::string n, char c) : name(n), avatar(c)
{
	xPos = 1;
	yPos = 1;
}

void Character::setName(std::string s)
{
	name = s;
}

std::string Character::getName()
{
	return name;
}

void Character::setAvatar(char c)
{
	avatar = c;
}

char Character::getAvatar()
{
	return avatar;
}

void Character::setX(int c)
{
	xPos = c;
}

int Character::getX()
{
	return xPos;
}

void Character::setY(int c)
{
	yPos = c;
}

int Character::getY()
{
	return yPos;
}