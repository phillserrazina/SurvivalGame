#include "GameManager.h"

GameManager::GameManager()
{
	turnsSurvived = 0;

	gridWidth = 50;
	gridHeight = 20;

	gridX = 0;
	gridY = 0;

	numOfPlayers = 1;
	numOfMobs = 10;
	numOfBombs = 3;
	numOfManholes = 5;
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
				}
				else if (newValue > 100)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number bettwen 1 and 100");
				}
				else
				{
					gridWidth = newValue;
				}

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				gridOptions();

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
				}
				else if (newValue > 25)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number bettwen 1 and 25");
				}
				else
				{
					gridHeight = newValue;
				}

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				gridOptions();

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
				Console::setColour(Console::YELLOW, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Back";

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

void GameManager::playerOptions()
{
	// Variables

	int keyPressed = 0;

	string newName;
	char newAvatar;

	bool nameSelected = true;
	bool avatarSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display

	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "PLAYER OPTIONS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Player Name: " << Player::playerName << endl;
	cout << "Player Avatar: " << Player::playerAvatar << endl;
	Console::setColour(Console::YELLOW, Console::BLACK);
	cout << endl << "Back";

	while (enterPressed != true)
	{
		// While "Player Name" is selected
		if (nameSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(2, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(2, 0);
			cout << "Player Name:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << Player::playerName;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				nameSelected = false;
				avatarSelected = true;

				// Set colours to default
				Console::setCursorPosition(2, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(2, 0);
				cout << "Player Name: " << Player::playerName;

				break;

				// Enter
			case (13):
				Console::setCursorPosition(2, 13);
				cout << "         ";
				Console::setCursorPosition(2, 13);
				getline(cin, newName);

				if (newName.length() > 20)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That is quite a big name! Please choose a shorter one.");
				}
				else if (newName.length() < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("Please enter a name!");
				}
				else
				{
					Player::playerName = newName;
				}

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				playerOptions();

				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Player Avatar" is selected
		if (avatarSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(3, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(3, 0);
			cout << "Player Avatar:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << Player::playerAvatar;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				avatarSelected = false;
				backSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Player Avatar: " << Player::playerAvatar;

				break;

				// Up Arrow
			case (72):
				avatarSelected = false;
				nameSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Player Avatar: " << Player::playerAvatar;

				break;

			// Enter
			case (13):
				Console::setCursorPosition(3, 15);
				cout << "      ";
				Console::setCursorPosition(3, 15);
				cin >> newAvatar;

				Player::playerAvatar = newAvatar;

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				playerOptions();
				
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
				avatarSelected = true;

				// Set colours to default
				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::YELLOW, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Back";

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

void GameManager::monsterOptions()
{
	// Variables

	int keyPressed = 0;

	int newNumOfMobs;
	char newAvatar;

	bool numOfMobsSelected = true;
	bool avatarSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display

	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "MONSTER OPTIONS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Number Of Monsters: " << numOfMobs << endl;
	cout << "Monster Avatar: " << Monster::monsterAvatar << endl;
	Console::setColour(Console::YELLOW, Console::BLACK);
	cout << endl << "Back";

	while (enterPressed != true)
	{
		// While "Player Name" is selected
		if (numOfMobsSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(2, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(2, 0);
			cout << "Number Of Monsters:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << numOfMobs;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				numOfMobsSelected = false;
				avatarSelected = true;

				// Set colours to default
				Console::setCursorPosition(2, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(2, 0);
				cout << "Number Of Monsters: " << numOfMobs;

				break;

				// Enter
			case (13):
				Console::setCursorPosition(2, 20);
				cout << "         ";
				Console::setCursorPosition(2, 20);
				cin >> newNumOfMobs;

				if (newNumOfMobs > 35)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That is quite a big number! Please choose a shorter one.");
				}
				else if (newNumOfMobs < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("There has to be at least one monster!");
				}
				else
				{
					numOfMobs = newNumOfMobs;
				}

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				monsterOptions();

				break;

			// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}

		// While "Player Avatar" is selected
		if (avatarSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(3, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(3, 0);
			cout << "Monster Avatar:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << Monster::monsterAvatar;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				avatarSelected = false;
				backSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Monster Avatar: " << Monster::monsterAvatar;

				break;

				// Up Arrow
			case (72):
				avatarSelected = false;
				numOfMobsSelected = true;

				// Set colours to default
				Console::setCursorPosition(3, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(3, 0);
				cout << "Monster Avatar: " << Monster::monsterAvatar;

				break;

			// Enter
			case (13):
				Console::setCursorPosition(3, 16);
				cout << "      ";
				Console::setCursorPosition(3, 16);
				cin >> newAvatar;

				Monster::monsterAvatar = newAvatar;

				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				monsterOptions();

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
				avatarSelected = true;

				// Set colours to default
				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::YELLOW, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Back";

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
				enterPressed = true;

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

				playerOptions();
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

				// Enter
			case (13):
				Console::clear();
				Console::setCursorPosition(0, 0);
				enterPressed = true;

				monsterOptions();
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
				enterPressed = true;

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
				enterPressed = true;

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

		// Create a new Player with the given info and a random position
		Player p;
		p.setX(randX);
		p.setY(randY);

		// Push the new player into the Player Vector
		controller.playerVector.push_back(p);
	}
}

void GameManager::setMobsInfo()
{
	for (int i = 1; i <= numOfMobs; i++)
	{
		// Variables
		string mName = "Monster";
		char mAvatar = Monster::monsterAvatar;

		int randX = CostumMath::getRandom(1, grid.getGridWidth());
		int randY = CostumMath::getRandom(1, grid.getGridHeight());

		// Create a new Player with the given info and a random position
		Monster m(mName, mAvatar);
		m.setX(randX);
		m.setY(randY);

		// Push the new player into the Player Vector
		controller.mobVector.push_back(m);
	}
}

void GameManager::dropBombs()
{
	for(int i = 0; i < numOfBombs; i++)
	{
		// Variables

		int randX = CostumMath::getRandom(1, grid.getGridWidth());
		int randY = CostumMath::getRandom(1, grid.getGridHeight());

		// Create a new Player with the given info and a random position
		PickBomb pb;
		pb.setX(randX);
		pb.setY(randY);

		// Push the new player into the Player Vector
		bombVector.push_back(pb);
	}
}

void GameManager::setManholes()
{
	for (int i = 0; i < numOfManholes; i++)
	{
		// Variables

		int randX = CostumMath::getRandom(1, grid.getGridWidth());
		int randY = CostumMath::getRandom(1, grid.getGridHeight());

		// Create a new Player with the given info and a random position
		Manhole mh;
		mh.setX(randX);
		mh.setY(randY);

		// Push the new player into the Player Vector
		holeVector.push_back(mh);
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

	// Set up Monster's info
	setMobsInfo();

	// Set up Pickable Bombs
	dropBombs();

	// Set up Manholes
	setManholes();

	// Now that all the calculations are made, draw the grid
	grid.drawGrid();

	for (int i = 0; i < holeVector.size(); i++)
	{
		Console::setColour(Console::WHITE, Console::BLACK);
		Console::setCursorPosition(holeVector[i].getY(), holeVector[i].getX());
		cout << holeVector[i].getAvatar();
	}

	// Now, let's put pickable bombs in the field
	for (int i = 0; i < bombVector.size(); i++)
	{
		Console::setColour(Console::WHITE, Console::BLACK);
		Console::setCursorPosition(bombVector[i].getY(), bombVector[i].getX());
		cout << bombVector[i].getAvatar();
	}

	// After the grid and bombs, draw the monsters
	for (int i = 0; i < controller.mobVector.size(); i++)
	{
		Console::setColour(Console::GREEN, Console::BLACK);
		Console::setCursorPosition(controller.mobVector[i].getY(), controller.mobVector[i].getX());
		cout << controller.mobVector[i].getAvatar();
	}

	// Once that all the monsters have been drawn, draw the player
	for (int i = 0; i < controller.playerVector.size(); i++)
	{
		Console::setColour(Console::WHITE, Console::BLACK);
		Console::setCursorPosition(controller.playerVector[i].getY(), controller.playerVector[i].getX());
		cout << controller.playerVector[i].getAvatar();
	}
}

void GameManager::playGame()
{
	// Variables

	bool gameOver = false;

	// GAME LOOP
	while (gameOver != true)
	{
		Console::setCursorPosition(grid.getGridHeight() + 2, 0);
		Console::setColour(Console::WHITE, Console::BLACK);
		cout << "Bombs: " << controller.getPlayerBombs();

		// Move the Player
		for (int i = 0; i < controller.playerVector.size(); i++)
		{
			controller.movePlayer(controller.playerVector[i], grid);

			// Bomb Pickup Handler
			for (int j = 0; j < bombVector.size(); j++)
			{
				// Draw any existing bombs
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(bombVector[j].getY(), bombVector[j].getX());
				cout << bombVector[j].getAvatar();

				// Check if the player touches any bomb
				if (controller.playerVector[i].getX() == bombVector[j].getX() &&
					controller.playerVector[i].getY() == bombVector[j].getY())
				{
					// If he does, delete the bomb
					bombVector.erase(bombVector.begin() + j);

					// And add it to the Player's inventory
					controller.setPlayerBombs(controller.getPlayerBombs() + 1);
				}
			}

			// Move the monsters
			for (int j = 0; j < controller.mobVector.size(); j++)
			{
				// If the monster is alive
				if (controller.mobVector[j].getDead() != true)
				{
					controller.moveMob(controller.mobVector[j], controller.playerVector[i], grid);

					// If the monster touches the player
					if ((controller.mobVector[j].getX() == controller.playerVector[i].getX()) &&
						((controller.mobVector[j].getY() == controller.playerVector[i].getY())))
					{
						gameOver = true;
					}

					// If the monster touches the bomb
					if ((controller.mobVector[j].getX() == controller.getBomb().getX()) &&
						((controller.mobVector[j].getY() == controller.getBomb().getY())))
					{
						controller.getBomb().setTimer(0);
						controller.getBomb().boomBomb(controller.mobVector, controller.playerVector[i]);
					}

					// If the monster steps on a manhole
					for (int k = 0; k < holeVector.size(); k++)
					{
						if ((controller.mobVector[j].getX() == holeVector[k].getX()) && 
							(controller.mobVector[j].getY() == holeVector[k].getY()))
						{
							controller.mobVector[j].setDead(true);

							holeVector.erase(holeVector.begin() + k);
						}
					}
					
				}

				// If the monster is dead
				else if(controller.mobVector[j].getDead() == true)
				{
					Console::setCursorPosition(controller.mobVector[j].getY(), controller.mobVector[j].getX());
					cout << " ";
					controller.mobVector.erase(controller.mobVector.begin() + j);
				}
			}

			// If the player steps on a manhole
			for (int j = 0; j < holeVector.size(); j++)
			{
				if ((controller.playerVector[i].getX() == holeVector[j].getX()) &&
					(controller.playerVector[i].getY() == holeVector[j].getY()))
				{
					gameOver = true;
				}
			}

			turnsSurvived++;

			if (controller.mobVector.empty())
			{
				gameOver = true;
			}
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

	double base = 1.05;
	int finalScore = 0;
	bool exitResults = false;

	// Reset Player Vector for the next game
	while (!controller.playerVector.empty())
	{
		controller.playerVector.pop_back();
	}

	// Reset Mob Vector for the next game
	while (!controller.mobVector.empty())
	{
		controller.mobVector.pop_back();
		counter++;
	}

	// Reset Bomb Vector for the next game
	while (!bombVector.empty())
	{
		bombVector.pop_back();
	}

	// Reset Hole Vector for the next game
	while (!holeVector.empty())
	{
		holeVector.pop_back();
	}

	// Get how many monsters were killed
	killCount = numOfMobs - counter;

	finalScore = (static_cast<int>(CostumMath::getPower(base, (turnResult / 2)) + killCount));

	Console::setCursorPosition(0, 0);
	Console::setColour(Console::WHITE, Console::RED);
	cout << "GAME OVER" << endl;
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << endl << "Results:" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << "SCORE: " << finalScore << endl;
	cout << "MONSTERS KILLED: " << killCount << endl;
	cout << "TURNS SURVIVED: " << turnsSurvived << endl;

	// Reset stats for the next game
	turnsSurvived = 0;
	finalScore = 0;
	controller.setPlayerBombs(0);

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