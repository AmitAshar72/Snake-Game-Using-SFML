#pragma once
#include <SFML\Graphics.hpp>
#define MAX_CONTENTS 2
class Menu
{
public:
	Menu(float width, float height, sf::RenderWindow& window);
	void draw();
	void moveUp();
	void moveDown();
	int getSelectedIndex();
private:
	int selectedIndex;	
	static constexpr float offset = 10.0f;
	sf::RenderWindow& win;
	sf::Font font;
	sf::Text menu[MAX_CONTENTS];

};

