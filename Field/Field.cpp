
#include<iostream>
#include<cassert>

#include "Field.h"
#include "Enemys/Orc.h"
#include "Enemys/Goblin.h"
#include "Enemys/Troll.h"
#include "Items/MandalorianArmor.h"
#include "Items/PowerPotion.h"
#include "Items/HealthPotion.h"

Field::Field()
{
	height = 3;
	width = 3;

	/*std::vector <std::vector<Cell>> field;
	for (int i = 0; i < width; ++i) {
		field.push_back(std::vector <Cell>());
		for (int j = 0; j < height; ++j) {
			field[i].emplace_back(i, j);
		}
	}*/


	field = new Cell * [width];
	for (int i = 0; i < width; ++i) {
		field[i] = new Cell[height]();
	}

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < width; ++j) {
			field[i][j] = Cell(i, j, this);
		}
	}

	entry = Point(0, 0);
	exit = Point(width, height);
}

Field::Field(int setHeight, int setWidth)
{
	height = setHeight;
	width = setWidth;

	field = new Cell * [width];
	for (int i = 0; i < width; ++i) {
		field[i] = new Cell[height];
	}

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < width; ++j) {
			field[i][j] = Cell(i, j, this);
		}
	}

	entry = Point(0, 0);
	exit = Point(width - 1, height - 1);
}

Field::~Field() {
	for (int i = 0; i < width; ++i)
		delete[] field[i];
	delete[] field;
}

Field::Field(const Field& obj) :width(obj.width), height(obj.height), field(new Cell* [width])
{
	exit = obj.exit;
	entry = obj.entry;
	field = new Cell * [width];
	for (int i = 0; i < width; ++i) {
		field[i] = new Cell[height];
	}

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			field[i][j] = obj.field[i][j];
		}
	}

}

Field& Field::operator=(const Field& obj)
{
	if (this != &obj) {

		for (int i = 0; i < width; ++i) {
			delete[] field[i];
		}
		delete[] field;

		width = obj.width;
		height = obj.height;

		exit = obj.exit;
		entry = obj.entry;

		field = new Cell * [width];
		for (int i = 0; i < width; ++i) {
			field[i] = new Cell[height];
		}

		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				field[i][j] = obj.field[i][j];
				field[i][j].setFieldPointer(this);
			}
	}

	return *this;
}

Field::Field(Field&& obj)
{
	//*this = std::move(obj);
	std::swap(height, obj.height);
	std::swap(width, obj.width);
	std::swap(entry, obj.entry);
	std::swap(exit, obj.exit);
	std::swap(field, obj.field);

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			field[i][j].setFieldPointer(this);
		}
	}
}

Field& Field::operator=(Field&& obj)
{
	if (this != &obj) {

		/*for (int i = 0; i < width; ++i)
			delete[] field[i];
		delete[] field;*/

		std::swap(width, obj.width);
		std::swap(height, obj.height);
		std::swap(field, obj.field);
		std::cout << field << std::endl;

		std::swap(entry, obj.entry);
		std::cout << entry.x << entry.y << std::endl;
		std::swap(exit, obj.exit);
		std::cout << exit.x << exit.y << std::endl;

		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				field[i][j].setFieldPointer(this);
			}
		}

	}
	return *this;
}



Cell* Field::operator[](const int index) {
	//assert(index >= 0 && index < width);

	return field[index];
}


void Field::setEntry(short entryX = 0, short entryY = 0) {
	if (entryX < width && entryY < height) {
		entry = Point(entryX, entryY);
	}
}

void Field::setExit(short exitX, short exitY) {
	if (exitX < width && exitY < height) {
		exit = Point(exitX, exitY);
	}
}

void Field::setWidth(short setW) {
	width = setW;
}

void Field::setHeight(short setH) {
	height = setH;
}

bool Field::tryMove(Point destination, Point start) {

	if (((destination.x == start.x) && (abs(destination.y - start.y) == 1)) ||
		((destination.y == start.y) && (abs(destination.x - start.x) == 1))) {
		return true;
	}

	return false;
}

Cell* Field::moveEnemy(Point start, Point destination, Enemy* enemy) {

	if (tryMove(destination, start)) {

		field[destination.x][destination.y].setEnemyPointer(enemy);
		enemy->setCellPointer(&field[destination.x][destination.y]);
		field[start.x][start.y].setEnemyPointer(nullptr);

		return &field[destination.x][destination.y];
	}
}
