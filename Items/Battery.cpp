#include "Battery.h"
#include "Field/Cell.h"


Battery::Battery(Cell* cell) {
	cellPointer = cell;
	cellPointer->setItemPointer(this);
}

void Battery::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

void Battery::removeFromField(){ 
	cellPointer->setItemPointer(nullptr);
	cellPointer = nullptr;
}

std::string** Battery::printObj() const {

	std::string** tempStr = new std::string * [2];
	for (int i = 0; i < 2; ++i) {
		tempStr[i] = new std::string[4];
	}
	if (cellPointer != nullptr)
	{
		tempStr[0][0] = "BATTARY";
		tempStr[1][0] = "4";
		tempStr[0][1] = "positionX";
		tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
		tempStr[0][2] = "positionY";
		tempStr[1][2] = std::to_string(cellPointer->getPosition().y);
		tempStr[0][3] = "energy";
		tempStr[1][3] = std::to_string(energy);

	}
	else
	{
		tempStr[0][0] = "BATTARY: ";
		tempStr[1][0] = "2";
		tempStr[1][1] = "taken";
	}
		return tempStr;


}

std::string Battery::printObj2() const {

	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "BATTERY: ";
		resStr += "position: ";
		resStr += std::to_string(cellPointer->getPosition().x) + " " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "energy: ";
		resStr += std::to_string(energy) + " ";


	}
	else
	{
		resStr += "BATTERY: ";
		resStr += "picked";
	}

	return resStr;
}