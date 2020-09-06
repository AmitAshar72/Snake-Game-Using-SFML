#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include <assert.h>

Board::Board(sf::RenderWindow & win) :
	win(win)	
{
	board.setSize(sf::Vector2f(cellsize- cellPadding, cellsize- cellPadding));
	
}

void Board::DrawCell(const location & loc, sf::Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	
	const int offsetX = x+borderpadding;
	const int offsetY = y+borderpadding;

	board.setPosition((sf::Vector2f(loc.x*cellsize+offsetX, loc.y*cellsize+offsetY)));
	board.setOutlineColor(sf::Color::Blue);
	
	board.setFillColor(c);
	win.draw(board);
}

void Board::DrawSprite(const location & loc, sf::Sprite* _sprite)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	const int offsetX = x + borderpadding;
	const int offsetY = y + borderpadding;
	//_sprite = tex;
	
	_sprite->setScale(0.20f,0.20f);
	_sprite->setPosition(sf::Vector2f(loc.x*cellsize +x-borderpadding, loc.y*cellsize + y-borderpadding));
	//obstac.setTexture(obst);
	win.draw(*_sprite);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

sf::RectangleShape Board::getBoard()
{
	return board;
}

bool Board::isInsideBoard(const location & loc)
{
	return loc.x>=0 && loc.x<width && 
		loc.y>=0 && loc.y<height;
}

bool Board::CheckForObstacle(const location & loc) const
{
	return checkObs[loc.y * width + loc.x];
}

void Board::SpawnObstacle(std::mt19937 & rng, const Snake & snake, const Fruit & fruit)
{
	std::uniform_int_distribution<int> xDist(0, GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, GetGridHeight() - 1);

	location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.isInTile(newLoc) || CheckForObstacle(newLoc) || fruit.GetLocation() == newLoc);

	checkObs[newLoc.y * width + newLoc.x] = true;
}

void Board::DrawBorder()
{
	//top
	border[0].setSize(sf::Vector2f(width*cellsize+ borderpadding*2, borderwidth));
	border[0].setPosition(sf::Vector2f(x-borderpadding,y-borderwidth - borderpadding));
	//border[0].setPosition(sf::Vector2f(x, y - borderwidth ));
	border[0].setFillColor(bordercolor);

	//left
	border[1].setSize(sf::Vector2f(borderwidth,height*cellsize+borderwidth*2+borderpadding*2));
	border[1].setPosition(sf::Vector2f(x - borderwidth , y - borderwidth-borderpadding));
	//border[1].setPosition(sf::Vector2f(x - borderwidth , y - borderwidth));
	border[1].setFillColor(bordercolor);
	//right
	border[2].setSize(sf::Vector2f(borderwidth, height*cellsize + borderwidth * 2 + borderpadding * 2));
	border[2].setPosition(sf::Vector2f(x +width * cellsize +borderpadding, y - borderwidth - borderpadding));
	//border[2].setPosition(sf::Vector2f(x + width * cellsize , y - borderwidth));
	border[2].setFillColor(bordercolor);
	//bottom
	border[3].setSize(sf::Vector2f(width*cellsize+ borderpadding*2, borderwidth));
	border[3].setPosition(sf::Vector2f(x- borderpadding , y +height * cellsize+borderpadding ));
	//border[3].setPosition(sf::Vector2f(x, y + height * cellsize ));
	border[3].setFillColor(bordercolor);

	win.draw(border[0]);
	win.draw(border[1]);
	win.draw(border[2]);
	win.draw(border[3]);
}

void Board::DrawObstacles(sf::Sprite& obs)
{
	
	//std::
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (CheckForObstacle({ x,y }))
			{
				//DrawCell({ x,y }, poisonColor);
				//DrawSprite({x,y}, obstac);
				//animation(delt_time);
				DrawSprite({ x,y }, &obs);
			}
		}
	}
}

void Board::DrawFruit(const location& loc, sf::Sprite & obs)
{
	DrawSprite(loc, &obs);
}


