#pragma once
#ifndef SFML_STATIC
#define SFML_STATIC
#endif
#include "SFML/Graphics.hpp"
#include "Menu.h"
class Penguin
{
	sf::Texture ppng;
	float waddlemax;
	float waddleangle;
	bool direction;
public:
	sf::Sprite penguin;
	void update();
	void draw(sf::RenderWindow* window);
	Penguin();
};

