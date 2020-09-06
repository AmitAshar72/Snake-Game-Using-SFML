#include "Fruit.h"

Fruit::Fruit(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);	
}

void Fruit::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);

	location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.isInTile(newLoc));

	loc = newLoc;
}

void Fruit::Draw(Board & brd, sf::Sprite& sp) const
{
	brd.DrawSprite(loc, &sp);
}

bool Fruit::isInTile(const location & in_loc) const
{
	return loc == in_loc;
}

const location & Fruit::GetLocation() const
{
	return loc;
}
