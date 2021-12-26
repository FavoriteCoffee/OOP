#pragma once
#include"Item.h" 
#include"Point.h"
#include<string>

class PowerPotion : public Item
{
public:

	PowerPotion(Cell*);

	int getValue() const override { return attack; }
	ItemType getItemType() const override { return itemType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ITEM; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;
	std::string** printObj() const override;
	std::string printObj2() const override;

private:

	int attack = 1;
	ItemType itemType = ItemType::POWER_POTION;
	Cell* cellPointer;
};
