#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Sprite* _sprite, sf::Vector2u imageCount):
	
	imageCount(imageCount)
{	
	currentImage.x=0;
	uvRect.width = 128.0f;
	uvRect.height = 128.0f;
	this->_sprite = _sprite;
}

void Animation::update(int row, float del_time)
{
	std::cout<<"update called"<<std::endl;
	currentImage.y = row;
	totalTime += del_time;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		std::cout << "IMAGE NUMEBER:  " + currentImage.x<< std::endl;
		if (currentImage.x >= imageCount.x)
		{
			std::cout << "Image set to 0 frame" << std::endl;
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;
	_sprite->setTextureRect(uvRect);
	std::cout << "Sprite Set" << std::endl;
}
