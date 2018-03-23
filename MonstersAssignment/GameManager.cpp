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

	gameWon = false;
	gameLost = false;
}

/* 
Function that prepares the visual settings of the console such as the
window title, the window size and position and the colour of the initial
text.
*/
void GameManager::setVisualSettings()
{
	Console::setWindowTitle("Console Monster Escape");		// Set Window Title
	Console::setTextBufferSize(30, 110);					// Set Console Size
	Console::setWindowPosition(200, 450);					// Set Console Position
	Console::setColour(Console::WHITE, Console::BLACK);		// Set background colour to white and text colour to black.
	Console::clear();
}

/*
Function that displays the instructions menu and handles the input
to return to the settings menu.
*/
void GameManager::instructionsMenu()
{
	// Variables

	int keyPressed = 0;

	bool enterPressed = false;

	// Menu Display
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "INSTRUCTIONS" << endl << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << "The objective of this game is to survive as long as possible and kill as " << endl;
	cout << "many monsters as you.                                                    " << endl;
	cout << "To move, the player can press WASD or the arrow keys. The monsters won't " << endl;
	cout << "move until the player chooses what they want to do.                      " << endl;
	cout << "By default, the player will be represented by a '@' and the monsters will" << endl;
	cout << "be represented by a 'M'. This can be changed in the settings, in Player  " << endl;
	cout << "and Monster Options.                                                     " << endl;
	cout << "To help the player, there will be bombs that can be picked up and planted" << endl;
	cout << "by pressing B on the keyboard. Bombs will take 3 turns to explode.       " << endl;
	cout << "There will also be traps where both monsters and players can fall in.    " << endl;
	cout << "By default, pickable bombs are represented by a '+' and traps are        " << endl;
	cout << "represented by a 'O'. These can also be changed in the setting, in grid  " << endl;
	cout << "options.";

	Console::setCursorPosition(16, 0);
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

/*
Function that displays the Grid Options Menu and handles the input
to select the various options.
*/
void GameManager::gridOptions()
{
	// Variables

	int keyPressed = 0;

	int newValue = 0;

	bool widthSelected = true;
	bool heightSelected = false;
	bool manholeSelected = false;
	bool bombSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display

	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "GRID OPTIONS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Grid Width: " << gridWidth << endl;
	cout << "Grid Height: " << gridHeight << endl;
	cout << "Number of Traps: " << numOfManholes << endl;
	cout << "Number of Bombs: " << numOfBombs << endl;
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

				if (newValue < 20)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number between 20 and 100");
				}
				else if (newValue > 100)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number between 20 and 100");
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
				manholeSelected = true;

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

				if (newValue < 10)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number between 10 and 25");
				}
				else if (newValue > 25)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number between 10 and 25");
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

		// While "Number of Traps" is selected
		if (manholeSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(4, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(4, 0);
			cout << "Number of Traps:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << numOfManholes;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				manholeSelected = false;
				bombSelected = true;

				// Set colours to default
				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Number of Traps: " << numOfManholes;

				break;

				// Up Arrow
			case (72):
				manholeSelected = false;
				heightSelected = true;

				// Set colours to default
				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Number of Traps: " << numOfManholes;

				break;

				// Enter
			case (13):
				Console::setCursorPosition(4, 17);
				cout << "      ";
				Console::setCursorPosition(4, 17);
				cin >> newValue;

				if (newValue > 15)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number between 1 and 15");
				}
				else if (newValue < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number between 1 and 15");
				}
				else
				{
					numOfManholes = newValue;
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

		// While "Number of Traps" is selected
		if (bombSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(5, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(5, 0);
			cout << "Number of Bombs:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << numOfBombs;

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
				// Down Arrow
			case (80):
				bombSelected = false;
				backSelected = true;

				// Set colours to default
				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Number of Bombs: " << numOfBombs;

				break;

				// Up Arrow
			case (72):
				bombSelected = false;
				manholeSelected = true;

				// Set colours to default
				Console::setCursorPosition(5, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(5, 0);
				cout << "Number of Bombs: " << numOfBombs;

				break;

				// Enter
			case (13):
				Console::setCursorPosition(5, 17);
				cout << "      ";
				Console::setCursorPosition(5, 17);
				cin >> newValue;

				if (newValue > 10)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too big! Please give me a number between 1 and 10");
				}
				else if (newValue < 1)
				{
					Console::clear();
					Console::setCursorPosition(0, 0);

					Console::pause("That value is too small! Please give me a number between 1 and 10");
				}
				else
				{
					numOfBombs = newValue;
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
			Console::setCursorPosition(7, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(7, 0);
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
				bombSelected = true;

				// Set colours to default
				Console::setCursorPosition(7, 0);
				cout << "                   ";
				Console::setColour(Console::YELLOW, Console::BLACK);
				Console::setCursorPosition(7, 0);
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

/*
Function that displays the Player Options Menu and handles the input
to select the various options.
*/
void GameManager::playerOptions()
{
	// Variables

	int keyPressed = 0;

	string newName;
	char newAvatar;
	int newValue;

	bool nameSelected = true;
	bool avatarSelected = false;
	bool bombSelected = false;
	bool backSelected = false;

	bool enterPressed = false;

	// Menu Display

	Console::setColour(Console::AQUA, Console::BLACK);
	cout << "PLAYER OPTIONS" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << endl << "Player Name: " << Player::playerName << endl;
	cout << "Player Avatar: " << Player::playerAvatar << endl;
	cout << "Starting Bombs: " << controller.getPlayerBombs() << endl;
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
				bombSelected = true;

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

		// While "Starting Bombs" is selected
		if (bombSelected == true)
		{
			// Highlight Selected Option
			Console::setCursorPosition(4, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(4, 0);
			cout << "Starting Bombs:";
			Console::setColour(Console::WHITE, Console::BLACK);
			cout << " " << controller.getPlayerBombs();

			// Wait for input
			keyPressed = _getch();

			// Input Response
			switch (keyPressed)
			{
			// Down Arrow
			case (80):
				bombSelected = false;
				backSelected = true;

				// Set colours to default
				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Starting Bombs: " << controller.getPlayerBombs();

				break;

			// Up Arrow
			case (72):
				bombSelected = false;
				avatarSelected = true;

				// Set colours to default
				Console::setCursorPosition(4, 0);
				cout << "                   ";
				Console::setColour(Console::WHITE, Console::BLACK);
				Console::setCursorPosition(4, 0);
				cout << "Starting Bombs: " << controller.getPlayerBombs();

				break;

				// Enter
			case (13):
				Console::setCursorPosition(4, 16);
				cout << "      ";
				Console::setCursorPosition(4, 16);
				cin >> newValue;

				controller.setPlayerBombs(newValue);

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
			Console::setCursorPosition(6, 0);
			cout << "                   ";
			Console::setColour(Console::BLACK, Console::RED);
			Console::setCursorPosition(6, 0);
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
				bombSelected = true;

				// Set colours to default
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

				settingsMenu();
				break;

				// If an arrow is not pressed, nothing happens
			default:
				break;
			}
		}
	}
}

/*
Function that displays the Monster Options Menu and handles the input
to select the various options.
*/
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

/*
Function that displays the Settings Menu and handles the input
to select the various options.
*/
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

/*
Function that displays the Main Menu and handles the input
to select the various options.
*/
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

/*
Function that prepares the player for the game with the information
given such as the Player's name and avatar. It also gives the player
a random position to start the game in.
*/
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

/*
Function that prepares the monsters for the game with the information
given such as the Monsters' name and avatar. It also gives the monsters
a random position to start the game in.
*/
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

/*
Function that prepares the pickable bombs for the game by giving them
a random position.
*/
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

/*
Function that prepares the traps for the game by giving them
a random position.
*/
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

/*
Function that uses all of the previous functions to set up the information
that the game needs. It also displays the grid and all the initial objects.
*/
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

/*
Function that handles the core of the game.
*/
void GameManager::playGame()
{
	// Variables

	bool gameOver = false;

	// GAME LOOP
	while (gameOver != true)
	{
		// Display how many bombs the players has
		Console::setColour(Console::WHITE, Console::BLACK);
		Console::setCursorPosition(grid.getGridHeight() + 2, 0);
		cout << "Bombs: " << controller.getPlayerBombs();

		for (int i = 0; i < controller.playerVector.size(); i++)
		{
			// Move the Player
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

			for (int j = 0; j < controller.mobVector.size(); j++)
			{
				// If the monster is alive
				if (controller.mobVector[j].getDead() != true)
				{
					// Move it
					controller.moveMob(controller.mobVector[j], controller.playerVector[i], grid);

					// If the monster touches the player
					if ((controller.mobVector[j].getX() == controller.playerVector[i].getX()) &&
						((controller.mobVector[j].getY() == controller.playerVector[i].getY())))
					{
						// The player dies, trigger the end of the game
						gameOver = true;
						gameLost = true;

						deathReason = "got caught by a nasty Monster!";
					}

					// If the monster touches the bomb
					if ((controller.mobVector[j].getX() == controller.getBomb().getX()) &&
						((controller.mobVector[j].getY() == controller.getBomb().getY())))
					{
						// Explode the bomb
						controller.getBomb().setTimer(0);
						controller.getBomb().boomBomb(controller.mobVector, controller.playerVector[i]);
					}

					// If the monster steps on a manhole
					for (int k = 0; k < holeVector.size(); k++)
					{
						if ((controller.mobVector[j].getX() == holeVector[k].getX()) && 
							(controller.mobVector[j].getY() == holeVector[k].getY()))
						{
							// Kill the monster
							controller.mobVector[j].setDead(true);

							// Get rid of the manhole
							holeVector.erase(holeVector.begin() + k);
						}
					}
					
				}

				// If the monster is dead
				else if(controller.mobVector[j].getDead() == true)
				{
					// Delete it from the monster vector
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
					gameLost = true;

					deathReason = "fell on a Trap!";
				}
			}

			// Increment the "Survived Turns" counter
			turnsSurvived++;

			// If all the monsters are dead, the player wins, trigger the end of the game
			if (controller.mobVector.empty())
			{
				gameOver = true;
				gameWon = true;
			}
		}
	}
}

/*
Function that handles the Game Over screen.
*/
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

	fstream logFile("gameLog.txt", ios::app);

	// Reset Mob Vector for the next game
	while (!controller.mobVector.empty())
	{
		controller.mobVector.pop_back();
		counter++;
	}

	// Get how many monsters were killed
	killCount = numOfMobs - counter;

	if (deathReason == "fell on a Trap!")
	{
		killCount -= 1;
	}

	finalScore = (static_cast<int>(turnsSurvived / 3) + killCount);

	Console::setCursorPosition(0, 0);
	Console::setColour(Console::WHITE, Console::RED);
	cout << "GAME OVER" << endl;
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << endl << "Results:" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << "SCORE: " << finalScore << endl;
	cout << "MONSTERS KILLED: " << killCount << endl;
	cout << "TURNS SURVIVED: " << turnsSurvived << endl;

	// Register results in a log file
	logFile << controller.playerVector[0].getName() << " survived for " << turnsSurvived << " turns but eventually " << deathReason << "... Final Score: " << finalScore << endl;

	// Reset stats for the next game
	turnsSurvived = 0;
	finalScore = 0;
	gameWon = false;
	gameLost = false;
	controller.setPlayerBombs(0);

	// Reset Player Vector for the next game
	while (!controller.playerVector.empty())
	{
		controller.playerVector.pop_back();
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

/*
Function that handles the Win Screen.
*/
void GameManager::winGame()
{
	// Variables

	int keyPressed = 0;
	int counter = 0;
	int killCount = 0;
	int winBonus = 50;
	int turnResult = turnsSurvived;

	if (turnsSurvived % 2 != 0)
	{
		turnResult = turnsSurvived - 1;
	}

	double base = 1.05;
	int finalScore = 0;
	bool exitResults = false;

	fstream logFile("gameLog.txt", ios::app);

	// Reset Mob Vector for the next game
	while (!controller.mobVector.empty())
	{
		controller.mobVector.pop_back();
		counter++;
	}

	// Get how many monsters were killed
	killCount = numOfMobs - counter;

	finalScore = (static_cast<int>(turnsSurvived / 3) + killCount + winBonus);

	Console::setCursorPosition(0, 0);
	Console::setColour(Console::WHITE, Console::GREEN);
	cout << "YOU WON!" << endl;
	Console::setColour(Console::AQUA, Console::BLACK);
	cout << endl << "Results:" << endl;
	Console::setColour(Console::WHITE, Console::BLACK);
	cout << "SCORE: " << finalScore << endl;
	cout << "MONSTERS KILLED: " << killCount << endl;
	cout << "TURNS SURVIVED: " << turnsSurvived << endl;

	// Register results in a log file
	logFile << controller.playerVector[0].getName() << " won the game by killing " << killCount << " monsters in a mere " << turnsSurvived << " turns! Final Score: " << finalScore << endl;

	// Reset stats for the next game
	turnsSurvived = 0;
	finalScore = 0;
	gameWon = false;
	gameLost = false;
	controller.setPlayerBombs(0);

	// Reset Player Vector for the next game
	while (!controller.playerVector.empty())
	{
		controller.playerVector.pop_back();
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

/*
Function that compacts the "prepareGame", "playGame" and "gameOver"/"winGame"
functions.
*/
void GameManager::gameLoop()
{
	prepareGame();
	playGame();
	Console::clear();
	if (gameWon == true)
	{
		winGame();
	}
	else if (gameLost == true)
	{
		gameOver();
	}
}