
#include "Goblin.h"
#include <cstdlib>
#include "Field/Cell.h"
#include "Field/Field.h"


Goblin::Goblin(Cell* cell) {
	health = 1;
	defence = 1;
	attack = 1;
	cellPointer = cell;
	cellPointer->setEnemyPointer(this);
}

void Goblin::setHealth(int hp) {
	health += hp;
}

void Goblin::setDefence(int def) {
	defence += def;
}
void Goblin::setAttack(int atk) {
	attack += atk;
}

void Goblin::removeFromField() {
	cellPointer->setEnemyPointer(nullptr);
	cellPointer = nullptr;
}

void Goblin::setCellPointer(Cell* newCell) {
	cellPointer = std::move(newCell);
}

Point Goblin::move() {

	Point destination = cellPointer->getPosition();

	IObject::moveKey step = IObject::moveKey(rand() % 4);

	//Enemy::moveAlittle[step];

	switch (step)
	{
	case IObject::moveKey::LEFT:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x - 1][getCellPointer()->getPosition().y].getIsPassable()) &&
			(!(cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x - 1][getCellPointer()->getPosition().y].getEnemy())) &&
			(cellPointer->getPosition().x - 1 >= 0) &&
			(cellPointer->getPosition().x - 1 < cellPointer->getFieldPointer()->getWidth())) {

			destination.x = cellPointer->getPosition().x - 1;
			destination.y = getCellPointer()->getPosition().y;

		}
		return destination;

	case IObject::moveKey::UP:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y - 1].getIsPassable()) &&
			(!(cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y - 1].getEnemy())) &&
			(cellPointer->getPosition().y - 1 >= 0) &&
			(cellPointer->getPosition().y - 1 < cellPointer->getFieldPointer()->getHeight())) {

			destination.x = getCellPointer()->getPosition().x;
			destination.y = getCellPointer()->getPosition().y - 1;

		}
		return destination;

	case IObject::moveKey::RIGHT:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x + 1][getCellPointer()->getPosition().y].getIsPassable()) &&
			(!(cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x + 1][getCellPointer()->getPosition().y].getEnemy())) &&
			(cellPointer->getPosition().x + 1 >= 0) &&
			(cellPointer->getPosition().x + 1 < cellPointer->getFieldPointer()->getWidth())) {

			destination.x = cellPointer->getPosition().x + 1;
			destination.y = getCellPointer()->getPosition().y;

		}
		return destination;

	case IObject::moveKey::DOWN:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y + 1].getIsPassable()) &&
			(!(cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y + 1].getEnemy())) &&
			(cellPointer->getPosition().y + 1 >= 0) &&
			(cellPointer->getPosition().y + 1 < cellPointer->getFieldPointer()->getHeight())) {

			destination.x = getCellPointer()->getPosition().x;
			destination.y = getCellPointer()->getPosition().y + 1;

		}
		return destination;
	}
}

std::string** Goblin::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[6];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "GOBLIN";
		tempStr[1][0] = "6";
		tempStr[0][1] = "positionX";
		tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
		tempStr[0][2] = "positionY";
		tempStr[1][2] = std::to_string(cellPointer->getPosition().y);
		tempStr[0][3] = "health";
		tempStr[1][3] = std::to_string(health);
		tempStr[0][4] = "defence";
		tempStr[1][4] = std::to_string(defence);
		tempStr[0][5] = "attack";
		tempStr[1][5] = std::to_string(attack);
	}
	else
	{
		tempStr[0][0] = "GOBLIN: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "die";
	}
	
	return tempStr;

}

std::string Goblin::printObj2() const 
{
	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "[ GOBLIN: ] ";
		resStr += "position: ";
		resStr += std::to_string(cellPointer->getPosition().x) + " , " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "health: ";
		resStr += std::to_string(health) + " ";
		resStr += "defence: ";
		resStr += std::to_string(defence) + " ";
		resStr += "attack: ";
		resStr += std::to_string(attack) + " ";
	}
	else
	{
		resStr += "[ GOBLIN: ] ";
		resStr += "die";
	}
	return resStr;
}