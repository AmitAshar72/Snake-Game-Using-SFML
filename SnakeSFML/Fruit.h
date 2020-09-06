#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
class Fruit
{
public:
	Fruit(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake); //spawns fruit in a new location
	void Draw(Board& brd, sf::Sprite& sp) const; //draws fruit on the board
	bool isInTile(const location& in_loc) const; // checks if the fruit is in the tile/cell
	const location& GetLocation() const;
private:
	
	sf::Color c = sf::Color::Red;
	location loc;

};

