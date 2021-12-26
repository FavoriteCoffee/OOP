#pragma once
#include "Enemys/Enemy.h"
#include "Items/Item.h"
#include "Player/Player.h"
#include "Point.h"

//#include "IObject.h"

class Field;

class Cell
{
private:

	bool isPassable = true;

	Field* fieldPointer = nullptr;

	Player* playerPointer = nullptr;
	Enemy* enemyPointer = nullptr;
	Item* itemPointer = nullptr;

	Point position;

public:

	Cell();
	//Cell(Field*);
	/*Cell(const Cell&);
	Cell& operator=(const Cell&);*/


	Cell(int, int, Field*);

	Cell(const Cell&);
	Cell& operator=(const Cell&);

	Cell(Cell&&);
	Cell& operator=(Cell&&);



	//Cell(int x, int y, Field*, bool setIsPassable);

	Point getPosition() const { return position; }
	bool getIsPassable() const { return isPassable; }
	bool getPlayer() const { return playerPointer; }
	bool getEnemy() const {
		if (enemyPointer == nullptr) return false;
		else return true;
	}
	bool getItem() const { return itemPointer; }

	Enemy::EnemyType getEnemyType() const { return enemyPointer->getEnemyType(); }

	Field* getFieldPointer() const { return fieldPointer; }

	Player* getPlayerPointer() { return playerPointer; }
	Enemy* getEnemyPointer() { return enemyPointer; }
	Item* getItemPointer() { return itemPointer; }

	void setPlayerPointer(Player*);
	void setEnemyPointer(Enemy*);
	void setItemPointer(Item*);

	void setIsPassiable(bool);
	void setFieldPointer(Field*);
};
