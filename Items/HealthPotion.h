#pragma once
#include"Item.h"
#include"Point.h"
#include<string>

class Cell;

class HealthPotion :public Item
{
public:

	HealthPotion(Cell*);

	int getValue() const override { return health; }
	ItemType getItemType() const override { return itemType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ITEM; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;
	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int health = 3;
	ItemType itemType = ItemType::HEALTH_POTION;
	Cell* cellPointer;
};