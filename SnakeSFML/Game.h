#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include "Menu.h"
#include "Animation.h"

#include <random>
class Game
{
public:	
	Game(sf::RenderWindow& win );
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete; //rule of 3
	void gameInit();
	//void render(sf::RenderWindow* wind);
	
private:	
	void update();
	void compose();		
	void Endgame();
	void scoreDisp();
	
public:
	
private:
	sf::RenderWindow& win;	
	sf::Text text,text_score;
	sf::Texture splashTex;
	sf::Sprite splash;
	sf::SoundBuffer collide_buffer, gameover_buffer;
	sf::Sound fruit, gameOver;
	sf::Music bgmusic;

	sf::Clock clock;	
	Board brd;
	Snake snk;
	std::mt19937 rng;
	Fruit frt;
	Menu m;
	sf::Vector2u tex = sf::Vector2u(3, 1);
	sf::Sprite obstac;
	sf::Sprite powerUp;
	sf::Texture obst, powerUp_tex;
	Animation anim, anim2;
	location delta_loc = { 1,0 };
	static constexpr int snakeMovePeriodMin = 5; //5 frames per movement
	int snakeMovePeriod = 20; //3 movements per sec

	int snakeMoveCounter = 0;
	int snakeSpeedUpPeriod = 180;
	int snakeSpeedupCounter = 0;
	int score = 0;
	int menuIndex = 0;
	float deltaTime = 0.0f;
	bool isGameOver = false;	
	bool hasGameStarted = false;
	bool isSplashDone = false;
};

