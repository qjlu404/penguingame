#ifndef SFML_STATIC
#define SFML_STATIC
#endif
#include <SFML/Graphics.hpp>
#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape cursor;
    Menu MainMenu(10, 100, "Main Menu");
    MainMenu.append("Play");
    MainMenu.append("Exit");
    cursor.setRadius(5);
    cursor.setFillColor(sf::Color::Yellow);
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(3);
    window.setMouseCursorVisible(0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        MainMenu.update(window);
        cursor.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        window.clear();
        MainMenu.draw(window);
        window.draw(cursor);
        window.display();
    }

    return 0;
}