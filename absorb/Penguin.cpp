#include "Penguin.h"
#include <cmath>
#include <Windows.h>
#include <iostream>

void Penguin::update()
{
    if (direction)
    {
        waddleangle -=  60 / waddleangle;
        if (abs(waddleangle) > waddlemax)
            direction = 0;
    }
    if (!direction)
    {
        waddleangle += 3;
        if (abs(waddleangle) > waddlemax)
            direction = 1;
    }
    penguin.setRotation(waddleangle);
}
Penguin::Penguin() : ppng(), penguin()
{
    if (ppng.loadFromFile("textures/penguion.png"))
    {
        penguin.setTexture(ppng);
    }
    else
    {
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
        std::cerr << "\n from class Game: error loading some images\n";
        std::string a;
        std::cout << "press enter to continue\n";
        std::getline(std::cin, a);
        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
        penguin.setColor(sf::Color::Color(100, 100, 100, 255));
        penguin.setPosition(100, 100);
    }
    waddlemax = 20;
    direction = 0;
    waddleangle = 0;
    penguin.setPosition(400, 600);
    penguin.setScale(.2, .2);
    penguin.setOrigin(261, 1000);
}

void Penguin::draw(sf::RenderWindow* window)
{
    window->draw(penguin);
}