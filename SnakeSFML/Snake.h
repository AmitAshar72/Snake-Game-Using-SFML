#pragma once
#include "Board.h"
#include <SFML\Graphics.hpp>
class Snake
{
private:
	class Segment
	{
	public:		
		void InitHead(const location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const location& delta_loc);
		void Draw(Board& brd) const;
		const location& GetLocation() const; // just peeking at the value, rather than creating a copy
	private:
		location loc;		
		sf::Color c;
		//static sf::Texture segTex;
		
	};
public:
	Snake(const location& loc);
	//static sf::Texture snkTex;
	void MoveBy(const location& delta_loc);
	location GetNextHeadLocation(const location& delta_loc) const; //position of the head of the snake after location change (delta_loc)
	void Grow();
	void Draw(Board& brd) const;
	bool isInTile(const location& targetloc) const;
	bool isInTileExceptTail(const location& targetloc) const;
private:		
	static constexpr int nSegmentsMax = 100;	
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};

