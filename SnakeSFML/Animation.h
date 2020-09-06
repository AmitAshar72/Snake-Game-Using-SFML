#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
public:
	Animation(sf::Sprite* _sprite, sf::Vector2u imageCount, float switchTime); 
	//receives a pointer to the sprite, total image count in the sprite sheet and the time b/w swtiching frames
	void update(int row, float del_time);
	//the update function switches the frames in between the sprite sheets at that row, with the help
	//of the clock time that is being sent from the game class
public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::Sprite* _sprite;

	float totalTime=0.0f; 
	float switchTime;
};

