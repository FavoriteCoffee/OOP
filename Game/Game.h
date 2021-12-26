#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
#include "IniFile/IniFile.h"
#include "Field/Field.h"
#include "Point.h"
#include "Game.h"
#include "Items/MandalorianArmor.h"
#include "Items/Battery.h"
#include "Items/HealthPotion.h"
#include "Items/PowerPotion.h"
#include "Logger/Logger2.h"
#include "IGame.h"
#include "GUI/SFMLScene.h"
#include "Input/Input.h"

using namespace std;
//using PLayer = dynamic_cast<Player*>(vectorOfPointersToObjects[0]);
//using namespace sf;

template <typename Rule>
class Game : public IGame
{
private:

	Rule rule;
	Field* playingField;
	Font font;
	SFMLScene scene;
	Clock clock;
	Time sleepTime = seconds(0.3);
	Input input;
	std::fstream filelog;
	std::fstream saveObjectsFile;
	std::fstream saveMapFile;
	std::string fileName = "testF.txt";
	IniFile iniFile = IniFile(fileName);



public:

	std::vector <Enemy*> vectorOfPointersToEnemies;

	std::vector <Item*> vectorOfPointersToItems;
	std::vector <IObject*> vectorOfPointersToObjects;

	Logger2 gameLog2;

	Game(Field* field, Rule setRule) : scene(this), input(this) {
		playingField = field;
		rule = setRule;
	}

	Rule* getRule() {
		return rule;
	}

	const Field& getField() const override {
		return *playingField;
	}

	const std::vector <IObject*>& getVectorOfPointersToObjects() const override {
		return vectorOfPointersToObjects;
	}

	Player* getPlayerFromVector() const override {
		return dynamic_cast<Player*>(vectorOfPointersToObjects[0]);
	}

	const std::vector <Enemy*>& getVectorOfPointersToEnemies() const override {
		return vectorOfPointersToEnemies;
	}

	const std::vector <Item*>& getVectorOfPointersToItems() const override {
		return vectorOfPointersToItems;
	}

	bool ifRule() const override {
		if (rule.openTheDoor(this)) return true;
		else return false;
	}

	const std::fstream& getSaveObjectsFile() const override {
		return saveObjectsFile;
	}

	//const std::fstream& getSaveMapFile() const override {
		//return saveMapFile;
	//}

	Game();
	//void setField();

	void moveEnemy() {

		for (int i = 0; i < vectorOfPointersToEnemies.size(); ++i) {
			if (vectorOfPointersToEnemies[i] != nullptr) {
				if (vectorOfPointersToEnemies[i]->getCellPointer()) {
					Point start = vectorOfPointersToEnemies[i]->getCellPointer()->getPosition();
					Point destination = vectorOfPointersToEnemies[i]->move();
					playingField->moveEnemy(start, destination, vectorOfPointersToEnemies[i]);
				}
			}
		}

	}

	bool tryFight() { return true; }
	bool tryPicUp() { return true; }

	void createObjects() {

		Player* player = new Player(&playingField->field[playingField->getEntry().x][playingField->getEntry().y]);
		vectorOfPointersToObjects.push_back(player);

		Goblin* goblin0 = new Goblin(&playingField->field[3][4]);
		Troll* troll0 = new Troll(&playingField->field[5][5]);
		Orc* orc0 = new Orc(&playingField->field[6][5]);

		vectorOfPointersToEnemies.push_back(goblin0);
		vectorOfPointersToEnemies.push_back(troll0);
		vectorOfPointersToEnemies.push_back(orc0);

		vectorOfPointersToObjects.push_back(goblin0);
		vectorOfPointersToObjects.push_back(troll0);
		vectorOfPointersToObjects.push_back(orc0);

		HealthPotion* heal0 = new HealthPotion(&playingField->field[13][7]);
		PowerPotion* power0 = new PowerPotion(&playingField->field[2][8]);
		MandalorianArmor* armor0 = new MandalorianArmor(&playingField->field[3][13]);
		Battery* battery0 = new Battery(&playingField->field[7][12]);

		vectorOfPointersToItems.push_back(heal0);
		vectorOfPointersToItems.push_back(power0);
		vectorOfPointersToItems.push_back(armor0);
		vectorOfPointersToItems.push_back(battery0);

		vectorOfPointersToObjects.push_back(heal0);
		vectorOfPointersToObjects.push_back(power0);
		vectorOfPointersToObjects.push_back(armor0);
		vectorOfPointersToObjects.push_back(battery0);
	}

