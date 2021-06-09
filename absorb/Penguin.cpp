#include "Penguin.h"
#include <Windows.h>
#include <iostream>

Penguin::Penguin() : ppng(), penguin()
{
    if (ppng.loadFromFile("textures/pengguion.png"))
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
    }
}

void Penguin::draw()
{

}