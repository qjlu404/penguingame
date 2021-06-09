#ifndef SFML_STATIC
#define SFML_STATIC
#endif
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape cursor;
    Game game(&window);
    Menu MainMenu(10, 50, "Main Menu");
    MainMenu.append("Play");
    MainMenu.append("Exit");
    MainMenu.show();
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
        switch (MainMenu.getItemIndex())
        {
        case 0:
            game.run();
        case 1:
            return 0;
        default:
            break;
        }
        MainMenu.update(window);
        cursor.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        window.clear(sf::Color::Color(30,0,0,255));
        MainMenu.draw(&window);
        window.draw(cursor);
        window.display();
    }

    return 0;
}