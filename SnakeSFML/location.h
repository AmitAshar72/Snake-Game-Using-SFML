#pragma once
class location 
{
public:
	void Add(const location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator== (const location& rhs)const //equivalence def for isInTile check
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};