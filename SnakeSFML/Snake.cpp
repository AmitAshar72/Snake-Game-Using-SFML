#include "Snake.h"
#include <assert.h>
Snake::Snake(const location & loc)
{
	segments[0].InitHead(loc);	
	//snkTex.loadFromFile("obstacle.png");
}

void Snake::MoveBy(const location & delta_loc)
{
	for (int i = nSegments - 1; i > 0;i--) 
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

location Snake::GetNextHeadLocation(const location & delta_loc) const
{
	location l(segments[0].GetLocation());
	//initializing l as a copy of location of the head (copy ctor)
	l.Add(delta_loc);
	return l; //return next location after delta is applied
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0;i < nSegments;i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::isInTileExceptTail(const location & targetloc) const
{
	for (int i = 0;i < nSegments-1;i++) // nSegments -1 because we dont want to check the tail
	{
		if (segments[i].GetLocation() == targetloc)  //defined operator in location class
		{
			return true;
		}
	}
	return false;
}
int Snake::getLength() const
{
	return nSegments;
}
bool Snake::isInTile(const location & targetloc) const
{
	for (int i = 0;i < nSegments;i++) // nSegments -1 because we dont want to check the tail
	{
		if (segments[i].GetLocation() == targetloc)  //defined operator in location class
		{
			return true;
		}
	}
	return false;
}


void Snake::Segment::InitHead(const location & in_loc)
{
	loc = in_loc; //assignment operator
	c = sf::Color::Yellow;
	
}

void Snake::Segment::InitBody()
{
	c = sf::Color::Green;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1); //either x or y can be 1 or -1
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const location & Snake::Segment::GetLocation() const
{
	return loc;
}
