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

class Logger
{
public:

	Logger(IObject* player, IObject* goblin, IObject* troll, IObject* orc,  IObject* battery, IObject* healthPotion, IObject* powerPotion, IObject* mandalorianArmor);

	std::string logAllObjects();
	void getNewData();
	void deleteOldData();
	void updateOldData();
	//std::ofstream& fout; 
	//friend std::ostream& operator<< (std::ostream& out, const Logger& loger);
	//friend std::ofstream& operator<< (std::ofstream& fout, const Logger& loger);
	std::string tempstrNew;
private:

	std::map < IObject*, std::string** > oldLogMap;
	std::map < IObject*, std::string** > newLogMap;
	std::map <IObject*, std::string** >  ::iterator oldIt;
	std::map <IObject*, std::string** >  ::iterator newIt;
};
