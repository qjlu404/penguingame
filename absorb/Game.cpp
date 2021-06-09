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
    switch (exitmenu.getItemIndex())
    {
    case 0:
        exit(8);
        break;
    case 1:
        wexit = true;
    case 2:
        exitmenu.hide();
        exitmenu.clearitemindex();
        break;
    }
    cursor.setPosition(sf::Mouse::getPosition(*window).x,
                       sf::Mouse::getPosition(*window).y);

    exitmenu.update(window);
    player.update();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        exitmenu.show();
    }
}
void Game::render()
{
    window->clear(sf::Color(0,200,255,200));
    player.draw(window);
    exitmenu.draw(window);
    window->draw(cursor);
    window->display();
}

// public
Game::Game(sf::RenderWindow* inwin) : player(), exitmenu(10,10, ""), cursor(5)
{
    window = inwin;
    wexit = 0;
    exitmenu.append("Cancel");
    exitmenu.append("Main Menu");
    exitmenu.append("Exit");
    cursor.setFillColor(sf::Color::Yellow);
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(3);
}
void Game::run()
{
    while (window->isOpen())
    {
        process();
        update();
        render();
        if (wexit) break;
    }
    wexit = 0;
}