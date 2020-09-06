#pragma once
#include <SFML\Graphics.hpp>
#include "Game.h"
class Engine
{
private:
	static sf::RenderWindow window;
public:		
	static void initialize(); //initalizes window
	static bool isRunning(); //checks if window is running
	static void handleEvents(); //handles events and calls gameinit here
	static void render(); // displays onto the screen
	static Game g;
private:
	static constexpr float screenwidth = 800.0f;
	static constexpr float screenheight = 600.0f;
};

