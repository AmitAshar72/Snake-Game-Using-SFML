#pragma once
#include <SFML\Graphics.hpp>
#include "location.h"
#include "Animation.h"
#include <random>
class Board
{
public:
	Board(sf::RenderWindow& win); 
	void DrawCell(const location& loc, sf::Color); // draws rect to the grid
	void DrawSprite(const location& loc, sf::Sprite* _sprite); //draws sprite to the grid
	int GetGridWidth() const;
	int GetGridHeight() const;
	sf::RectangleShape getBoard();
	bool isInsideBoard(const location& loc); //checks if within the boundary values
	bool CheckForObstacle(const location& loc) const; //function checks if obstacles have occupied a grid space
	void SpawnObstacle(std::mt19937& rng, const class Snake& snake, const class Fruit& fruit);
	//spawns obstacles randomly and not on the space where snake or fruit has occupied
	void DrawBorder(); 
	void DrawObstacles(sf::Sprite& obs);
	void DrawFruit(const location& loc,sf::Sprite& obs);	//draws pickups/fruits
private:
	
private:
	sf::RenderWindow& win;	//stores reference to the window screen 

	sf::Color bordercolor = sf::Color::Blue;
	sf::Color poisonColor = sf::Color(128.0f, 128.0f, 128.0f);
	sf::RectangleShape board;
	sf::RectangleShape border[4];

	static constexpr int cellsize = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int x = 150;
	static constexpr int y = 50;
	static constexpr int cellPadding = 1;
	static constexpr int borderwidth = 3;
	static constexpr int borderpadding = 1;

	bool checkObs[width*height] = { false }; //bool array for the gridspace
	
};

