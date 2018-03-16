#include "Monster.h"

int Monster::kill = 0;

Monster::Monster(std::string s, char c) : Character(s, c)
{
	state = ROAMING;
	visionRange = 10;
	chasingCooldown = 5;

	xPos = 1;
	yPos = 1;

	health = 1;
}

void Monster::setState(State s)
{
	state = s;
}

Monster::State Monster::getState()
{
	return state;
}

void Monster::setVisionRange(int i)
{
	visionRange = i;
}

int Monster::getVisionRange()
{
	return visionRange;
}

void Monster::setChasingCounter(int i)
{
	chasingCounter = i;
}

int Monster::getChasingCounter()
{
	return chasingCounter;
}

void Monster::setChasingCooldown(int i)
{
	chasingCooldown = i;
}

int Monster::getChasingCooldown()
{
	return chasingCooldown;
}

void Monster::setHealth(int i)
{
	health = i;
}

int Monster::getHealth()
{
	return health;
}

void Monster::setDead(bool b)
{
	isDead = b;
}

bool Monster::getDead()
{
	return isDead;
}

Monster::~Monster()
{
	kill++;
}