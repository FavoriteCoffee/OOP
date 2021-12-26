#pragma once
#include<iostream>


class Cell;

class IObject
{
public:

	enum class Objects
	{
		NOTHING,
		PLAYER,
		ENEMY,
		ITEM
	};

	enum class moveKey
	{
		LEFT,
		UP,
		RIGHT,
		DOWN
	};
	
	virtual void removeFromField() = 0;
	virtual Cell* getCellPointer() const = 0;
	virtual Objects getObjType() const = 0;
	virtual std::string** printObj() const = 0;
	virtual std::string printObj2() const = 0;
	//virtual std::string convertObjectToString(IObject*) const = 0;

};
