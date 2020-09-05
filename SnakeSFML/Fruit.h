#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
class Fruit
{
public:
	Fruit(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd, sf::Sprite& sp) const;
	bool isInTile(const location& in_loc) const;
	const location& GetLocation() const;
private:
	//sf::Texture ft;
	sf::Color c = sf::Color::Red;
	location loc;

};

