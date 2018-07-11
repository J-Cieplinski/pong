#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"
#include "Ball.h"


class Game
{
private:
	sf::RenderWindow	m_Window;
	sf::Event			m_Event;
	Paddle				m_PlayerOnePaddle;
	Paddle				m_PlayerTwoPaddle;
	Ball				m_Ball;

public:
	Game(sf::Vector2f screenSize, std::string name);
	~Game();

	void Run();
};

