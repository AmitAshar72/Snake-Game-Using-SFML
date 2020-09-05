#include "Menu.h"

Menu::Menu(float width, float height, sf::RenderWindow& window):	
	win(window)
{
	if (!font.loadFromFile("font.ttf"))
	{
		//error
	}	

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Start");
	menu[0].setPosition(sf::Vector2f(width / 2 - (offset*2), height / 4 * 1));
	menu[0].setCharacterSize(30);
	menu[0].setStyle(sf::Text::Bold);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2 -offset, height / 4 * 2));
	menu[1].setCharacterSize(30);
	menu[1].setStyle(sf::Text::Bold);	

	selectedIndex = 0;
	
}

void Menu::draw()
{
	
	for (int i=0;i<MAX_CONTENTS;i++)
	{		
		win.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedIndex - 1 >= 0)
	{
		menu[selectedIndex].setFillColor(sf::Color::White);
		--selectedIndex;
		menu[selectedIndex].setFillColor(sf::Color::Green);
	}
}

void Menu::moveDown()
{
	if (selectedIndex + 1 < MAX_CONTENTS)
	{
		menu[selectedIndex].setFillColor(sf::Color::White);
		++selectedIndex;
		menu[selectedIndex].setFillColor(sf::Color::Green);
	}
}

int Menu::getSelectedIndex()
{
	return selectedIndex;
}
