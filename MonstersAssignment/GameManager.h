#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include<fstream>
#include "GameController.h"
#include "PickableBomb.h"
#include "Manhole.h"

using namespace std;

class GameManager
{
private:
	int turnsSurvived;

	int numOfPlayers;
	int numOfMobs;

	int numOfBombs;
	int numOfManholes;

	int gridWidth;
	int gridHeight;

	int gridX;
	int gridY;

	bool gameWon;
	bool gameLost;

	std::string deathReason;

	Grid grid;

	Controller controller;

	vector<PickBomb> bombVector;
	vector<Manhole> holeVector;

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
	void setManholes();

	// Core Game Functions
	void prepareGame();
	void playGame();
	void gameOver();
	void winGame();

	// Game Structure
	void gameLoop();
};

#endif // !GAME_MANAGER_H