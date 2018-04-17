#ifndef BOMB_H
#define BOMB_H

#include<vector>
#include "Player.h"
#include "Monster.h"
#include "CostumMath.h"

class Bomb : public Character
{
private:
	int damage;
	int timer;
	float range;
	bool bombPlaced;

public:
	Bomb();

	void setBombPlaced(bool b);
	bool getBombPlaced();

	void setDamage(int);
	int getDamage();

	void setTimer(int);
	int getTimer();

	void setRange(float);
	float getRange();

	void boomBomb(std::vector<Monster> &, Player);
};

#endif // !BOMB_H