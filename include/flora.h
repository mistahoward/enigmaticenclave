#ifndef FLORA_H
#define FLORA_H

#include <string>

#include "entity.h"

using std::string; 

class Flora : public Entity
{
	public:
		Flora(int mapIndex, int roomIndex, string name, string description,
			bool isEdible, bool isDeadly, bool isMedicinal, bool isPoisonous,
			bool isToxic, bool isHallucinogenic, bool isPsychoactive,
			bool isNarcotic, bool isSedative, bool isStimulant) : 
		Entity(mapIndex, roomIndex, name, description), 
			isEdible(isEdible), isDeadly(isDeadly), isMedicinal(isMedicinal),
			isPoisonous(isPoisonous), isToxic(isToxic), 
			isHallucinogenic(isHallucinogenic), isPsychoactive(isPsychoactive),
			isNarcotic(isNarcotic), isSedative(isSedative), 
			isStimulant(isStimulant) {}
	private:
		bool isEdible;
		bool isDeadly;
		bool isMedicinal;
		bool isPoisonous;
		bool isToxic;
		bool isHallucinogenic;
		bool isPsychoactive;
		bool isNarcotic;
		bool isSedative;
		bool isStimulant;
		int mapIndex;
		int roomIndex;
		string name;
		string description;
};

#endif // FLORA_H