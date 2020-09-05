#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
public:
	Animation(sf::Sprite* _sprite, sf::Vector2u imageCount);
	void update(int row, float del_time);
public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::Sprite* _sprite;

	float totalTime=0.0f;
	float switchTime = 0.3f;
};

