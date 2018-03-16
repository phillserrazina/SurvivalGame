#include "GameManager.h"

GameManager::GameManager()
{
	turnsSurvived = 0;

	gridWidth = 50;
	gridHeight = 20;

	gridX = 0;
	gridY = 0;

	numOfPlayers = 1;
	numOfMobs = 5;
}

void GameManager::setVisualSettings()
{
	Console::setWindowTitle("Console Monster Escape");		// Set Window Title
	Console::setTextBufferSize(30, 110);					// Set Console Size
	Console::setWindowPosition(200, 450);					// Set Console Position
	Console::setColour(Console::WHITE, Console::BLACK);		// Set background colour to white and text colour to black.
	Console::clear();
}

void GameManager::instructionsMenu()
{
	// Variables

	int keyPressed = 0;

	bool enterPressed = false;

	// Menu Display
	cout << "**Instructions**" << endl;
	Console::setCursorPosition(10, 0);
	Console::setColour(Console::BLACK, Console::RED);
	cout << "Back";
	Console::setColour(Console::WHITE, Console::BLACK);

	while (enterPressed != true)
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		// If "Enter" is pressed
		case (13):
			Console::clear();
			Console::setCursorPosition(0, 0);
			enterPressed = true;

			mainMenu();
			break;

			// Invalid Input
		default:
			break;
		}
	}
}

