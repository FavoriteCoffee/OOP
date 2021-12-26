#pragma once
#include"Item.h" 
#include<string>

class Cell;

class Battery : public Item
{
public:

	Battery(Cell*);

	int getValue() const override { return energy; }
	ItemType getItemType() const override { return itemType; }
	Cell* getCellPointer() const override { return cellPointer; }
	IObject::Objects getObjType() const override { return IObject::Objects::ITEM; }

	void setCellPointer(Cell*) override;

	void removeFromField() override;
	std::string** printObj() const override;
	std::string printObj2() const override;

private:
	int energy = 1;
	ItemType itemType = ItemType::BATTARY;
	Cell* cellPointer;
};
