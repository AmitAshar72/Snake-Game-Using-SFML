#include "Game.h"
#include <iostream>
using namespace sf;
Game::Game(sf::RenderWindow& win)
	:
	win(win),
	brd(win),
	rng(std::random_device()()),
	snk({3,4}),		
	frt(rng, brd, snk),
	m(800.0f,600.0f,win),
	anim(&obstac,tex,0.5f),
	anim2(&powerUp,tex,0.65f)
{  
	loadTextures();
	loadSound();
}

void Game::gameInit()
{	
		update();
		compose();	
				
}

void Game::update()
{
	if (!isSplashDone) //splash screen
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			isSplashDone = true;
			bgmusic.play(); //background music starts
		}
	}
	else 
	{
		if (!isGameOver)
		{
			if (!hasGameStarted) //menu
			{
				deltaTime = clock.restart().asSeconds(); //delta time for update function in animation class 
				
				//input handling for menu
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					m.moveUp();
					menuIndex = m.getSelectedIndex();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					m.moveDown();
					menuIndex = m.getSelectedIndex();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					if (menuIndex == 0)
					{
						hasGameStarted = true;		//starts game				
					}
					else
					{
						win.close(); //closes window
					}

				}
			}
			else //game
			{
				//handles snake movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					const location new_delta_loc = { 0,-1 };
					if (delta_loc != -new_delta_loc || snk.getLength() <= 2) //user defined operators in location class
					{
						delta_loc = new_delta_loc;
					}
					std::cout << "Moving UP" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					const location new_delta_loc = { 0,1 };
					if (delta_loc != -new_delta_loc || snk.getLength() <= 2)
					{
						delta_loc = new_delta_loc;
					}
					std::cout << "Moving Down" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					const location new_delta_loc = { -1,0 };
					if (delta_loc != -new_delta_loc || snk.getLength() <= 2)
					{
						delta_loc = new_delta_loc;
					}
					std::cout << "Moving Left" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					const location new_delta_loc = { 1,0 };
					if (delta_loc != -new_delta_loc || snk.getLength() <= 2)
					{
						delta_loc = new_delta_loc;
					}
					std::cout << "Moving Right" << std::endl;
				}
				++snakeMoveCounter; //movement counter increases every frame
				if (snakeMoveCounter >= snakeMovePeriod) //when the movement counter is more than move period, snake moves
					//initially set to move snake one grid per second
				{
					snakeMoveCounter = 0;
					const location next = snk.GetNextHeadLocation(delta_loc); //gets snake's head's next location
					if (!brd.isInsideBoard(next) ||
						snk.isInTileExceptTail(next) ||
						brd.CheckForObstacle(next)) //end game check
						//if the snake touches the border or the obstacle or itself, then game is over
					{
						isGameOver = true;
						bgmusic.stop(); //background music stops
						gameOver.play(); //game over sound effect
					}
					else
					{
						if (next == frt.GetLocation())
						{
							snk.Grow(); //calls grow function when snake eats fruit
							frt.Respawn(rng, brd, snk); // respawns the fruit to another location
							fruit.play(); //sound effect when snake eats fruit
							brd.SpawnObstacle(rng, snk, frt); //eating fruit is the queue for obstacle to be spawned
							score++; //player score increases by 1
						}
						snk.MoveBy(delta_loc); //snake moves with delta_loc value, initially set to {1,0}. Means snake moves right at the beginning

					}
				}
				++snakeSpeedupCounter; //speed counter increases every frame
				if (snakeSpeedupCounter >= snakeSpeedUpPeriod) //when the speed counter is more than speed period, snake move period is decreased
				{
					snakeSpeedupCounter = 0;
					std::cout << "Speed++" << std::endl;
					snakeMovePeriod = std::max(snakeMovePeriod - 1, snakeMovePeriodMin); //returns the max of the least values
				
				}
			}
					   
		}
	}
	
}

void Game::compose()
{
	if (!isGameOver) 
	{
		if (!isSplashDone)
		{
			win.draw(splash); //draws splash to screen
			//Text Space to enter
		}
		else
		{
			if (!hasGameStarted)
			{
				m.draw(); //draws menu to screen
				//Text Arrow keys/enter to navigate
			}
			else
			{
				snk.Draw(brd); //draw call for snake
				frt.Draw(brd, powerUp); ////draw call for fruit
				brd.DrawBorder(); ////draw call for border
				brd.DrawObstacles(obstac); //draw call for obstacle
				
				anim.update(0, deltaTime); //handles obstacle sprite
				anim2.update(0,deltaTime); //handles pickup sprite
				scoreDisp(); //displays score
			}
		}
	}		
	else //gameover
	{
		Endgame();	//gameover prompt
		scoreDisp();
	}
	
}

void Game::Endgame()
{
	sf::Font font;
	font.loadFromFile("font.ttf");	
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);	
	text.setFillColor(sf::Color::White);
	text.setPosition(325.0f, 250.0f);
	text.setString("Game Over");
	win.draw(text);
}

void Game::scoreDisp()
{
	sf::Font font;
	font.loadFromFile("font.ttf");	
	text_score.setFont(font);
	text_score.setCharacterSize(25);
	text_score.setStyle(sf::Text::Bold);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(675.0f, 20.0f);
	text_score.setString("Score: "+std::to_string(score));
	win.draw(text_score);
}

void Game::loadTextures()
{
	//load texture
	powerUp_tex.loadFromFile("pickup.png");
	powerUp.setTexture(powerUp_tex);
	powerUp.setTextureRect(sf::IntRect(128, 0, 128, 128));

	obst.loadFromFile("obstacle.png");
	obstac.setTexture(obst);
	obstac.setTextureRect(sf::IntRect(128, 0, 128, 128));

	if (!splashTex.loadFromFile("splash.png"))
	{
		std::cout << "Error Loading Splash File"<<std::endl;
	}
	splash.setTexture(splashTex);
}

void Game::loadSound()
{
	//load sound
	bgmusic.openFromFile("bgmusic.ogg");
	bgmusic.setVolume(50);
	bgmusic.setLoop(true);

	if (!collide_buffer.loadFromFile("fruit.wav"))
	{
		std::cout << "Error Loading fruit.wav File" << std::endl;
	}
	fruit.setBuffer(collide_buffer);
	if (!gameover_buffer.loadFromFile("gameover.wav"))
	{
		std::cout << "Error Loading gameover.wav File" << std::endl;
	}
	gameOver.setBuffer(gameover_buffer);
}






