#pragma once
#include "../Point.h"
#include "../IObject.h"

class Cell;

class Enemy : public IObject
{
public:
	enum class EnemyType
	{
		GOBLIN,
		TROLL,
		ORC
	};

	//std::map <IObject::moveKey, Point()> moveAlittle;

	virtual int getHealth() const = 0;
	virtual int getDefence() const = 0;
	virtual int getAttack() const = 0;
	virtual EnemyType getEnemyType() const = 0;///???
	virtual Point move() = 0;
	

	virtual void setHealth(int) = 0;
	virtual void setDefence(int) = 0;
	virtual void setAttack(int) = 0;
	virtual void setCellPointer(Cell*) = 0;
};

