#include "Engine.h"
//#include "Game.h"
int main()
{
	
	Engine::initialize();
	while (Engine::isRunning())
	{	
		Engine::handleEvents();
		Engine::render();
	}
	
	return 0;
}