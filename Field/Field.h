#pragma once
#include "Cell.h"
#include "IObject.h"
#include "Point.h"
#include "Enemys/Goblin.h"
#include "Enemys/Orc.h"
#include "Enemys/Troll.h"
#include <vector>

class Field
{
private:

	int height;
	int width;

	Point entry;
	Point exit;


public:
	Cell** field;

	Field();
	Field(int, int);

	Field(Field&&);
	Field& operator=(Field&&);
	~Field();

	Field(const Field&);
	Field& operator=(const Field&);

	//std::vector<Cell> operator[](const int index);
	Cell* operator[](const int index);

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	const Point& getExit() const { return exit; }
	Point getEntry() const { return entry; }

	bool tryMove(Point, Point);
	Cell* moveEnemy(Point start, Point destination, Enemy* enemy);

	void setEntry(short, short);
	void setExit(short, short);
	void setWidth(short);
	void setHeight(short);


	//std::vector <std::vector<Cell>> field;

};



