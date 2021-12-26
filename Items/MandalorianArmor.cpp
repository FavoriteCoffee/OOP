#pragma once
#include"MandalorianArmor.h"
#include "Field/Cell.h"

MandalorianArmor::MandalorianArmor(Cell* cell) {
	cellPointer = cell;
	cellPointer->setItemPointer(this);
}

void MandalorianArmor::removeFromField() {
	cellPointer->setItemPointer(nullptr);
	cellPointer = nullptr;
}

void MandalorianArmor::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

std::string** MandalorianArmor::printObj() const{

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[4];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "MANDALORIAN ARMOR";
		tempStr[1][0] = "4";
		tempStr[0][1] = "positionX";
		tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
		tempStr[0][2] = "positionY";
		tempStr[1][2] = std::to_string(cellPointer->getPosition().y);
		tempStr[0][3] = "defence";
		tempStr[1][3] = std::to_string(defence);
	}
	else
	{
		tempStr[0][0] = "MANDALORIAN ARMOR: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "taken";
	}
	return tempStr;
}

std::string MandalorianArmor::printObj2() const {

	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "MANDALORIAN ARMOR: ";
		resStr += "position";
		resStr +=  std::to_string(cellPointer->getPosition().x) + " " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "defence: ";
		resStr += std::to_string(defence) + " ";
	}
	else
	{
		resStr += "MANDALORIAN ARMOR: ";
		resStr += "picked";
	}

	return resStr;

}