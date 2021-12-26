//#pragma once
//
//#include "Drawable.h"
//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//class Graphics {
//private:
//	sf::RenderWindow* window;
//	Drawable** m_objects;
//public:
//	Graphics();
//	Graphics(Drawable** objects);
//	Graphics& operator= (const Graphics& graphics);
//	Graphics(const Graphics& graphics);
//	void update();
//	sf::RenderWindow* getWindow();
//	void close();
//};

//#ifndef GAME_V3_DRAW_H
//#define GAME_V3_DRAW_H

#pragma once
//#define PICTURES "pictures.png"
#include "Field/Field.h"
#include "Point.h"
#include <vector>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


//constexpr std::string PICTURES ("pictures.png");

class IGame;

using namespace sf;

static const float VIEW_HEIGHT = 400;

class SFMLScene {
private:
 
    Sprite sprite;
    Font font;
    Text text;
    Texture img;
    RenderWindow window;
    Event event;
    View view;
   // Field playingField;
    const IGame* game;

public:

    SFMLScene(const IGame*);
    SFMLScene() = default;
    void windowPollEvent();
    bool windowIsOpen() const;
    void draw();
    void ResizeView(const sf::RenderWindow& window, sf::View& view);
   
};
//#endif //GAME_V3_DRAW_H