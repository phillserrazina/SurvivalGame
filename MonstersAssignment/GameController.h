#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include<iostream>
#include<conio.h>
#include<vector>
#include "CostumMath.h"
#include "Player.h"
#include "Monster.h"
#include "GridManager.h"
#include "console.h"
#include "Bomb.h"

using namespace std;

class Controller
{
private:
	Bomb bomb;

public:
	Controller();

	vector<Monster> mobVector;
	vector<Player> playerVector;

	void movePlayer(Player &, Grid);

	void mobRoaming(Monster &, Player &, Grid grid);
	void mobChasing(Monster &, Player &);
	
	void moveMob(Monster &, Player &, Grid grid);
};

#endif // !GAME_CONTROLLER_H