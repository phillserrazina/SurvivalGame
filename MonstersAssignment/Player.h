#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
public:
	Player();

	static std::string playerName;
	static char playerAvatar;
};

#endif // !PLAYER_H