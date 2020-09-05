#include "Engine.h"
#include<iostream>
using namespace sf;

RenderWindow Engine::window;
Game Engine::g(window);

void Engine::initialize()
{
	window.create(VideoMode(screenwidth, screenheight),"Snake");
	window.setFramerateLimit(60);
	std::cout << window.getSize().x<<" "<< window.getSize().y <<std::endl;
	//Game theG(&window);
}

bool Engine::isRunning()
{
	return window.isOpen();
}

void Engine::handleEvents()
{
	
	Event event;
	while (window.pollEvent(event))
	{
		
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			//break;
		}		
	}
	window.clear();
	g.gameInit();
}

void Engine::render(){
	
	//render(&window);
	//g.render();
	//window.draw(g.brd.getBoard());
	window.display();
}
