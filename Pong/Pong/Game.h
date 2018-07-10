#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"

class Game
{
private:
	sf::RenderWindow	m_Window;
	sf::Event			m_Event;
	Paddle				m_Paddle;
public:
	Game(unsigned int, unsigned int, std::string);
	~Game();

	void Run();
};

