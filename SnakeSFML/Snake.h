#pragma once
#include "Board.h"
#include <SFML\Graphics.hpp>
class Snake
{
private:
	class Segment //segments together join to form a snake
	{
	public:		
		void InitHead(const location& loc); //initializes head of the snake
		void InitBody(); //initializes head of the body
		void Follow(const Segment& next); //follows the head of the body
		void MoveBy(const location& delta_loc); //adds Location value
		void Draw(Board& brd) const; //calls draw function in the snake class with location and color as parameters
		const location& GetLocation() const; // just peeking at the value, rather than creating a copy
	private:
		location loc;		
		sf::Color c;		
	};
public:
	Snake(const location& loc);
	void MoveBy(const location& delta_loc);
	location GetNextHeadLocation(const location& delta_loc) const; //position of the head of the snake after location change (delta_loc)
	void Grow(); //adds a segment
	void Draw(Board& brd) const;
	bool isInTile(const location& targetloc) const; //checks the occupied grid of the snake 
	bool isInTileExceptTail(const location& targetloc) const; //checks the occupied grid of the snake except the tail
	int getLength() const;
private:		
	static constexpr int nSegmentsMax = 100;	//max segments
	Segment segments[nSegmentsMax]; //array of segments
	int nSegments = 1; //segment counter
};

