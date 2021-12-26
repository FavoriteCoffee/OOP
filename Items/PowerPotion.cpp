#pragma once
#include"PowerPotion.h"
#include "Field/Cell.h"

PowerPotion::PowerPotion(Cell* cell) {
	cellPointer = cell;
	cellPointer->setItemPointer(this);
}

void PowerPotion::removeFromField() {
	cellPointer->setItemPointer(nullptr);
	cellPointer = nullptr;
}

void PowerPotion::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

std::string** PowerPotion::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[4];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "POWER POTION";
		tempStr[1][0] = "4";
		tempStr[0][1] = "positionX";
		tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
		tempStr[0][2] = "positionY";
		tempStr[1][2] = std::to_string(cellPointer->getPosition().y);
		tempStr[0][3] = "attack";
		tempStr[1][3] = std::to_string(attack);
	}
	else
	{
		tempStr[0][0] = "POWER POTION: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "taken";
	}

	return tempStr;
}

std::string PowerPotion::printObj2() const {

	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "POWER POTION: ";
		resStr += "position: ";
		resStr += std::to_string(cellPointer->getPosition().x) + " " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "attack: ";
		resStr += std::to_string(attack) + " ";
	}
	else
	{
		resStr += "POWER POTION: ";
		resStr += "picked";
	}

	return resStr;

}