#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using std::string; 

class Entity {
public:
	Entity(int mapIndex, int roomIndex, string name, string description) 
		: mapIndex(mapIndex), roomIndex(roomIndex), name(name), description(description) {}
	int getMapIndex();
	void setMapIndex(int mapIndex);
	int getRoomIndex();
	void setRoomIndex(int roomIndex);
	string getName();
	void setName(string name);
	string getDescription();
	void setDescription(string description);

	virtual ~Entity() {}
private:
    int mapIndex;
    int roomIndex;
	string name;
	string description;
};

#endif // ENTITY_H