#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

class Character
{
protected:
	std::string name;

	char avatar;

	int xPos;
	int yPos;

public:
	Character();
	Character(std::string, char);

	void setName(std::string);
	std::string getName();

	void setAvatar(char);
	char getAvatar();

	void setX(int);
	int getX();

	void setY(int);
	int getY();

};

#endif // !CHARACTER_H