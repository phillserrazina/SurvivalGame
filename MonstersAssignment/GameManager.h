#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GameController.h"
#include "PickableBomb.h"

using namespace std;

class GameManager
{
private:
	int turnsSurvived;

	int numOfPlayers;
	int numOfMobs;

	int numOfBombs;

	int gridWidth;
	int gridHeight;

	int gridX;
	int gridY;

	Grid grid;

	Controller controller;

	vector<PickBomb> bombVector;

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
	void dropBombs();

	// Core Game Functions
	void prepareGame();
	void playGame();
	void gameOver();

	// Game Structure
	void gameLoop();
};

#endif // !GAME_MANAGER_H