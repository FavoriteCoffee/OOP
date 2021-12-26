#pragma once
#include "Enemy.h"
#include "../Point.h"
#include<string>

class Cell;
class Field;

class Goblin : public Enemy
{
public:
	
	Goblin(Cell*);
	
	Point moveAlittele(Point);

	int getHealth() const override { return health; }
	int getDefence() const override { return defence; }
	int getAttack() const override { return attack; }
	Cell* getCellPointer() const override { return cellPointer; }
	EnemyType getEnemyType() const override { return enemyType; }
	IObject::Objects getObjType() const override { return IObject::Objects::ENEMY; }

	void setCellPointer(Cell*) override;

	void setHealth(int) override;
	void setDefence(int) override;
	void setAttack(int) override;

	void removeFromField() override;

	Point move() override;
	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int health;
	int defence;
	int attack;
	EnemyType enemyType = EnemyType::GOBLIN;

	Cell* cellPointer;//TODO враг может числиться в нескольких клетках -> unique_ptr
};

