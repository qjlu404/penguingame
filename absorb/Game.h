#ifndef SFML_STATIC
#define SFML_STATIC
#endif
#include "Menu.h"
#include "Penguin.h"
#include <Windows.h>
#include <vector>
class Game
{
	sf::RenderWindow* window;
	Penguin player;
	void process();
	void update();
	void render();
public:
	Game(sf::RenderWindow* inwin);
	void run();
};
