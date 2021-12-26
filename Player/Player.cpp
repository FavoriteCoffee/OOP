#pragma once
#include<cstdlib>
#include<iostream>
#include "Field/Cell.h"
#include "IObject.h"
#include "Player.h"
#include "Enemys/Enemy.h"
#include "Field/Field.h"
#include<string>


void Player::setHealth(int hp) {
	health += hp;
}

void Player::setDefence(int def) {
	defence += def;
}

void Player::setAttack(int atk) {
	attack += atk;
}

void Player::setEnergy(int enrg) {
	energy += enrg;
}

void Player::move(Point moveKey) {

	if (moveKey.x || moveKey.y) {

		Point destination = cellPointer->getPosition();

			if ((cellPointer->getFieldPointer()->field[cellPointer->getPosition().x + moveKey.x][cellPointer->getPosition().y + moveKey.y].getIsPassable()) &&
				(cellPointer->getPosition().x + moveKey.x >= 0) &&
				(cellPointer->getPosition().y + moveKey.y >= 0) &&
				(cellPointer->getPosition().x + moveKey.x < cellPointer->getFieldPointer()->getWidth()) &&
				(cellPointer->getPosition().y + moveKey.y < cellPointer->getFieldPointer()->getHeight())) {

				destination.x = cellPointer->getPosition().x + moveKey.x;
					destination.y = cellPointer->getPosition().y + moveKey.y;
			}


		cellPointer->setPlayerPointer(nullptr);
		cellPointer->getFieldPointer()->field[destination.x][destination.y].setPlayerPointer(this);

		cellPointer = &(cellPointer->getFieldPointer()->field[destination.x][destination.y]);
	}
}


void Player::move(IObject::moveKey setMoveKey) {

	Point destination = cellPointer->getPosition();
	switch (setMoveKey)
	{
	case IObject::moveKey::LEFT:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x - 1][getCellPointer()->getPosition().y].getIsPassable()) &&
			(cellPointer->getPosition().x - 1 >= 0) &&
			(cellPointer->getPosition().x - 1 < cellPointer->getFieldPointer()->getWidth())) {

			destination.x = cellPointer->getPosition().x - 1;
			destination.y = getCellPointer()->getPosition().y;
		}
		break;

	case IObject::moveKey::UP:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y - 1].getIsPassable()) &&
			(cellPointer->getPosition().y - 1 >= 0) &&
			(cellPointer->getPosition().y - 1 < cellPointer->getFieldPointer()->getHeight())) {

			destination.x = getCellPointer()->getPosition().x;
			destination.y = getCellPointer()->getPosition().y - 1;
		}
		break;

	case IObject::moveKey::RIGHT:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x + 1][getCellPointer()->getPosition().y].getIsPassable()) &&
			(cellPointer->getPosition().x + 1 >= 0) &&
			(cellPointer->getPosition().x + 1 < cellPointer->getFieldPointer()->getWidth())) {

			destination.x = cellPointer->getPosition().x + 1;
			destination.y = getCellPointer()->getPosition().y;
		}
		break;
	case IObject::moveKey::DOWN:
		if ((cellPointer->getFieldPointer()->field[getCellPointer()->getPosition().x][getCellPointer()->getPosition().y + 1].getIsPassable()) &&
			(cellPointer->getPosition().y + 1 >= 0) &&
			(cellPointer->getPosition().y + 1 < cellPointer->getFieldPointer()->getHeight())) {

			destination.x = getCellPointer()->getPosition().x;
			destination.y = getCellPointer()->getPosition().y + 1;
		}
		break;
	}

	cellPointer->setPlayerPointer(nullptr);
	cellPointer->getFieldPointer()->field[destination.x][destination.y].setPlayerPointer(this);

	cellPointer = &(cellPointer->getFieldPointer()->field[destination.x][destination.y]);
}

Player::Player(Cell* cell) {
	health = 15;
	defence = 2;
	attack = 5;
	energy = 7;
	cellPointer = cell;
	cellPointer->setPlayerPointer(this);
}

void Player::pickUp(Item* item, std::vector <Item*>& vectorOfPointersToItems) {

	if (item->getItemType() == Item::ItemType::BATTARY) energy += item->getValue();
	else if (item->getItemType() == Item::ItemType::HEALTH_POTION) health += item->getValue();
	else if (item->getItemType() == Item::ItemType::MANDALORIAN_ARMOR) defence += item->getValue();
	else if (item->getItemType() == Item::ItemType::POWER_POTION) attack += item->getValue();
	item->removeFromField();
	for (int i = 0; i < vectorOfPointersToItems.size(); ++i) {
		if (vectorOfPointersToItems[i] == item) vectorOfPointersToItems[i] = nullptr;
	}
}

