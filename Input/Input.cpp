

#include <iostream>
#include "Game/IGame.h"
#include "Field/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "Input.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

using namespace sf;

Input::Input(IGame* setGame): game(setGame) {
	coordinateShift = Point(0, 0);
}


Point Input::movement() {

	coordinateShift.x = 0;
	coordinateShift.y = 0;

	if (Keyboard::isKeyPressed(Keyboard::Left)) { coordinateShift.x -= 1;}
	if (Keyboard::isKeyPressed(Keyboard::Up)) { coordinateShift.y -= 1; }
	if (Keyboard::isKeyPressed(Keyboard::Right)) { coordinateShift.x += 1; }
	if (Keyboard::isKeyPressed(Keyboard::Down)) { coordinateShift.y += 1; }

	if (Keyboard::isKeyPressed(Keyboard::A)) { coordinateShift.x -= 1; }
	if (Keyboard::isKeyPressed(Keyboard::W)) { coordinateShift.y -= 1; }
	if (Keyboard::isKeyPressed(Keyboard::D)) { coordinateShift.x += 1; }
	if (Keyboard::isKeyPressed(Keyboard::S)) { coordinateShift.y += 1; }

	return coordinateShift;
}


bool Input::saving() {
	bool res = false;
	if (Keyboard::isKeyPressed(Keyboard::Z)) { res = true; }
	return res;
}

bool Input::continuePreviousGame() {
	bool res = false;
	if (Keyboard::isKeyPressed(Keyboard::X)) { res = true; }
	return res;
}