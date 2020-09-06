#pragma once
#include <SFML\Graphics.hpp>
#define MAX_CONTENTS 2 //total contents on the menu
class Menu
{
public:
	Menu(float width, float height, sf::RenderWindow& window);
	void draw(); //draws the menu
	void moveUp(); 
	void moveDown();
	//moveUp() and moveDown() for navigation through menus
	int getSelectedIndex(); //receives selectedIndex
private:
	int selectedIndex;	
	static constexpr float offset = 10.0f;
	sf::RenderWindow& win;
	sf::Font font;
	sf::Text menu[MAX_CONTENTS];

};

