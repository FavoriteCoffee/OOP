#pragma once
#include"Enemy.h"
#include"Point.h"
#include<string>

class Cell;

class Orc : public Enemy
{
public:
	Orc(Cell*);

	int getHealth() const override { return health; }
	int getDefence() const override { return defence; }
	int getAttack() const override { return attack; }
	EnemyType getEnemyType() const override { return enemyType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ENEMY; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;//!!

	void setHealth(int) override;
	void setDefence(int) override;
	void setAttack(int) override;

	Point move() override;	
	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int health;
	int defence;
	int attack;
	EnemyType enemyType = EnemyType::ORC;
	Cell* cellPointer;

	int trajectoryDirection = 1;
};

