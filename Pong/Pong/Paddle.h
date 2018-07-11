#pragma once
#include <SFML/Graphics.hpp>
#include "misc.cpp"

class Paddle
{
private:
	sf::RectangleShape	m_Shape;
	sf::Vector2f		m_ScreenSize;
	PlayerKeyboard		m_Keys;
	bool Move(float);

public:
	const sf::RectangleShape& getPaddle();
	void UpdatePosition();
	Paddle(sf::Vector2f, sf::Vector2f, PlayerKeyboard*);
	~Paddle();
};

