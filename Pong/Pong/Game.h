#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"


class Game
{
private:
	sf::RenderWindow	m_Window;
	sf::Event			m_Event;
	Paddle				m_PlayerOnePaddle;
	Paddle				m_PlayerTwoPaddle;

public:
	Game(sf::Vector2f screenSize, std::string name);
	~Game();

	void Run();
};

