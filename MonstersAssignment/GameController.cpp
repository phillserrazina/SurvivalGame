#include "GameController.h"

Controller::Controller()
{
	playerBombs = 0;
}

Bomb Controller::getBomb()
{
	return bomb;
}

void Controller::setPlayerBombs(int i)
{
	playerBombs = i;
}

int Controller::getPlayerBombs()
{
	return playerBombs;
}

/*
	"movePlayer" Function controlls input necessary to move the player:
	a = left;
	d = right;
	w = up;
	s = down;
	Anything else, triggers the function again, forcing the user to insert valid input.
*/

void Controller::movePlayer(Player &player, Grid grid)
{
	// Variables

	int lastX = player.getX();
	int lastY = player.getY();

	char input = _getch();

	// Make all input lowercase
	input = tolower(input);

	switch (input)
	{
	// Move Left
	case 'a':
		if (lastX != 1)
		{
			player.setX(player.getX() - 1);
		}
			
		break;

	// Move Right
	case 'd':
		if (lastX != (grid.getGridWidth() - 1))
		{
			player.setX(player.getX() + 1);
		}
			
		break;

	// Move Up
	case 'w':
		if (lastY != 1)
		{
			player.setY(player.getY() - 1);
		}
			
		break;
	
	// Move Down
	case 's':
		if (lastY != grid.getGridHeight() - 1)
		{
			player.setY(player.getY() + 1);
		}
			
		break;

	case 'b':
		// If the player has any bombs and presses 'b', place one
		if (playerBombs > 0)
		{
			if (bomb.getBombPlaced() == false)
			{
				bomb.setX(player.getX());
				bomb.setY(player.getY());
			}

			bomb.setBombPlaced(true);

			playerBombs--;
		}
		
		break;

	// Detect Arrows
	default:
		
		switch (int keyPressed = _getch())
		{
		// Up Arrow
		case (72):
			if (lastY != 1)
			{
				player.setY(player.getY() - 1);
			}

			break;

		// Down Arrow
		case (80):
			if (lastY != grid.getGridHeight() - 1)
			{
				player.setY(player.getY() + 1);
			}

			break;

		// Left Arrow
		case (75):
			if (lastX != 1)
			{
				player.setX(player.getX() - 1);
			}

			break;

		// Right Arrow
		case (77):
			if (lastX != (grid.getGridWidth() - 1))
			{
				player.setX(player.getX() + 1);
			}

			break;

		// Invalid Input
		default:
			movePlayer(player, grid);
			break;
		}
	}

	// Erase previous position's avatar
	Console::setCursorPosition(lastY, lastX);
	std::cout << " ";

	// Draw avatar on new position
	Console::setColour(Console::WHITE, Console::BLACK);
	Console::setCursorPosition(player.getY(), player.getX());
	std::cout << player.getAvatar();
	
	if (bomb.getBombPlaced() == true)
	{
		bomb.boomBomb(mobVector, player);

		Console::setCursorPosition(bomb.getY(), bomb.getX());
		cout << bomb.getAvatar();
	}
	if (bomb.getBombPlaced() == false)
	{
		Console::setCursorPosition(bomb.getY(), bomb.getX());
		cout << " ";
		bomb.setX(105);
		bomb.setY(1);
	}
}

/*
	"mobRoaming" handles the Monster AI when the designated monster is in
	the ROAMING state. When in this state, the monster takes a random 
	direction and walks 1 unit towards it.
*/
void Controller::mobRoaming(Monster &mob, Player &player, Grid grid)
{
	int distFromMobToPlayer = CostumMath::getVectorLenght(mob.getX(), mob.getY(), 
														  player.getX(), player.getY());

	int lastX = mob.getX();
	int lastY = mob.getY();

	int randNum = CostumMath::getRandom(1, 5);

	switch (randNum)
	{
	// Move Left
	case (1):
		if (lastX != 1)
		{
			mob.setX(mob.getX() - 1);
		}
			
		break;

	// Move Right
	case (2):
		if (lastX != (grid.getGridWidth() - 1))
		{
			mob.setX(mob.getX() + 1);
		}
			
		break;

	// Move Up
	case (3):
		if (lastY != 1)
		{
			mob.setY(mob.getY() - 1);
		}
			
		break;

	// Move Down
	case (4):
		if (lastY != grid.getGridHeight() - 1)
		{
			mob.setY(mob.getY() + 1);
		}
			
		break;
	}

	if (mob.getChasingCooldown() == 0)
	{
		// If the Player is in the vision field, CHASE HIM!
		if (distFromMobToPlayer <= mob.getVisionRange())
		{
			mob.setState(mob.CHASING);
		}
		
		mob.setChasingCooldown(5);
	}
	else
	{
		mob.setChasingCooldown(mob.getChasingCooldown() - 1);
	}
	

	// Erase previous position's avatar
	Console::setCursorPosition(lastY, lastX);
	std::cout << " ";

	// Draw avatar on new position
	Console::setColour(Console::GREEN, Console::BLACK);
	Console::setCursorPosition(mob.getY(), mob.getX());
	std::cout << mob.getAvatar();
}

