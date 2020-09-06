#pragma once
class location 
{
public:
	void Add(const location& val) //adds location values
	{
		x += val.x;
		y += val.y;
	}

	bool operator!=(const location& rhs) const //not equal to operator defined for location
	{
		return !(*this == rhs);
	}
	location operator-() const //return negated values of x and y
	{
		return { -x,-y };
	}

	bool operator== (const location& rhs)const //equal to operator defined for location
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};