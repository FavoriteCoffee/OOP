#include "Troll.h"
#include "Field/Cell.h"
#include "Field/Field.h"


Troll::Troll(Cell* cell) {
	health = 15;
	defence = 0;
	attack = 5;
	cellPointer = cell;
	cellPointer->setEnemyPointer(this);
}


void Troll::setHealth(int hp) {
	health += hp;
}

void Troll::setDefence(int def) {
	defence += def;
}
void Troll::setAttack(int atk) {
	attack += atk;
}


void Troll::removeFromField() {
	cellPointer->setEnemyPointer(nullptr);
	cellPointer = nullptr;
}

Point Troll::move() {

	Point destination;
	destination = trajectory[step];

	if ((step + trajectoryDirection) < 0) trajectoryDirection *= -1;
	else if ((step + trajectoryDirection) >= trajectoryLength) trajectoryDirection *= -1;

	if (((trajectory[step + trajectoryDirection].y) < cellPointer->getFieldPointer()->getHeight()) &&
		((trajectory[step + trajectoryDirection].x) < cellPointer->getFieldPointer()->getWidth()) &&
		((trajectory[step + trajectoryDirection].x) >= 0) &&
		((trajectory[step + trajectoryDirection].y) >= 0) &&
		(cellPointer->getFieldPointer()->field[trajectory[step + trajectoryDirection].x][trajectory[step + trajectoryDirection].y].getIsPassable() &&
			(!(cellPointer->getFieldPointer()->field[trajectory[step + trajectoryDirection].x][trajectory[step + trajectoryDirection].y].getEnemy())))) {

		step += trajectoryDirection;
		destination =  trajectory[step];
	}
	
	return destination;
}

void Troll::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

std::string** Troll::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[6];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "TROLL: ";
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
		tempStr[0][0] = "TROLL: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "die";
	}
		return tempStr;
}

std::string Troll::printObj2() const
{
	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "[ TROLL: ] ";
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
		resStr += "[ TROLL: ] ";
		resStr += "die ";
	}
	return resStr;
}

