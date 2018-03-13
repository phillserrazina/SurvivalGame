#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
	bool inRange;

public:
	Player(std::string, char);
};

#endif // !PLAYER_H