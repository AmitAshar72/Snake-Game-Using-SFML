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
	anim(&obstac,tex),
	anim2(&powerUp,tex)
{
	powerUp_tex.loadFromFile("down.png");
	powerUp.setTexture(powerUp_tex);
	powerUp.setTextureRect(sf::IntRect(128, 0, 128, 128));

	obst.loadFromFile("obstacle.png");
	obstac.setTexture(obst);
	obstac.setTextureRect(sf::IntRect(128, 0, 128, 128));

	

	if (!splashTex.loadFromFile("splash.png"))
	{
		
	}
	splash.setTexture(splashTex);

	bgmusic.openFromFile("bgmusic.ogg");
	bgmusic.setVolume(50);
	bgmusic.setLoop(true);

	if (!collide_buffer.loadFromFile("fruit.wav"))
	{

	}
	fruit.setBuffer(collide_buffer);
	if (!gameover_buffer.loadFromFile("gameover.wav"))
	{

	}
	gameOver.setBuffer(gameover_buffer);

	/*if (!obstacle.loadFromFile("obstacle.png")) {}
	brd.getBoard().setTexture(&obstacle);
	Animation anim(&obstacle, sf::Vector2u(3, 1), 0.3f);*/
}

void Game::gameInit()
{	
		update();
		compose();	
				
}

void Game::update()
{
	if (!isSplashDone)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			isSplashDone = true;
	}
	else 
	{
		if (!isGameOver)
		{
			if (!hasGameStarted)
			{
				deltaTime = clock.restart().asSeconds();
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
						hasGameStarted = true;
						bgmusic.play();
					}
					else
					{
						win.close();
					}

				}
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					delta_loc = { 0,-1 };
					std::cout << "Moving UP" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					delta_loc = { 0,1 };
					std::cout << "Moving Down" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					delta_loc = { -1,0 };
					std::cout << "Moving Left" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					delta_loc = { 1,0 };
					std::cout << "Moving Right" << std::endl;
				}
				++snakeMoveCounter;
				if (snakeMoveCounter >= snakeMovePeriod)
				{
					snakeMoveCounter = 0;
					const location next = snk.GetNextHeadLocation(delta_loc);
					if (!brd.isInsideBoard(next) ||
						snk.isInTileExceptTail(next) ||
						brd.CheckForObstacle(next))
					{
						isGameOver = true;
						bgmusic.stop();
						gameOver.play();
					}
					else
					{

						if (next == frt.GetLocation())
						{
							snk.Grow();
							frt.Respawn(rng, brd, snk);
							fruit.play();
							brd.SpawnObstacle(rng, snk, frt);
							score++;
						}
						snk.MoveBy(delta_loc);
					}
				}
				++snakeSpeedupCounter;
				if (snakeSpeedupCounter >= snakeSpeedUpPeriod)
				{
					snakeSpeedupCounter = 0;
					std::cout << "Speed++" << std::endl;
					snakeMovePeriod = std::max(snakeMovePeriod - 1, snakeMovePeriodMin);
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
			win.draw(splash);
		}
		else
		{
			if (!hasGameStarted)
			{
				m.draw();
			}
			else
			{
				snk.Draw(brd);
				frt.Draw(brd, powerUp);
				brd.DrawBorder();
				brd.DrawObstacles(obstac);
				//brd.DrawFruit(powerUp);
				anim.update(0, deltaTime);
				anim2.update(0,deltaTime);
				scoreDisp();
			}
		}
	}		
	else
	{
		Endgame();	
		scoreDisp();
	}
	
}


void Game::Endgame()
{
	sf::Font font;
	font.loadFromFile("font.ttf");
	// Create a text
	//sf::Text text("Game Over", font);
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
	// Create a text
	//sf::Text text("Game Over", font);
	text_score.setFont(font);
	text_score.setCharacterSize(25);
	text_score.setStyle(sf::Text::Bold);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(675.0f, 20.0f);
	text_score.setString("Score: "+std::to_string(score));
	win.draw(text_score);
}


//void Game::render(sf::RenderWindow* wind)
//{/*
//	std::uniform_int_distribution<int> colorDist(0, 255);
//	for (int y = 0;y < brd.GetGridHeight();y++)
//	{
//		for (int x = 0;x < brd.GetGridWidth();x++)
//		{
//			location loc = { x,y };
//			sf::Color c(colorDist(rng), colorDist(rng), colorDist(rng));
//			brd.DrawCell(loc, c);
//			wind->draw(brd.getBoard());
//		}
//	}*/
//	snk.Draw(brd);
//	wind->draw(brd.getBoard());
//	
//}



