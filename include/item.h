#ifndef ITEM_H
#define ITEM_H

class Item {
	public: 
	Item();
	int itemId;
	bool consumable;
	int durability;
	int atkRequirement;
	int defRequirement;
	int dexRequirement;
	int intRequirement;
	int luckRequirement;
	int lvlRequirement;
};

#endif // ITEM_H