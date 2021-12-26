//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "Graphics.h"
//
//enum ControlButtons {
//	LEFT,
//	UP,
//	RIGHT,
//	DOWN
//};
//
//class Input {
//
//private:
//
//	sf::RenderWindow* m_window;
//	sf::Event event;
//	bool m_closeButtonPressed;
//	char buttonList[4];
//	bool pressedButton[255];
//
//public:
//
//	Input();
//	Input(Graphics graphics);
//	void setWindow(sf::RenderWindow* window);
//	void update();
//	bool pressed(ControlButtons button);
//	bool closeButtonPressed();
//};


#pragma once

#include "Field/Field.h"
#include "Point.h"
#include <vector>
#include <iostream>
#include <string>


class IGame;

class Input
{
private:
	Point coordinateShift;
	IGame* game;

public:
	Input(IGame* game);
	Point movement();
	bool saving();
	bool continuePreviousGame();

};
