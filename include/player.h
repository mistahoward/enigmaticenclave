#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

class Player
{
public:
	Player();
	int health;
	int stamina;
	int hunger;
	int thirst;
	int attack;
	int defense;
	int dexterity;
	int intelligence;
	int luck;
	int level;
	int experience;
	Item inventory[20];
	Item equippedItems[5];
};

#endif // PLAYER_H