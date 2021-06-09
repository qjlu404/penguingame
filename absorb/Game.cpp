#include "Game.h"
#include <iostream>
#include <Windows.h>
void Game::process()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
void Game::update()
{
}
void Game::render()
{
    window->clear(sf::Color(0,200,255,200));
    window->draw(player.penguin);
    window->display();
}

// public
Game::Game(sf::RenderWindow* inwin) : player()
{
    window = inwin;
    window->setMouseCursorVisible(1);
}
void Game::run()
{
    while (window->isOpen())
    {
        process();
        update();
        render();
    }
}