bool Player::fighting(Enemy* enemy, std::vector<Enemy*>& vectorOfPointersToEnemies) {

	if (energy > 0) {

		--energy;

		if (attack > enemy->getDefence()) {

			enemy->setHealth(enemy->getDefence() - attack);

			if (enemy->getHealth() <= 0) {
				enemy->removeFromField();

				for (int i = 0; i < vectorOfPointersToEnemies.size(); ++i) {
					if ((vectorOfPointersToEnemies[i] != nullptr) && (vectorOfPointersToEnemies[i]->getEnemyType() == enemy->getEnemyType())) {
						vectorOfPointersToEnemies[i] = nullptr;
						//vectorOfPointersToEnemies.erase(vectorOfPointersToEnemies.begin() + i);
					}

				}

				return true;
			}
		}

		if (enemy->getAttack() > defence) {

			setHealth(defence - enemy->getAttack());

			if (health > 0) return true;
			else return false;
		}

		return true;
	}
	else {

		health = 0;
		return false;
	}

	//if (energy > 0) {

	//	energy -= 1;

	//	if (attack > enemy->getDefence()) {

	//		enemy->setHealth(enemy->getDefence() - attack);
	//		if (enemy->getHealth() <= 0) {
	//			enemy->removeFromField();
	//			for (int i = 0; i < vectorOfPointersToEnemies.size(); ++i) {
	//				if (vectorOfPointersToEnemies[i]->getEnemyType() == enemy->getEnemyType()) {
	//					vectorOfPointersToEnemies[i] = nullptr;
	//					//vectorOfPointersToEnemies.erase(vectorOfPointersToEnemies.begin() + i);
	//				}

	//			}
	//				
	//			//std::cout << "e died" << std::endl;
	//			//std::cout << "u win"<< std::endl;
	//			return true;
	//		}
	//	}
	//	if (enemy->getAttack() > defence) {

	//		setHealth(defence - enemy->getAttack());
	//		if (health > 0) return true;
	//		else {
	//			//std::cout << "game over" << std::endl;
	//			return false;
	//		}
	//	}
	//	//std::cout << "u win" << std::endl;
	//	return true;
	//}
	//else {
	//	//std::cout << "game over" << std::endl;
	//	health = 0;
	//	return false;
	//}
}

void Player::setCellPointer(Cell* newCell) {
	cellPointer = newCell;
}

//				if (attack > (2 * enemy.getDefence())) enemy.setHealth(enemy.getHealth() / 2);
//				else if (attack > enemy.getDefence()) enemy.setHealth(enemy.getHealth() - 1);
//
//				if (!enemy.getHealth()) {
//
//					if (enemy.getAttack() > (2 * defence)) health = health / 2;
//					else if (enemy.getAttack() > defence) --health;
//				}
//				else break;
//			}
//		}
//		else 
//			if (health + defence + attack > enemy.getAttack() + enemy.getDefence() + enemy.getHealth())
//				enemy.setHealth(0);
//			else if (rand() % 2) { 
//				enemy.setHealth(0);
//				return true;
//				//enemy.deleteObj(); !!!!!!!!!!
//			}
//			else {
//				health = 0;
//				return false;
//			}
//			
//		
//		if (health) {
//			--energy;
//			return true;
//			field[enemy.getPosition().x][enemy.getPosition().y].setLinkEnemy(); !!!!!!!!!!!!!!!!!
//		}
//		else return false;
//	}
//	else health = 0;
//	return false;
//}

void Player::removeFromField() {
	cellPointer->setEnemyPointer(nullptr);
}

std::string** Player::printObj() const {

		std::string** tempStr = new std::string * [2];
		for (int i = 0; i < 2; ++i) {
			tempStr[i] = new std::string[7];
		}
		if (cellPointer != nullptr)
		{
			tempStr[0][0] = "PLAYER";
			tempStr[1][0] = "7";
			tempStr[0][1] = "positionX";
			tempStr[1][1] = std::to_string(cellPointer->getPosition().x);
			tempStr[0][2] = "positionY";
			tempStr[1][2] =  std::to_string(cellPointer->getPosition().y);
			tempStr[0][3] = "health";
			tempStr[1][3] = std::to_string(health);
			tempStr[0][4] = "defence";
			tempStr[1][4] = std::to_string(defence);
			tempStr[0][5] = "attack";
			tempStr[1][5] = std::to_string(attack);
			tempStr[0][6] = "energy";
			tempStr[1][6] = std::to_string(energy);
		}
		//std::string tempStr = "PLAYER: (" + std::to_string(cellPointer->getPosition().x) + ";" + std::to_string(cellPointer->getPosition().y) +
		//	", health: " + std::to_string(health) +
		//	", defence : " + std::to_string(defence) +
		//	", attack: " + std::to_string(attack) +
		//	", energy: " + std::to_string(energy);
		else
		{
			tempStr[0][0] = "PLAYER";
			tempStr[1][0] = "2";
			tempStr[1][1] = "die";
		}

		return tempStr;

}

std::string Player::printObj2() const {

	std::string resStr = "";

	if (cellPointer != nullptr)
	{
		resStr = "[ PLAYER: ] \n";
		resStr += "position: ";
		resStr += std::to_string(cellPointer->getPosition().x) + " , " + std::to_string(cellPointer->getPosition().y) + " ";;
		resStr += "health: ";
		resStr += std::to_string(health) + " ";
		resStr += "defence: ";
		resStr += std::to_string(defence) + " ";
		resStr += "attack: ";
		resStr += std::to_string(attack) + " ";
		resStr += "energy: ";
		resStr += std::to_string(energy) + " ";

		
	}
	//std::string tempStr = "PLAYER: (" + std::to_string(cellPointer->getPosition().x) + ";" + std::to_string(cellPointer->getPosition().y) +
	//	", health: " + std::to_string(health) +
	//	", defence : " + std::to_string(defence) +
	//	", attack: " + std::to_string(attack) +
	//	", energy: " + std::to_string(energy);
	else
	{
		resStr += "[ PLAYER: ] ";
		resStr += "2";
		resStr += "die";
	}

	return resStr;

}
//
//std::string convertObjectToString(IObject* obj) const {
//	if (obj != nullptr) {
//
//	}
//}