	void logPlayer() {

		gameLog2.logObject(vectorOfPointersToObjects[0]);
		std::cout << gameLog2;
		filelog.open("filelog.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		filelog << gameLog2;
		filelog.close();
	}

	void logEnemies() {

		filelog.open("filelog.txt", std::fstream::in | std::fstream::out | std::fstream::app);

		gameLog2.logObject(vectorOfPointersToObjects[1]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		gameLog2.logObject(vectorOfPointersToObjects[2]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		gameLog2.logObject(vectorOfPointersToObjects[3]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		filelog.close();
	}

	void logItems() {

		filelog.open("filelog.txt", std::fstream::in | std::fstream::out | std::fstream::app);

		gameLog2.logObject(vectorOfPointersToObjects[4]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		gameLog2.logObject(vectorOfPointersToObjects[5]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		gameLog2.logObject(vectorOfPointersToObjects[6]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		gameLog2.logObject(vectorOfPointersToObjects[7]);
		std::cout << gameLog2.tempstrNew2;
		filelog << gameLog2;

		filelog.close();
	}

	void ResizeView(const sf::RenderWindow& window, sf::View& view)// развЄртка окна с маштабированием
	{
		float aspectRatio = float(window.getSize().x / float(window.getSize().y));
		view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
	}

	void setObjects();

	void setField() {
		int height = 15;
		int width = 15;

		playingField = new Field(width, height);

		//Field field0(field1);
		//field0 = field1;

		playingField->setEntry(2, 2);
		playingField->setExit(1, 1);

		int gameMap[15][15] = {
			{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},

			{1,0,0,0,0, 0,0,0,0,0, 1,1,1,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,1},

			{1,0,0,0,0, 0,0,0,1,1, 1,1,1,1,1},
			{1,1,1,1,1, 0,0,0,1,0, 0,0,0,0,1},
			{1,0,0,0,1, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1}
		};


		int width0 = playingField->getWidth();
		int height0 = playingField->getHeight();

		for (int i = 0; i < width0; ++i) {
			for (int j = 0; j < height0; ++j) {
				/*if ((i == 0) || (j == 0) || (i == playingField.getWidth() - 1) || (j == playingField.getHeight() - 1)) {
					(playingField)[i][j].setIsPassiable(false);
				}*/
				if (gameMap[i][j] == 1) (*playingField)[j][i].setIsPassiable(false);
			}
		}
	}

	int getNumberOfAliveEnemies() const {
		int counter = 0;
		for (int i = 0; i < vectorOfPointersToEnemies.size(); ++i) {
			if (vectorOfPointersToEnemies[i] != nullptr) ++counter;
		}

		return counter;
	}

	int getNumberOfRemainingItems() const {
		int counter = 0;
		for (int i = 0; i < vectorOfPointersToItems.size(); ++i) {
			if (vectorOfPointersToItems[i] != nullptr) ++counter;
		}

		return counter;
	}

	Field* getPlayingField() { return &playingField; }

	bool isEnemyStillAlive(Enemy::EnemyType type) const {
		bool counter = false;
		for (int i = 0; i < vectorOfPointersToEnemies.size(); ++i) {
			if ((vectorOfPointersToEnemies[i] != nullptr) && (vectorOfPointersToEnemies[i]->getEnemyType() == type))
				counter = true;
		}

		return counter;
	}

	void saveField() {

		std::string width = to_string(playingField->getWidth());
		std::string height = to_string(playingField->getHeight());
		std::string entryX = to_string(playingField->getEntry().x);
		std::string entryY = to_string(playingField->getEntry().y);
		std::string exitX = to_string(playingField->getExit().x);
		std::string exitY = to_string(playingField->getExit().y);

		iniFile.addData("FIELD", "Width", width);
		iniFile.addData("FIELD", "Height", height);
		iniFile.addData("FIELD", "EntryX", entryX);
		iniFile.addData("FIELD", "EntryY", entryY);
		iniFile.addData("FIELD", "ExitX", exitX);
		iniFile.addData("FIELD", "ExitY", exitY);

		for (int i = 0; i < playingField->getWidth(); ++i) {
			std::string row;

			for (int j = 0; j < playingField->getHeight(); ++j) {

				if ((*playingField)[j][i].getIsPassable())
					row += "0";
				else
					row += "1";
			}

			iniFile.addData("FIELD", to_string(i), row);
		}

	}

	void savePlayer() {

		if (vectorOfPointersToObjects[0] != nullptr) {
			IObject* player = dynamic_cast<Player*>(vectorOfPointersToObjects[0]);
			auto playerData = player->printObj();
			int numOfrows = atoi(playerData[1][0].c_str());

			for (int count = 1; count < atoi(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->printObj()[1][0].c_str()); ++count) {
				iniFile.addData("PLAYER", playerData[0][count], playerData[1][count]);
			}
		}
		else iniFile.addData("PLAYER", "", "");

	}

	void saveEnemies() {

		if (vectorOfPointersToEnemies[0] != nullptr) {
			Goblin* goblin = dynamic_cast<Goblin*>(vectorOfPointersToEnemies[0]);
			auto goblinData = goblin->printObj();
			int numOfrows = atoi(goblinData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("GOBLIN", goblinData[0][count], goblinData[1][count]);
			}
		}
		else iniFile.addData("GOBLIN", "", "");

		if (vectorOfPointersToEnemies[1] != nullptr) {
			Troll* troll = dynamic_cast<Troll*>(vectorOfPointersToEnemies[1]);
			auto trollData = troll->printObj();
			int numOfrows = atoi(trollData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("TROLL", trollData[0][count], trollData[1][count]);
			}
		}
		else iniFile.addData("TROLL", "", "");

		if (vectorOfPointersToEnemies[2] != nullptr) {
			Orc* orc = dynamic_cast<Orc*>(vectorOfPointersToEnemies[2]);
			auto orcData = orc->printObj();
			int numOfrows = atoi(orcData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("ORC", orcData[0][count], orcData[1][count]);
			}
		}
		else iniFile.addData("ORC", "", "");
	}

	void saveItems() {
		if (vectorOfPointersToItems[0] != nullptr) {
			HealthPotion* healthPotion = dynamic_cast<HealthPotion*>(vectorOfPointersToItems[0]);
			auto healthPotionData = healthPotion->printObj();
			int numOfrows = atoi(healthPotionData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("HEALTH_POTION", healthPotionData[0][count], healthPotionData[1][count]);
			}
		}
		else iniFile.addData("HEALTH_POTION", "", "");

		if (vectorOfPointersToItems[1] != nullptr) {
			PowerPotion* powerPotion = dynamic_cast<PowerPotion*>(vectorOfPointersToItems[1]);
			auto powerPotionData = powerPotion->printObj();
			int numOfrows = atoi(powerPotionData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("POWER_POTION", powerPotionData[0][count], powerPotionData[1][count]);
			}
		}
		else iniFile.addData("POWER_POTION", "", "");

		if (vectorOfPointersToItems[2] != nullptr) {
			MandalorianArmor* mandalorianArmor = dynamic_cast<MandalorianArmor*>(vectorOfPointersToItems[2]);
			auto mandalorianArmorData = mandalorianArmor->printObj();
			int numOfrows = atoi(mandalorianArmorData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("MANDALORIAN_ARMOR", mandalorianArmorData[0][count], mandalorianArmorData[1][count]);
			}
		}
		else iniFile.addData("MANDALORIAN_ARMOR", "", "");

		if (vectorOfPointersToItems[3] != nullptr) {
			Battery* battery = dynamic_cast<Battery*>(vectorOfPointersToItems[3]);
			auto batteryData = battery->printObj();
			int numOfrows = atoi(batteryData[1][0].c_str());

			for (int count = 1; count < numOfrows; ++count) {
				iniFile.addData("BATTARY", batteryData[0][count], batteryData[1][count]);
			}
		}
		else iniFile.addData("BATTARY", "", "");
	}

	void save() {

		saveField();
		savePlayer();
		saveEnemies();
		saveItems();

		iniFile.save();

		/*

		tempstrNew += newIt->second[0][0];

		for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {

			tempstrNew += newIt->second[0][0];

			for (int count = 1; count < atoi(newIt->second[1][0].c_str()); ++count) {
				if (newIt->second[1][count] != oldIt->second[1][count]) {
					tempstrNew += newIt->second[0][count];
					tempstrNew += newIt->second[1][count];
					++count;
				}
			}

			tempstrNew += "\n";
		}

		deleteOldData();
		updateOldData();
		return tempstrNew;
	
		iniFile.addData("PLAYER", "attack", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getAttack()));
		iniFile.addData("PLAYER", "defence", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getDefence()));
		iniFile.addData("PLAYER", "energy", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getEnergy()));
		iniFile.addData("PLAYER", "health", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getHealth()));
		iniFile.addData("PLAYER", "positionX", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getCellPointer()->getPosition().x));
		iniFile.addData("PLAYER", "positionY", std::string(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getCellPointer()->getPosition().y));

		iniFile.addData("GOBLIN", "attack", std::string(vectorOfPointersToEnemies[0]->getAttack()));
		iniFile.addData("GOBLIN", "defence", std::string(vectorOfPointersToEnemies[0])->getDefence());
		iniFile.addData("GOBLIN", "health", std::string(vectorOfPointersToEnemies[0])->getHealth());
		iniFile.addData("GOBLIN", "positionX", std::string(vectorOfPointersToEnemies[0])->getCellPointer()->getPosition().x);
		iniFile.addData("GOBLIN", "positionY", std::string(vectorOfPointersToEnemies[0])->getCellPointer()->getPosition().y);

		iniFile.addData("TROLL", "attack", std::string(vectorOfPointersToEnemies[1]->getAttack()));
		iniFile.addData("TROLL", "defence", std::string(vectorOfPointersToEnemies[1])->getDefence());
		iniFile.addData("TROLL", "health", std::string(vectorOfPointersToEnemies[1])->getHealth());
		iniFile.addData("TROLL", "positionX", std::string(vectorOfPointersToEnemies[1])->getCellPointer()->getPosition().x);
		iniFile.addData("TROLL", "positionY", std::string(vectorOfPointersToEnemies[1])->getCellPointer()->getPosition().y);

		iniFile.addData("ORC", "attack", std::string(vectorOfPointersToEnemies[2]->getAttack()));
		iniFile.addData("ORC", "defence", std::string(vectorOfPointersToEnemies[2])->getDefence());
		iniFile.addData("ORC", "health", std::string(vectorOfPointersToEnemies[2])->getHealth());
		iniFile.addData("ORC", "positionX", std::string(vectorOfPointersToEnemies[2])->getCellPointer()->getPosition().x);
		iniFile.addData("ORC", "positionY", std::string(vectorOfPointersToEnemies[2])->getCellPointer()->getPosition().y);*/


	}

	bool tryGetInt(const std::string &value) {
		try {
			if (value == "not found") return false;
		if (std::stoi(value) == 0)
			if (value[0] != '0')
				return false;
		}
		catch (...) {
			std::cout << "invalid data" << std::endl;
			return false;
		}
		return true;
	}

	void deleteGame() {

		for (int i = 0; i < vectorOfPointersToObjects.size(); ++i) {
			delete vectorOfPointersToObjects[i];
		}

		int size = vectorOfPointersToEnemies.size();
		for (int i = 0; i < size; ++i) {
			vectorOfPointersToEnemies.pop_back();
		}
		size = vectorOfPointersToItems.size();
		for (int i = 0; i < size; ++i) {
			vectorOfPointersToItems.pop_back();
		}
		size = vectorOfPointersToObjects.size();
		for (int i = 0; i < size; ++i) {
			vectorOfPointersToObjects.pop_back();
		}

		delete playingField;
	}

	bool checkFieldData(int height, int width) {

		std::string value;

		int entryX;
		int entryY;
		int exitX;
		int exitY;


		value = iniFile.getData("FIELD", "EntryX");
		if (!tryGetInt(value)) return false;
		else {
			entryX = std::stoi(value);
			if (!(entryX >= 0) && (entryX < width)) return false;
			
		}

		value = iniFile.getData("FIELD", "EntryY");
		if (!tryGetInt(value)) return false;
		else {
			entryY = std::stoi(value);
			if (!(entryY >= 0) && (entryY < width)) return false;
		}

		value = iniFile.getData("FIELD", "ExitX");
		if (!tryGetInt(value)) return false;
		else {
			exitX = std::stoi(value);
			if (!(exitX >= 0) && (exitX < width)) return false;
		}
		
		value = iniFile.getData("FIELD", "ExitY");
		if (!tryGetInt(value)) return false;
		else {
		exitY = std::stoi(value);
		if (!(exitY >= 0) && (exitY < width)) return false;
		}
		


		for (int i = 0; i < width; ++i) {
			std::string rowIndex = to_string(i);
			std::string row = iniFile.getData("FIELD", rowIndex);
			if (!(row.size() == width)) return false;
			for (int j = 0; j < height; ++j) {
				std::string colIndex = row.substr(j, 1);

				if (!(tryGetInt(colIndex)) && ((std::stoi(colIndex) == 0) || (std::stoi(colIndex) == 1)))
					return false;
			}
		}

		return true;
	}

	bool checkPlayerData(int height, int width) {

		std::string value;
		int x;
		int y;
		int attack;
		int defence;
		int energy;
		int health;

		if (!tryGetInt(iniFile.getData("PLAYER", "positionX"))) return false;
		value = iniFile.getData("PLAYER", "positionX");
		x = std::stoi(value);
		if (!((x >= 0) && (x < width))) return false;
	
		if (!tryGetInt(iniFile.getData("PLAYER", "positionY"))) return false;
		value = iniFile.getData("PLAYER", "positionY");
		y = std::stoi(value);
		if (!((y >= 0) && (y < height))) return false;

		if (!tryGetInt(iniFile.getData("PLAYER", "attack"))) return false;
		value = iniFile.getData("PLAYER", "attack");
		attack = std::stoi(value);
		if (! (attack >= 0)) return false;

		if (!tryGetInt(iniFile.getData("PLAYER", "defence"))) return false;
		value = iniFile.getData("PLAYER", "defence");
		defence = std::stoi(value);
		if (!(defence >= 0)) return false;

		if (!tryGetInt(iniFile.getData("PLAYER", "energy"))) return false;
		value = iniFile.getData("PLAYER", "energy");
		energy = std::stoi(value);
		if (! (energy >= 0)) return false;

		if (!tryGetInt(iniFile.getData("PLAYER", "health"))) return false;
		value = iniFile.getData("PLAYER", "health");
		health = std::stoi(value);
		if (!(health >= 0)) return false;

		return true;

	}

	bool checkEnymyData(int height, int width, std::string enymyName) {

		std::string value;
		int x;
		int y;
		int attack;
		int defence;
		int energy;
		int health;

		if (iniFile.getData(enymyName, "") == "") return true;

		if (!tryGetInt(iniFile.getData(enymyName, "positionX"))) return false;
		value = iniFile.getData(enymyName, "positionX");
		x = std::stoi(value);
		if (!((x >= 0) && (x < width))) return false;

		if (!tryGetInt(iniFile.getData(enymyName, "positionY"))) return false;
		value = iniFile.getData(enymyName, "positionY");
		y = std::stoi(value);
		if (!((y >= 0) && (y < height))) return false;

		if (!tryGetInt(iniFile.getData(enymyName, "attack"))) return false;
		value = iniFile.getData(enymyName, "attack");
		attack = std::stoi(value);
		if (!(attack >= 0)) return false;

		if (!tryGetInt(iniFile.getData(enymyName, "defence"))) return false;
		value = iniFile.getData(enymyName, "defence");
		defence = std::stoi(value);
		if (!(defence >= 0)) return false;

		if (!tryGetInt(iniFile.getData(enymyName, "health"))) return false;
		value = iniFile.getData(enymyName, "health");
		health = std::stoi(value);
		if (! (health >= 0)) return false;

		return true;
	}

	bool checkItemsData(int height, int width, std::string itemName) {

		std::string value;

		int x;
		int y;
		int attack;
		int defence;
		int energy;
		int health;


		if (iniFile.getData(itemName, "") == "") return true;

		if (!tryGetInt(iniFile.getData(itemName, "positionX"))) return false;
		value = iniFile.getData(itemName, "positionX");
		x = std::stoi(value);
		if (!( (x >= 0) && (x < width))) return false;

		if (!tryGetInt(iniFile.getData(itemName, "positionY"))) return false;
		value = iniFile.getData(itemName, "positionY");
		y = std::stoi(value);
		if (!((y >= 0) && (y < height))) return false;

		if (itemName == "POWER_POTION") {
			if (!tryGetInt(iniFile.getData(itemName, "attack"))) return false;
			value = iniFile.getData(itemName, "attack");
			attack = std::stoi(value);
			if (!(attack >= 0)) return false;
			return true;
		}

		if (itemName == "MANDALORIAN_ARMOR") {
			if (!tryGetInt(iniFile.getData(itemName, "defence"))) return false;
			value = iniFile.getData(itemName, "defence");
			defence = std::stoi(value);
			if (!(defence >= 0)) return false;
			return true;
		}

		if (itemName == "BATTARY") {
			if (!tryGetInt(iniFile.getData(itemName, "energy"))) return false;
			value = iniFile.getData(itemName, "energy");
			energy = std::stoi(value);
			if (!(energy >= 0)) return false;
			return true;
		}

		if (itemName == "HEALTH_POTION") {
			if (!tryGetInt(iniFile.getData(itemName, "health"))) return false;
			value = iniFile.getData(itemName, "health");
			health = std::stoi(value);
			if (!(health >= 0)) return false;
			return true;
		}

		return false;
	}

	bool checkFail() {

		std::string value;

		int height;
		int width;

		if (!tryGetInt(iniFile.getData("FIELD", "Height"))) return false;
		value = iniFile.getData("FIELD", "Height");
		height = std::stoi(value);
		if (! (height > 2)) return false;

		if (!tryGetInt(iniFile.getData("FIELD", "Width"))) return false;
		value = iniFile.getData("FIELD", "Width");
		width = std::stoi(value);
		if (! (width > 2)) return false;


		if (checkFieldData(height, width) &&
			checkPlayerData(height, width) &&
			checkEnymyData(height, width, "GOBLIN") &&
			checkEnymyData(height, width, "ORC") &&
			checkEnymyData(height, width, "TROLL") &&
			checkItemsData(height, width, "HEALTH_POTION") &&
			checkItemsData(height, width, "BATTARY")&&
			checkItemsData(height, width, "MANDALORIAN_ARMOR")&&
			checkItemsData(height, width, "POWER_POTION")
			)
			return true;
		else return false;
	}

	void loadField() {
		std::string value;
		int x;
		int y;
		int height;
		int width;
		int entryX;
		int entryY;
		int exitX;
		int exitY;

		value = iniFile.getData("FIELD", "Height");
		if (tryGetInt(value))
			height = std::stoi(value);

		value = iniFile.getData("FIELD", "Width");
		if (tryGetInt(value))
			width = std::stoi(value);

		value = iniFile.getData("FIELD", "EntryX");
		if (tryGetInt(value))
			entryX = std::stoi(value);

		value = iniFile.getData("FIELD", "EntryY");
		if (tryGetInt(value))
			entryY = std::stoi(value);

		value = iniFile.getData("FIELD", "ExitX");
		if (tryGetInt(value))
			exitX = std::stoi(value);

		value = iniFile.getData("FIELD", "ExitY");
		if (tryGetInt(value))
			exitY = std::stoi(value);


		playingField =  new Field(height, width);

		playingField->setEntry(entryX, entryY);
		playingField->setExit(exitX, exitY);

		/*int gameMap[15][15] = {
			{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1},

			{1,0,0,0,0, 0,0,0,0,0, 1,1,1,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,1},

			{1,0,0,0,0, 0,0,0,1,1, 1,1,1,1,1},
			{1,1,1,1,1, 0,0,0,1,0, 0,0,0,0,1},
			{1,0,0,0,1, 0,0,0,0,0, 0,0,0,0,1},
			{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
			{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1}
		};*/


		for (int i = 0; i < width; ++i) {
			std::string rowIndex = to_string(i);
			std::string row = iniFile.getData("FIELD", rowIndex);
			//if (tryGetInt(row))
			for (int j = 0; j < height; ++j) {
				std::string colIndex = row.substr(j, 1);
				if (tryGetInt(colIndex))
				if (std::stoi(colIndex) == 1) (*playingField)[j][i].setIsPassiable(false);
			}
		}

		int a = 0;
		//playingField->field = new Cell * [width];
		//for (int i = 0; i < width; ++i) {
		//	playingField->field[i] = new Cell[height];
		//}

		//for (int i = 0; i < width; ++i) {
		//	for (int j = 0; j < width; ++j) {
		//		playingField->field[i][j] = Cell(i, j, playingField);
		//	}
		//}

		/*playingField->setHeight(height);
		playingField->setWidth(width);*/
		
		

	}

	void loadPlayer() {

		std::string value;
		int x;
		int y;

		value = iniFile.getData("PLAYER", "positionX");
		if (tryGetInt(value))
			x = std::stoi(value);

		value = iniFile.getData("PLAYER", "positionY");
		if (tryGetInt(value))
			y = std::stoi(value);

		Player* player = new Player(&(playingField->field[x][y]));
		vectorOfPointersToObjects.push_back(player);

		value = iniFile.getData("PLAYER", "attack");
		if (tryGetInt(value))
			player->setAttack(std::stoi(value) - player->getAttack());

		value = iniFile.getData("PLAYER", "defence");
		if (tryGetInt(value))
			player->setDefence(std::stoi(value) - player->getDefence());

		value = iniFile.getData("PLAYER", "energy");
		if (tryGetInt(value))
			player->setEnergy(std::stoi(value) - player->getEnergy());

		value = iniFile.getData("PLAYER", "health");
		if (tryGetInt(value))
			player->setHealth(std::stoi(value) - player->getHealth());


	}

	void loadGoblin() {

		std::string value;
		int x;
		int y;

		value = iniFile.getData("GOBLIN", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("GOBLIN", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			Goblin* goblin = new Goblin(&(playingField->field[x][y]));
			vectorOfPointersToObjects.push_back(goblin);
			vectorOfPointersToEnemies.push_back(goblin);

			value = iniFile.getData("GOBLIN", "attack");
			if (tryGetInt(value))
				goblin->setAttack(std::stoi(value) - goblin->getAttack());

			value = iniFile.getData("GOBLIN", "defence");
			if (tryGetInt(value))
				goblin->setDefence(std::stoi(value) - goblin->getDefence());

			value = iniFile.getData("GOBLIN", "health");
			if (tryGetInt(value))
				goblin->setHealth(std::stoi(value) - goblin->getHealth());
		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToEnemies.push_back(nullptr);
		}

	}

	void loadTroll() {

		std::string value;
		int x;
		int y;

		value = iniFile.getData("TROLL", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("TROLL", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			Troll* troll = new Troll(&playingField->field[x][y]);
			vectorOfPointersToObjects.push_back(troll);
			vectorOfPointersToEnemies.push_back(troll);

			value = iniFile.getData("TROLL", "attack");
			if (tryGetInt(value))
				troll->setAttack(std::stoi(value) - troll->getAttack());

			value = iniFile.getData("TROLL", "defence");
			if (tryGetInt(value))
				troll->setDefence(std::stoi(value) - troll->getDefence());

			value = iniFile.getData("TROLL", "health");
			if (tryGetInt(value))
				troll->setHealth(std::stoi(value) - troll->getHealth());

		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToEnemies.push_back(nullptr);
		}
	}

	void loadOrc() {

		std::string value;
		int x;
		int y;

		value = iniFile.getData("ORC", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("ORC", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			Orc* orc = new Orc(&playingField->field[x][y]);
			vectorOfPointersToObjects.push_back(orc);
			vectorOfPointersToEnemies.push_back(orc);

			value = iniFile.getData("ORC", "attack");
			if (tryGetInt(value))
				orc->setAttack(std::stoi(value) - orc->getAttack());

			value = iniFile.getData("ORC", "defence");
			if (tryGetInt(value))
				orc->setDefence(std::stoi(value) - orc->getDefence());

			value = iniFile.getData("ORC", "health");
			if (tryGetInt(value))
				orc->setHealth(std::stoi(value) - orc->getHealth());
		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToEnemies.push_back(nullptr);
		}
	}

	void loadItems() {

		std::string value;
		int x;
		int y;

		value = iniFile.getData("HEALTH_POTION", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("HEALTH_POTION", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			HealthPotion* health = new HealthPotion(&playingField->field[x][y]);
			vectorOfPointersToObjects.push_back(health);
			vectorOfPointersToItems.push_back(health);
		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToItems.push_back(nullptr);
		}

		value = iniFile.getData("POWER_POTION", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("POWER_POTION", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			PowerPotion* power = new PowerPotion(&playingField->field[x][y]);
			vectorOfPointersToObjects.push_back(power);
			vectorOfPointersToItems.push_back(power);
		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToItems.push_back(nullptr);
		}

		value = iniFile.getData("MANDALORIAN_ARMOR", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("MANDALORIAN_ARMOR", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			MandalorianArmor* armor = new MandalorianArmor(&(playingField->field[x][y]));
			vectorOfPointersToObjects.push_back(armor);
			vectorOfPointersToItems.push_back(armor);

		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToItems.push_back(nullptr);
		}

		value = iniFile.getData("BATTARY", "positionX");

		if (value != "not found") {

			if (tryGetInt(value))
				x = std::stoi(value);

			value = iniFile.getData("BATTARY", "positionY");
			if (tryGetInt(value))
				y = std::stoi(value);

			Battery* battery = new Battery(&playingField->field[x][y]);
			vectorOfPointersToObjects.push_back(battery);
			vectorOfPointersToItems.push_back(battery);

		}
		else {
			vectorOfPointersToObjects.push_back(nullptr);
			vectorOfPointersToItems.push_back(nullptr);
		}
	}


	bool loading() {
		iniFile.load();

		if (!checkFail()) return false;

		deleteGame();

		loadField();

		loadPlayer();
		loadGoblin();
		loadTroll();
		loadOrc();
		loadItems();

		return true;
	}


	//ќ—Ќќ¬Ќјя ‘”Ќ ÷»я Game

	void run() {

		filelog.open("filelog.txt", std::ofstream::out | std::ofstream::trunc);
		filelog.close();

		//saveMapFile.open("saveMapFile.txt", std::ofstream::out | std::ofstream::trunc);
		//saveMapFile.close();

		//задать поле
		setField();

		//задать объекты
		createObjects();

		//логгер
		gameLog2 = Logger2(vectorOfPointersToObjects[0], vectorOfPointersToObjects[1], vectorOfPointersToObjects[2], vectorOfPointersToObjects[3], vectorOfPointersToObjects[4], vectorOfPointersToObjects[5], vectorOfPointersToObjects[6], vectorOfPointersToObjects[7]);


		while (scene.windowIsOpen())
		{

			const Point& exit = playingField->getExit();
			if ((playingField->field[exit.x][exit.y].getPlayer() == true) &&
				(rule.openTheDoor(this)) ||
				(dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getHealth() <= 0)) {
				std::cout << "game over"; break;
			}

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			//time = time/ 1000;
			//if (time > 0)
				//time = 0.5;

			scene.windowPollEvent();

			dynamic_cast<Player*>(vectorOfPointersToObjects[0])->move(input.movement());

			logPlayer();

			moveEnemy();

			logEnemies();


			if ((dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getCellPointer()->getItem()) && (tryPicUp())) { dynamic_cast<Player*>(vectorOfPointersToObjects[0])->pickUp(vectorOfPointersToObjects[0]->getCellPointer()->getItemPointer(), vectorOfPointersToItems); }

			logPlayer();
			logItems();


			if ((dynamic_cast<Player*>(vectorOfPointersToObjects[0])->getCellPointer()->getEnemy()) && (tryFight())) { dynamic_cast<Player*>(vectorOfPointersToObjects[0])->fighting(vectorOfPointersToObjects[0]->getCellPointer()->getEnemyPointer(), vectorOfPointersToEnemies); }

			logPlayer();
			logEnemies();

			if (input.saving()) save();
			if (input.continuePreviousGame()) loading();
			

			sleep(sleepTime);
			scene.draw();
			//////std::cout << gameLog->logAllObjects();

			//std::cout << gameLog;
			//fout.open("file.txt");

			//playerLog->check();
		}
	}
};

