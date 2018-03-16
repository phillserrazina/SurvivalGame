#include "Bomb.h"

Bomb::Bomb()
{
	damage = 3;
	timer = 67;
	range = 5;

	name = "Bomb";
	avatar = 'B';
}

void Bomb::setBombPlaced(bool b)
{
	bombPlaced = b;
}

bool Bomb::getBombPlaced()
{
	return bombPlaced;
}

void Bomb::setDamage(int i)
{
	damage = i;
}

int Bomb::getDamage()
{
	return damage;
}

void Bomb::setTimer(int i)
{
	timer = i;
}

int Bomb::getTimer()
{
	return timer;
}

void Bomb::setRange(float f)
{
	range = f;
}

float Bomb::getRange()
{
	return range;
}

void Bomb::boomBomb(std::vector<Monster> &mobs, Player player)
{
	float playerDistance = CostumMath::getVectorLenght(xPos, yPos, player.getX(), player.getY());

	// Has the timer ended? 

	// If not, decrement it
	if (timer >= 67)
	{
		timer = 66;
		avatar = timer;
	}
	else if (timer == 66)
	{
		timer -= 15;
		avatar = timer;
	}
	else if (timer >= 50 && timer <= 51)
	{
		timer--;
		avatar = timer;
	}

	// If yes, explode the bomb
	else
	{
		timer = 0;

		// Reset the bomb
		bombPlaced = false;
		timer = 67;

		// Damage every nearby monster
		for (int i = 0; i < mobs.size(); i++)
		{
			float mobDistance = CostumMath::getVectorLenght(xPos, yPos, mobs[i].getX(), mobs[i].getY());

			if (mobDistance <= range)
			{
				mobs[i].setHealth(mobs[i].getHealth() - damage);

				if (mobs[i].getHealth() <= 0)
				{
					mobs[i].setDead(true);
				}
			}
		}

		if (playerDistance <= range)
		{

		}
	}
}