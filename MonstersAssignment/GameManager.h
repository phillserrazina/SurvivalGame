#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include<iostream>
#include<vector>
#include<conio.h>
#include "GridManager.h"
#include "console.h"
#include "GameController.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

class GameManager
{
private:
	int turnsSurvived;

	int numOfPlayers;
	int numOfMobs;

	int gridWidth;
	int gridHeight;

	int gridX;
	int gridY;

	Grid grid;

	vector<Player> playerVector;
	vector<Monster> mobVector;

	CostumMath gameMath;

public:
	GameManager();

	// Console Visuals
	void setVisualSettings();

	// Menu Functions
	void instructionsMenu();
	void gridOptions();
	void playerOptions();
	void monsterOptions();
	void settingsMenu();
	void mainMenu();

	// Character's Info Managers
	void setPlayersInfo();
	void setMobsInfo();

	// Core Game Functions
	void prepareGame();
	void playGame();
	void gameOver();

	// Game Structure
	void gameLoop();
};

#endif // !GAME_MANAGER_H