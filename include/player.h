#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "item.h"
#include "creature.h"

using std::string; 

class Player : public Creature
{
public:
	Player(int mapIndex, int roomIndex, string name, string description, 
		int currentHealth, int maxHealth, int currentStamina, int maxStamina, 
		int currentHunger, int maxHunger, int currentThirst, int maxThirst, 
		int attack, int defense, int dexterity, int intelligence,
		int luck, int level, int experience) :
		Creature(mapIndex, roomIndex, name, description, currentHealth, maxHealth, 
			currentStamina, maxStamina, currentHunger, maxHunger, currentThirst, 
			maxThirst, attack, defense, dexterity, intelligence, luck, level), 
		experience(experience) {}

	int getExperience();
	void setExperience(int experience);
	
private:
	int experience;
	Item inventory[20];
	Item equippedItems[5];
};

#endif // PLAYER_H