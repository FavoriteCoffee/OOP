#pragma once
#include <vector>
#include "IObject.h"
#include "Field/Field.h"

class IGame
{
public:
	
	virtual const std::vector <IObject*>& getVectorOfPointersToObjects() const = 0;
	virtual const Field& getField() const = 0;
	virtual bool ifRule() const = 0;
	virtual Player* getPlayerFromVector() const = 0;
	virtual const std::vector <Enemy*>& getVectorOfPointersToEnemies() const = 0;
	virtual const std::vector <Item*>& getVectorOfPointersToItems() const = 0;
	virtual const std::fstream& getSaveObjectsFile() const = 0;
	//virtual const std::fstream& getSaveMapFile() const = 0;
};

