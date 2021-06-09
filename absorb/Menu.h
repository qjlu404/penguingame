#pragma once
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Menu
{
    sf::Font font;
    sf::Text menuname;
    sf::RectangleShape border;
    std::vector<sf::Text> menu;
    std::vector<sf::RectangleShape> rects;
    bool visible;
    short selecteditem;

public:
    Menu();
    Menu(float x, float y, std::string title);
    void append(std::string txt);
    void update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
    sf::Vector2f getsize();
    void clearitemindex();
    short getItemIndex();
    bool isvisible();
    void show();
    void hide();
};