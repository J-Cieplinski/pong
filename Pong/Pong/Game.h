#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"
#include "Ball.h"


class Game
{
private:
	sf::RenderWindow		    m_Window;
	sf::Event				    m_Event;
	sf::Vector2f			    m_PaddleSize;
	sf::Font                    m_Font;
	std::array<sf::Text, 2>	    m_Score;
	Paddle					    m_PlayerOnePaddle;
	Paddle					    m_PlayerTwoPaddle;
	Ball					    m_Ball;
	PlayersInformation          m_PlayersInfo;

public:
	Game(sf::Vector2f screenSize, std::string name);
	~Game();
	void Run();
private:
    void UpdateScores();
    void UpdatePlayersInfo();
};

