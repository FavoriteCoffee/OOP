
#include "Cell.h"
#include "Field/Field.h"

Cell::Cell() {
	isPassable = true;

}

//Cell::Cell(Field* field) {
//	isPassable = true;
//	fieldPointer = field;
//}

Cell::Cell(int setX, int setY, Field* field) {
	isPassable = true;
	fieldPointer = field;
	position.x = setX;
	position.y = setY;
	playerPointer = nullptr;
	enemyPointer = nullptr;
	itemPointer = nullptr;
}

Cell::Cell(const Cell& obj) :isPassable(obj.isPassable),
fieldPointer(obj.fieldPointer), playerPointer(obj.playerPointer),
enemyPointer(obj.enemyPointer), itemPointer(obj.itemPointer),
position(obj.position)
{}

Cell& Cell::operator=(const Cell& obj) {
	if (this != &obj) {

		isPassable = obj.isPassable;
		fieldPointer = obj.fieldPointer;
		playerPointer = obj.playerPointer;
		enemyPointer = obj.enemyPointer;
		itemPointer = obj.itemPointer;
		position.x = obj.position.x;
		position.y = obj.position.y;
	}

	return *this;
}

Cell::Cell(Cell&& obj) {
	std::swap(isPassable, obj.isPassable);
	std::swap(fieldPointer, obj.fieldPointer);
	std::swap(playerPointer, obj.playerPointer);
	std::swap(enemyPointer, obj.enemyPointer);
	std::swap(itemPointer, obj.itemPointer);
	std::swap(position, obj.position);
}

Cell& Cell::operator=(Cell&& obj) {
	if (this != &obj) {

		std::swap(isPassable, obj.isPassable);
		std::swap(fieldPointer, obj.fieldPointer);
		std::swap(playerPointer, obj.playerPointer);
		std::swap(enemyPointer, obj.enemyPointer);
		std::swap(itemPointer, obj.itemPointer);
		std::swap(position, obj.position);
	}
	return *this;
}
//Cell::Cell(const Cell& obj) :isPassable(obj.isPassable), fieldPointer(obj.fieldPointer), playerPointer(obj.playerPointer), enemyPointer(obj.enemyPointer), itemPointer(obj.itemPointer)
//{
//	position.x = obj.position.x;
//	position.y = obj.position.y;
//}
//
//Cell& Cell::operator=(const Cell& obj)
//{
//	if (this != &obj) {
//
//		isPassable = obj.isPassable;
//		fieldPointer = obj.fieldPointer;
//		playerPointer = obj.playerPointer;
//		enemyPointer = obj.enemyPointer;
//		itemPointer = obj.itemPointer;
//		position = obj.position;
//	}
//
//	return *this;
//}


//Cell::Cell(int setX, int setY, Field* field, bool setIsPassable = true) {
//	isPassable = setIsPassable;
//	position.x = setX;
//	position.y = setY;
//	fieldPointer = field;
//	playerPointer = nullptr;
//	enemyPointer = nullptr;
//	itemPointer = nullptr;
//}

void Cell::setFieldPointer(Field* setField) {
	fieldPointer = setField;
}

void Cell::setIsPassiable(bool set) {
	isPassable = set;
}

void Cell::setPlayerPointer(Player* player ) {
	playerPointer = player;
}

void Cell::setEnemyPointer(Enemy* enemy) {
	enemyPointer = enemy;
}

void Cell::setItemPointer(Item* item) {
	itemPointer = item;
}
