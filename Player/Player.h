#pragma once
#include "Items/Item.h"
#include "Enemys/Enemy.h"
#include "Point.h"
#include<string>
#include<vector>

class Cell;
class Field;


class Player : public IObject
{
public:


	Player(Cell* cell);

	int getHealth() const  { return health; }
	int getDefence() const  { return defence; }
	int getAttack() const  { return attack; }
	int getEnergy() { return energy; }
	IObject::Objects getObjType() const override { return IObject::Objects::PLAYER; }

	Cell* getCellPointer() const override { return cellPointer; }

	void setCellPointer(Cell*);

	void setHealth(int);
	void setDefence(int);
	void setAttack(int);
	void setEnergy(int);

	void removeFromField() override;

	void move(IObject::moveKey);
	void move(Point);

	bool fighting(Enemy*, std::vector <Enemy*>&);

	void pickUp(Item*, std::vector <Item*>&);

	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int health;
	int defence;
	int attack;
	int energy;

	Cell* cellPointer;
};

	