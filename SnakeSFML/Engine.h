#pragma once
#include <SFML\Graphics.hpp>
#include "Game.h"
class Engine
{
private:
	static sf::RenderWindow window;
public:		
	static void initialize();
	static bool isRunning();
	static void handleEvents();
	static void render();
	static Game g;
private:
	static constexpr float screenwidth = 800.0f;
	static constexpr float screenheight = 600.0f;
};

