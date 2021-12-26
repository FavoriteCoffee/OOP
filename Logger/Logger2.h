#pragma once
#pragma once
#include<iostream>
#include <fstream>
#include "Point.h"
#include "IObject.h"
#include "Enemys/Enemy.h"
#include "Items/Item.h"
#include "Player/Player.h"
#include "Enemys/Goblin.h"
#include "Enemys/Orc.h"
#include "Enemys/Troll.h"
#include "Items/Battery.h"
#include "Items/HealthPotion.h"
#include "Items/PowerPotion.h"
#include "Items/MandalorianArmor.h"
#include <string>
#include <map>
class Cell;

class Logger2
{
public:

	Logger2(IObject* player, IObject* goblin, IObject* troll, IObject* orc, IObject* healthPotion, IObject* powerPotion, IObject* mandalorianArmor, IObject* battery);
	Logger2(){ }

	std::string logAllObjects();
	std::string logObject(IObject* obj);
	void getNewData(IObject* obj);
	//void deleteOldData(IObject* obj);
	void updateOldData(IObject* obj);
	//std::ofstream fout; 
	friend std::ostream& operator<< (std::ostream& out, const Logger2& logger);
	friend std::ofstream& operator<< (std::ofstream& fout, const std::string& tempstrNew2);
	std::string tempstrNew2;

private:

	std::map < IObject*, std::string > oldLogMap2;
	std::map < IObject*, std::string > newLogMap2;
	std::map <IObject*, std::string >  ::iterator oldIt;
	std::map <IObject*, std::string >  ::iterator newIt;
};
