#pragma once
#ifndef SFML_STATIC
#define SFML_STATIC
#endif
#include "SFML/Graphics.hpp"
class Penguin
{
	sf::Texture ppng;
	sf::Sprite penguin;
public:
	void draw(sf::RenderWindow* window);
	Penguin();
};

