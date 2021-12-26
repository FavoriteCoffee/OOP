#pragma once
#include "Enemy.h"
#include "Point.h"
#include<string>

class Cell;

class Troll : public Enemy
{
public:

	Troll(Cell*);

	int getHealth() const override { return health; }
	int getDefence() const override { return defence; }
	int getAttack() const override { return attack; }
	int getStep() { return step; }
	EnemyType getEnemyType() const override { return enemyType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ENEMY; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;

	void setHealth(int) override;
	void setDefence(int) override;
	void setAttack(int) override;

	Point move() override;

	int step = 0;
	int trajectoryDirection = 1;
	const int trajectoryLength = 9;
	Point trajectory[9] = { Point(5, 5), Point(6, 5), Point(7, 5),
							Point(7, 6), Point(7, 7), Point(7, 8),
							Point(6, 8), Point(5, 8), Point(4, 8) };

	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int health;
	int defence;
	int attack;
	EnemyType enemyType = EnemyType::TROLL;

	Cell* cellPointer;//TODO враг может числиться в нескольких клетках - > unique_ptr
};

