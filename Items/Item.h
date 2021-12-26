#pragma once
#include "Point.h"
#include "IObject.h"

class Cell;

class Item :public IObject
{
public:

	enum class ItemType
	{
		HEALTH_POTION,
		POWER_POTION,
		MANDALORIAN_ARMOR,
		BATTARY
	};

	virtual int getValue() const = 0 ;
	virtual ItemType getItemType() const = 0;

	virtual void setCellPointer(Cell*) = 0;
};
