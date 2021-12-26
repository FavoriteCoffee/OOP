#pragma once
#include"Item.h" 
#include"Point.h"
#include<string>

class MandalorianArmor: public Item
{
public:

	MandalorianArmor(Cell*);

	int getValue() const override { return defence; }
	ItemType getItemType() const override { return itemType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ITEM; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;
	std::string** printObj() const override;
	std::string printObj2() const override;

private:

	int defence = 2;
	ItemType itemType = ItemType::MANDALORIAN_ARMOR;
	Cell* cellPointer;
};


