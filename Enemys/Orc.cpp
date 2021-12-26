#pragma once
#include "Orc.h"
#include "Field/Cell.h"
#include "Field/Field.h"


Orc::Orc(Cell* cell) {
	health = 1;
	defence = 1;
	attack = 1;
	cellPointer = cell;
	cellPointer->setEnemyPointer(this);
}

void Orc::setHealth(int hp) {
	health += hp;
}

void Orc::setDefence(int def) {
	defence += def;
}
void Orc::setAttack(int atk) {
	attack += atk;
}

void Orc::removeFromField() {
	cellPointer->setEnemyPointer(nullptr);
	cellPointer = nullptr;

}

void Orc::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

Point Orc::move() {
	Point destination;
	destination.x = cellPointer->getPosition().x;
	destination.y = cellPointer->getPosition().y;

	if (((cellPointer->getPosition().y + trajectoryDirection) < cellPointer->getFieldPointer()->getHeight()) &&
		(cellPointer->getPosition().y + trajectoryDirection >= 0) &&
		(cellPointer->getFieldPointer()->field[cellPointer->getPosition().x][cellPointer->getPosition().y + trajectoryDirection].getIsPassable() &&
			(!(cellPointer->getFieldPointer()->field[cellPointer->getPosition().x][cellPointer->getPosition().y + trajectoryDirection].getEnemy())))) {

		destination.x = cellPointer->getPosition().x;
		destination.y = cellPointer->getPosition().y + trajectoryDirection;
	}
	else if ((cellPointer->getPosition().y - trajectoryDirection) < cellPointer->getFieldPointer()->getHeight() &&
		(cellPointer->getPosition().y - trajectoryDirection >= 0) &&
		(cellPointer->getFieldPointer()->field[cellPointer->getPosition().x][cellPointer->getPosition().y - trajectoryDirection].getIsPassable()) &&
		(!(cellPointer->getFieldPointer()->field[cellPointer->getPosition().x][cellPointer->getPosition().y - trajectoryDirection].getEnemy())) &&
		(!(cellPointer->getFieldPointer()->field[cellPointer->getPosition().x][cellPointer->getPosition().y - trajectoryDirection].getPlayer()))) {
		trajectoryDirection *= -1;
		destination.x = cellPointer->getPosition().x;
		destination.y = cellPointer->getPosition().y + trajectoryDirection;

	}

	return destination;
}

std::string** Orc::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[6];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "ORC";
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
		tempStr[0][0] = "ORC: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "die";
	}
	return tempStr;
}

std::string Orc::printObj2() const
{
	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "[ ORC: ] ";
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
		resStr += "[ ORC: ] ";
		resStr += "die";
	}
	return resStr;
}