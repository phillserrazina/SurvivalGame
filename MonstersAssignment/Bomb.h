#ifndef BOMB_H
#define BOMB_H

#include<vector>
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "GameController.h"
#include "CostumMath.h"

class Bomb : public Character
{
private:
	int damage;
	int timer;
	float range;

public:
	Bomb();

	void setDamage(int);
	int getDamage();

	void setTimer(int);
	int getTimer();

	void setRange(float);
	float getRange();

	void boomBomb(std::vector<Monster>, Player);
};

#endif // !BOMB_H