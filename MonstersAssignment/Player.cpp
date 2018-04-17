#include "Player.h"

std::string Player::playerName = "Default";
char Player::playerAvatar = '@';

Player::Player()
{
	name = playerName;
	avatar = playerAvatar;

	xPos = 1;
	yPos = 1;
}