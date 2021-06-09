#pragma once
#include "Menu.h"
#include <Windows.h>
#include <iostream>
Menu::Menu() : font(), menu(), border()
{
    selecteditem = -1;
    visible = 0;
    if (font.loadFromFile("./fonts/impact.ttf"))
    {
        menuname.setFont(font);
    }
    else
    {
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
        std::cerr << "error loading fonts\n";
        std::string a;
        std::cout << "press enter to continue\n";
        std::getline(std::cin, a);
        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    }
    border.setPosition(10, 10);
    border.setFillColor(sf::Color::Color(50, 50, 255, 150));
}
Menu::Menu(float x, float y, std::string title) : font(), menu(), border(), menuname()
{
    if (font.loadFromFile("./fonts/impact.ttf"))
    {
        menuname.setFont(font);
    }
    else
    {
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
        std::cerr << "from class Menu: error loading fonts\n";
        std::string a;
        std::cout << "press enter to continue\n";
        std::getline(std::cin, a);
        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    }
    visible = 0;
    selecteditem = -1;
    border.setPosition(x, y);
    border.setFillColor(sf::Color::Color(50, 50, 255, 150));
    menuname.setString(title);
    menuname.setFillColor(sf::Color::White);
    menuname.setOutlineColor(sf::Color::Black);
    menuname.setOutlineThickness(10);
    menuname.setPosition(border.getPosition().x + 150 + menuname.getCharacterSize() / 2, border.getPosition().y - 20);

}
void Menu::append(std::string txt)
{
    //rectangles
    sf::RectangleShape itembg;
    itembg.setPosition(border.getPosition().x + 50, border.getPosition().y + 50 + 40 * menu.size());
    itembg.setSize(sf::Vector2f(200, 40));
    itembg.setFillColor(sf::Color::Blue);
    itembg.setOutlineColor(sf::Color::Black);
    itembg.setOutlineThickness(3);

    //text
    sf::Text menuitem;
    menuitem.setFont(font);
    menuitem.setPosition(itembg.getPosition().x + 30, itembg.getPosition().y + 5);
    menuitem.setFillColor(sf::Color::White);
    menuitem.setString(txt);

    //updating
    rects.push_back(itembg);
    menu.push_back(menuitem);
    border.setSize(sf::Vector2f(300, 40 + menu.size() * 60));
}
void Menu::update(sf::RenderWindow& window)
{
    if (visible)
    {
        for (size_t i = 0; i < rects.size(); i++)
        {
            if (sf::Mouse::getPosition(window).x > rects[i].getPosition().x
                && sf::Mouse::getPosition(window).y > rects[i].getPosition().y
                && sf::Mouse::getPosition(window).x < rects[i].getPosition().x + rects[i].getSize().x
                && sf::Mouse::getPosition(window).y < rects[i].getPosition().y + rects[i].getSize().y)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    rects[i].setFillColor(sf::Color::Green);
                    selecteditem = (short)i;
                }
                else
                {
                    rects[i].setFillColor(sf::Color::Yellow);
                }

            }
            else
            {
                rects[i].setFillColor(sf::Color::Blue);
            }
        }
    }
    border.setSize(sf::Vector2f(300, 40 + menu.size() * 60));
}
void Menu::draw(sf::RenderWindow& window)
{
    if (visible)
    {
        window.draw(border);
        window.draw(menuname);
        for (size_t i = 0; i < rects.size(); i++)
            window.draw(rects[i]);
        for (size_t i = 0; i < menu.size(); i++)
            window.draw(menu[i]);
    }
}
short Menu::getItemIndex()
{
    return selecteditem;
}
void Menu::show()
{
    visible = 1;
}
void Menu::hide()
{
    visible = 0;
}