void GameManager::gridOptions()
{
	// Variables

	int keyPressed = 0;

	int newValue = 0;

	bool widthSelected = true;
	bool heightSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display

	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "GRID OPTIONS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Grid Width: " << gridWidth << endl;
	cout << "Grid Height: " << gridHeight << endl;
	Console::setColour(Console::YELLOW, Console::BLACK);
	cout << endl << "Back";

	while (enterPressed != true)
	{
		// While "Grid Width" is selected
		if (widthSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(2, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(2, 0);
			cout << "Grid Width:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << gridWidth;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
			// Down Arrow
			case (80):
				widthSelected = false;
				heightSelected = true;

				// Set colours to default
				Console::setCursorPosition(2, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(2, 0);
				cout << "Grid Width: " << gridWidth;

				break;

			// Enter
			case (13):
				Console::setCursorPosition(2, 12);
				cout << "      ";
				Console::setCursorPosition(2, 12);
				cin >> newValue;

				if (newValue < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number bettwen 1 and 100");

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				else if (newValue > 100)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number bettwen 1 and 100");

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				else
				{
					gridWidth = newValue;

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Grid Height" is selected
		if (heightSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(3, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(3, 0);
			cout << "Grid Height:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << gridHeight;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
			// Down Arrow
			case (80):
				heightSelected = false;
				backSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Grid Height: " << gridHeight;

				break;

			// Up Arrow
			case (72):
				heightSelected = false;
				widthSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Grid Height: " << gridHeight;

				break;

			// Enter
			case (13):
				Console::setCursorPosition(3, 13);
				cout << "      ";
				Console::setCursorPosition(3, 13);
				cin >> newValue;

				if (newValue < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number bettwen 1 and 50");

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				else if (newValue > 25)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number bettwen 1 and 25");

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				else
				{
					gridHeight = newValue;

					Console::clear();
					Console::setCursorPosition(0, 0);

					gridOptions();
				}
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Back" is selected
		if (backSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(5, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(5, 0);
			cout << "Back";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				backSelected = false;
				heightSelected = true;

				// Set colours to default
				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Back" << gridWidth;

				break;

				// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				settingsMenu();
				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}
	}
}

// TODO:
void GameManager::playerOptions()
{

}

// TODO:
void GameManager::monsterOptions()
{

}

void GameManager::settingsMenu()
{
	// Variables

	int keyPressed = 0;

	bool gridSelected = true;
	bool playerSelected = false;
	bool monsterSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "SETTINGS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Grid Options" << endl;
	cout << "Player Options" << endl;
	cout << "Monster Options" << endl;
	Console::setColour(Console::YELLOW, Console::BLACK);
	cout << endl << "Back";

	while (enterPressed != true)
	{
		// While "Grid Options" is selected
		if (gridSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(2, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(2, 0);
			cout << "Grid Options";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Down Arrow
			case (80):
				gridSelected = false;
				playerSelected = true;

				// Set colours to default
				Console::setCursorPosition(2, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(2, 0);
				cout << "Grid Options";

				break;

			// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);

				gridOptions();
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Player Options" is selected
		if (playerSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(3, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(3, 0);
			cout << "Player Options";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				playerSelected = false;
				gridSelected = true;

				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Player Options";

				break;

			// Down Arrow
			case (80):
				playerSelected = false;
				monsterSelected = true;

				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Player Options";

				break;

			// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				// Player Options Menu
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Monster Options" is selected
		if (monsterSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(4, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(4, 0);
			cout << "Monster Options";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				monsterSelected = false;
				playerSelected = true;

				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Monster Options";

				break;

			// Down Arrow
			case (80):
				monsterSelected = false;
				backSelected = true;

				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Monster Options";

				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Back" is selected
		if (backSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(6, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(6, 0);
			cout << "Back";
			Console::setColour(Console::WHITE, Console::BLACK);			

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				backSelected = false;
				monsterSelected = true;

				Console::setCursorPosition(6, 0);
				cout << "                   ";
				Console::setColour(Console::YELLOW, Console::BLACK);
				Console::setCursorPosition(6, 0);
				cout << "Back";

				break;

			// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				mainMenu();
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}
	}
}

void GameManager::mainMenu()
{
	// Variables

	int keyPressed = 0;

	bool playSelected = true;
	bool instSelected = false;
	bool settSelected = false;
	bool quitSelected = false;

	bool enterPressed = false;

	// Menu Display 

	cout << "MONSTER ESCAPE" << endl;

	cout << endl << "Start Game" << endl;
	cout << "Instructions" << endl;
	cout << "Settings" << endl;
	cout << "Quit";

	while (enterPressed != true)
	{
		// While "Play Game" is selected
		if (playSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(2, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(2, 0);
			cout << "Start Game";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Down Arrow
			case (80):
				playSelected = false;
				instSelected = true;

				// Set colours to default
				Console::setCursorPosition(2, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(2, 0);
				cout << "Start Game";

				break;

			// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);

				gameLoop();
				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Instructions" is selected
		if (instSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(3, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(3, 0);
			cout << "Instructions";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				instSelected = false;
				playSelected = true;

				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Instructions";

				break;

			// Down Arrow
			case (80):
				instSelected = false;
				settSelected = true;

				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Instructions";

				break;

			// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				instructionsMenu();
				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Settings" is selected
		if (settSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(4, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(4, 0);
			cout << "Settings";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
				// Up Arrow
			case (72):
				settSelected = false;
				instSelected = true;

				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Settings";

				break;

				// Down Arrow
			case (80):
				settSelected = false;
				quitSelected = true;

				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Settings";

				break;

			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);

				settingsMenu();
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Quit" is selected
		if (quitSelected == true)
		{
			// Highlight selected option
			Console::setCursorPosition(5, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(5, 0);
			cout << "Quit";
			Console::setColour(Console::WHITE, Console::BLACK);

			// Wait for input
			keyPressed = _getch();

			// Input response
			switch (keyPressed)
			{
			// Up Arrow
			case (72):
				quitSelected = false;
				settSelected = true;

				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Quit";

				break;

			// Enter
			case (13):
				enterPressed = true;
				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}
	}
}

void GameManager::setPlayersInfo()
{
	for (int i = 1; i <= numOfPlayers; i++)
	{
		CostumMath math;

		// Variables
		string pName;
		char pAvatar;

		int randX = math.getRandom(1, grid.getGridWidth());
		int randY = math.getRandom(1, grid.getGridHeight());

		// Ask the user for the Player's name and avatar
		cout << "What is the Player's name?" << endl;
		cin >> pName;
		cout << endl << "What is the Player's avatar?" << endl;
		cin >> pAvatar;

		// Create a new Player with the given info and a random position
		Player p(pName, pAvatar);
		p.setX(randX);
		p.setY(randY);

		// Push the new player into the Player Vector
		playerVector.push_back(p);
	}
}

void GameManager::setMobsInfo()
{
	for (int i = 1; i <= numOfMobs; i++)
	{
		// Variables
		string mName = "Monster";
		char mAvatar = 'M';

		int randX = CostumMath::getRandom(1, grid.getGridWidth());
		int randY = CostumMath::getRandom(1, grid.getGridHeight());

		// Create a new Player with the given info and a random position
		Monster m(mName, mAvatar);
		m.setX(randX);
		m.setY(randY);

		// Push the new player into the Player Vector
		mobVector.push_back(m);
	}
}

void GameManager::prepareGame()
{
	// Set grid info beforehand to make Player and Monster 
	// boundary calculations easier.
	grid.setGridHeight(gridHeight);
	grid.setGridWidth(gridWidth);

	grid.setGridStartX(gridX);
	grid.setGridStartY(gridY);

	// Set up Player's info
	setPlayersInfo();
	Console::clear();

	// Set up Monster's info
	setMobsInfo();
	Console::clear();

	// Now that all the calculations are made, draw the grid
	grid.drawGrid();

	// After the grid, draw the monsters
	for (int i = 0; i < mobVector.size(); i++)
	{
		Console::setColour(Console::GREEN, Console::BLACK);
		Console::setCursorPosition(mobVector[i].getY(), mobVector[i].getX());
		cout << mobVector[i].getAvatar();
	}

	// Once that all the monsters have been drawn, draw the player
	for (int i = 0; i < playerVector.size(); i++)
	{
		Console::setColour(Console::WHITE, Console::BLACK);
		Console::setCursorPosition(playerVector[i].getY(), playerVector[i].getX());
		cout << playerVector[i].getAvatar();
	}
}

void GameManager::playGame()
{
	// Variables

	Controller controller;

	bool gameOver = false;

	// GAME LOOP
	while (gameOver != true)
	{
		// Update the Controller Vectors
		controller.setMobVec(&mobVector);
		controller.setPlayerVec(&playerVector);

		// Move the Player
		for (int i = 0; i < playerVector.size(); i++)
		{
			controller.movePlayer(playerVector[i], grid);

			// Move the monsters
			for (int j = 0; j < mobVector.size(); j++)
			{
				controller.moveMob(mobVector[j], playerVector[i], grid);

				// If the monster touches the player
				if ((mobVector[j].getX() == playerVector[i].getX()) &&
					((mobVector[j].getY() == playerVector[i].getY())))
				{
					gameOver = true;
				}
			}

			turnsSurvived++;
		}
	}
}

void GameManager::gameOver()
{
	// Variables

	int keyPressed = 0;
	int counter = 0;
	int killCount = 0;
	int turnResult = turnsSurvived;

	if (turnsSurvived % 2 != 0)
	{
		turnResult = turnsSurvived - 1;
	}

	double exponent = 2;
	int finalScore = 0;
	bool exitResults = false;

	// Reset Player Vector for the next game
	while (!playerVector.empty())
	{
		playerVector.pop_back();
	}

	// Reset Mob Vector for the next game
	while (!mobVector.empty())
	{
		mobVector.pop_back();
		counter++;
	}

	// Get how many monsters were killed
	killCount = numOfMobs - counter;

	finalScore = (static_cast<int>(CostumMath::getPower((turnResult), exponent)) + killCount);

	Console::setCursorPosition(0, 0);
	Console::setColour(Console::WHITE, Console::RED);
	cout << "GAME OVER" << endl;
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << endl << "Results:" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << "SCORE: " << finalScore << endl;
	cout << "MONSTERS KILLED: " << killCount << endl;
	cout << "TURNS SURVIVED: " << turnsSurvived << endl;

	while (exitResults != true)
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case (13):
			Console::clear();
			Console::setCursorPosition(0, 0);
			exitResults = true;

			mainMenu();
			break;

		default:
			break;
		}
	}
}

void GameManager::gameLoop()
{
	prepareGame();
	playGame();
	Console::clear();
	gameOver();
}