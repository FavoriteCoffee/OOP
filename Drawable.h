#pragma once
#include <SFML/Graphics.hpp>
#include <String>
#include "Point.h"
class Drawable {
protected:
	Point windowPosition;
	Point origin;
	int spriteRotation;
	std::string m_filePath;
public:
	Drawable();
	Drawable(std::string filePath);
	virtual Point getWindowPosition();
	virtual void setWindowPosition(Point point);
	virtual int getSpriteRotation();
	virtual std::string getTextureFilePath();
	virtual Point getOrigign();
	virtual sf::Texture* getTexture();
};
