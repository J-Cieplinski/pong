#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
private:
	sf::RectangleShape	m_Shape;
	sf::RenderWindow	m_Window;
	sf::Vector2f		m_ScreenSize;
	bool reverse = false;

public:
	//void drawPaddle(sf::RenderWindow const&);
	const sf::RectangleShape& getPaddle();
	void UpdatePosition();
	Paddle(sf::Vector2f, sf::Vector2f);
	~Paddle();
};

