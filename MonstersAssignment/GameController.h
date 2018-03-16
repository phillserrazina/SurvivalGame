#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include<iostream>
#include<conio.h>
#include<vector>
#include "CostumMath.h"
#include "Player.h"
#include "Bomb.h"
#include "Monster.h"
#include "GridManager.h"
#include "GameManager.h"
#include "console.h"

using namespace std;

class Controller
{
private:
	vector<Monster> mobVec;
	vector<Player> playerVec;

	Bomb bomb;

public:
	Controller();

	static bool bombPlaced;

	void setBombPlaced(bool);
	bool getBombPlaced();

	void setMobVec(vector<Monster> *);
	void setPlayerVec(vector<Player> *);

	void movePlayer(Player &, Grid);

	void mobRoaming(Monster &, Player &, Grid grid);
	void mobChasing(Monster &, Player &);
	
	void moveMob(Monster &, Player &, Grid grid);
};

#endif // !GAME_CONTROLLER_H