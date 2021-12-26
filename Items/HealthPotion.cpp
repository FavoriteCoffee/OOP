#pragma once
#include "HealthPotion.h"
#include "Field/Cell.h"

HealthPotion::HealthPotion(Cell* cell) {
	cell->setIsPassiable(true);
	cellPointer = cell;
	cellPointer->setItemPointer(this);
}

void HealthPotion::removeFromField() {
	cellPointer->setItemPointer(nullptr);
	cellPointer = nullptr;
}

void HealthPotion::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}


std::string** HealthPotion::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[4];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "HEALTH POTION";
		tempStr[1][0] = "4";
		tempStr[0][1] = "positionX";
		tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
		tempStr[0][2] = "positionY";
		tempStr[1][2] = std::to_string(cellPointer->getPosition().y);
		tempStr[0][3] = "health";
		tempStr[1][3] = std::to_string(health);
	}
	else
	{
		tempStr[0][0] = "HEALTH POTION: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "taken";
	}
	return tempStr;;

}

std::string HealthPotion::printObj2() const {

	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "HEALTH POTION: ";
		resStr += "position: ";
		resStr += std::to_string(cellPointer->getPosition().x) + " " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "health: ";
		resStr += std::to_string(health) + " ";
	}
	else
	{
		resStr += "HEALTH POTION: ";
		resStr += "picked";
	}

	return resStr;

}