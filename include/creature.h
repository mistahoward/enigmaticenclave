#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"

class Creature : public Entity
{
public:
	Creature(int mapIndex, int roomIndex, string name, string description, 
		int currentHealth, int maxHealth, int currentStamina, int maxStamina, 
		int currentHunger, int maxHunger, int currentThirst, int maxThirst, 
		int attack, int defense, int dexterity, int intelligence,
		 int luck, int level)
	: Entity(mapIndex, roomIndex, name, description), 
		currentHealth(currentHealth), maxHealth(maxHealth), 
		currentStamina(currentStamina), maxStamina(maxStamina),
		currentHunger(currentHunger), maxHunger(maxHunger), 
		currentThirst(currentThirst), maxThirst(maxThirst), 
		attack(attack), defense(defense), dexterity(dexterity), 
		intelligence(intelligence), luck(luck), level(level) {}
	int getCurrentHealth();
	void setCurrentHealth(int health);
	int getStamina();
	void setStamina(int stamina);
	int getHunger();
	void setHunger(int hunger);
	int getCurrentThirst();
	void setCurrentThirst(int thirst);
	int getAttack();
	void setAttack(int attack);
	int getDefense();
	void setDefense(int defense);
	int getDexterity();
	void setDexterity(int dexterity);
	int getIntelligence();
	void setIntelligence(int intelligence);
	int getLuck();
	void setLuck(int luck);
	int getLevel();
	void setLevel(int level);

	virtual ~Creature() {}

private:
	int currentHealth;
	int maxHealth;
	int currentStamina;
	int maxStamina;
	int currentHunger;
	int maxHunger;
	int currentThirst;
	int maxThirst;
	int attack;
	int defense;
	int dexterity;
	int intelligence;
	int luck;
	int level;
};

#endif // CREATURE_H