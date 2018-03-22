#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include<iostream>
#include<conio.h>
#include<vector>
#include "console.h"
#include "CostumMath.h"
#include "GridManager.h"
#include "Player.h"
#include "Monster.h"
#include "Bomb.h"

using namespace std;

class Controller
{
private:
	Bomb bomb;
	int playerBombs;

public:
	Controller();

	vector<Monster> mobVector;
	vector<Player> playerVector;

	Bomb& getBomb();

	void setPlayerBombs(int);
	int getPlayerBombs();

	void movePlayer(Player &, Grid);

	void mobRoaming(Monster &, Player &, Grid);
	void mobChasing(Monster &, Player &);
	
	void moveMob(Monster &, Player &, Grid);
};

#endif // !GAME_CONTROLLER_H