/*
	"mobChasing" handles the Monster AI when the designated monster is in
	 the CHASING state. When in this state, the monster moves towards the
	 player.
*/
void Controller::mobChasing(Monster &mob, Player &player)
{
	// Variables

	int lastX = mob.getX();
	int lastY = mob.getY();

	// If player is WEST, move to the left
	if ((player.getX() < mob.getX()) && (player.getY() == mob.getY()))
	{
		mob.setX(mob.getX() - 1);
	}

	// If player is EAST, move to the left
	if ((player.getX() > mob.getX()) && (player.getY() == mob.getY()))
	{
		mob.setX(mob.getX() + 1);
	}

	// If player is NORTH, move up
	if ((player.getX() == mob.getX()) && (player.getY() < mob.getY()))
	{
		mob.setY(mob.getY() - 1);
	}

	// If player is SOUTH, move down
	if ((player.getX() == mob.getX()) && (player.getY() > mob.getY()))
	{
		mob.setY(mob.getY() + 1);
	}

	// If player is NORTHWEST, move up or left
	if ((player.getX() < mob.getX()) && (player.getY() < mob.getY()))
	{
		int rand = CostumMath::getRandom(1, 100);

		if (rand <= 50)
		{
			mob.setX(mob.getX() - 1);
		}
		else
		{
			mob.setY(mob.getY() - 1);
		}
	}

	// If player is NORTHEAST, move up or right
	if ((player.getX() > mob.getX()) && (player.getY() < mob.getY()))
	{
		int rand = CostumMath::getRandom(1, 100);

		if (rand <= 50)
		{
			mob.setX(mob.getX() + 1);
		}
		else
		{
			mob.setY(mob.getY() - 1);
		}
	}

	// If player is SOUTHEAST, move down or right
	if ((player.getX() > mob.getX()) && (player.getY() > mob.getY()))
	{
		int rand = CostumMath::getRandom(1, 100);

		if (rand <= 50)
		{
			mob.setX(mob.getX() + 1);
		}
		else
		{
			mob.setY(mob.getY() + 1);
		}
	}

	// If player is SOUTHWEST, move down or left
	if ((player.getX() < mob.getX()) && (player.getY() > mob.getY()))
	{
		int rand = CostumMath::getRandom(1, 100);

		if (rand <= 50)
		{
			mob.setX(mob.getX() - 1);
		}
		else
		{
			mob.setY(mob.getY() + 1);
		}
	}

	// Erase previous position's avatar
	Console::setCursorPosition(lastY, lastX);
	std::cout << " ";

	// Draw avatar on new position
	Console::setColour(Console::RED, Console::BLACK);
	Console::setCursorPosition(mob.getY(), mob.getX());
	std::cout << mob.getAvatar();

	if (mob.getChasingCounter() >= 10)
	{
		mob.setState(mob.ROAMING);
	}
}

/*
	"moveMob" Function controlls the Monster AI that follows the player around.
	If the player is in range, the monster will follow him for a certain ammount
	of turns before giving up.
*/
void Controller::moveMob(Monster &mob, Player &player, Grid grid)
{
	if (mob.getState() == mob.ROAMING)
	{
		// Reset Chasing Counter
		mob.setChasingCounter(0);
		mobRoaming(mob, player, grid);
	}
	else if (mob.getState() == mob.CHASING)
	{
		// Increment Chasing Counter
		mob.setChasingCounter(mob.getChasingCounter() + 1);
		mobChasing(mob, player);
	}
}