#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "Character.h"
#include "console.h"

class Monster : public Character
{
public:
	Monster(std::string, char);

	enum State
	{
		ROAMING,
		CHASING
	};

	void setState(State);
	State getState();

	void setVisionRange(int);
	int getVisionRange();

	void setChasingCounter(int);
	int getChasingCounter();

	void setChasingCooldown(int);
	int getChasingCooldown();

	void setHealth(int);
	int getHealth();

	void setCanMove(bool);
	bool getCanMove();

	~Monster();

private:
	State state;

	int visionRange;
	int chasingCounter;
	int chasingCooldown;
	int health;

	bool canMove;
};

#endif // !MONSTER_H