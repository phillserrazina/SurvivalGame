#include "Bomb.h"

Bomb::Bomb()
{
	damage = 3;
	timer = 3;
	range = 3;

	name = "Bomb";
	avatar = 'B';
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

void Bomb::boomBomb(std::vector<Monster> mobs, Player player)
{
	float playerDistance = CostumMath::getVectorLenght(xPos, yPos, player.getX(), player.getY());

	if (timer <= 0)
	{
		Controller::bombPlaced = false;

		for (int i = 0; i < mobs.size(); i++)
		{
			float mobDistance = CostumMath::getVectorLenght(xPos, yPos, mobs[i].getX(), mobs[i].getY());
		
			if (mobDistance <= range)
			{
				mobs[i].setHealth(mobs[i].getHealth() - damage);
			}
		}

		if (playerDistance <= range)
		{

		}
	}
	else if (timer > 0)
	{
		timer--;
		// avatar = static_cast<char>(timer);
	}
}