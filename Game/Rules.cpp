#pragma once

#include "Game.h"
#include "Rules.h"

bool Rule1::openTheDoor(const Game<Rule1>* game) const {
	//std::cout << game->getNumberOfAliveEnemies();

	if (game->getNumberOfAliveEnemies() == 0) {
		return true;
	}
	else {
		return false;
	}
}


bool Rule2::openTheDoor(const Game<Rule2>* game) const {
	if (!game->isEnemyStillAlive(Enemy::EnemyType::ORC)) {
		return true;
	}
	else return false;
}


bool Rule3::openTheDoor(const Game<Rule3>* game) const {
	if (game->getNumberOfRemainingItems() == 0) {
		return true;
	}
	else return false;
}
