#pragma once
#include <SFML\Graphics.hpp>
#include "location.h"
#include "Animation.h"
#include <random>
class Board
{
public:
	Board(sf::RenderWindow& win);
	void DrawCell(const location& loc, sf::Color);
	void DrawSprite(const location& loc, sf::Sprite* _sprite);
	int GetGridWidth() const;
	int GetGridHeight() const;
	sf::RectangleShape getBoard();
	bool isInsideBoard(const location& loc);
	bool CheckForObstacle(const location& loc) const;
	void SpawnObstacle(std::mt19937& rng, const class Snake& snake, const class Fruit& fruit);
	void DrawBorder();
	void DrawObstacles(sf::Sprite& obs);
	void DrawFruit(const location& loc,sf::Sprite& obs);
	void animation(float del);
private:
	
private:
	sf::RenderWindow& win;	
	sf::Sprite obstac,_sprite;
	sf::Vector2u tex= sf::Vector2u(3,1);
	
	sf::Texture obst;
	//Animation anim;
	static constexpr int cellsize = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int x = 150;
	static constexpr int y = 50;
	static constexpr int borderwidth = 3;
	static constexpr int borderpadding = 1;
	
	bool checkObs[width*height] = { false };
	sf::Color bordercolor = sf::Color::Blue;
	sf::Color poisonColor = sf::Color(128.0f, 128.0f, 128.0f);
	sf::RectangleShape board;	
	sf::RectangleShape border[4];
	
};

