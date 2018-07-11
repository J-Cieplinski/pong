#pragma once
#include <SFML/Graphics.hpp>
#include "misc.cpp"

class Paddle
{
private:
	sf::RectangleShape	m_Shape;
	sf::Vector2f		m_ScreenSize;
	PlayerKeyboard		m_Keys;
	float				m_Speed;
	
	bool Move(float);
public:
	const sf::RectangleShape& GetPaddle() const;
	void UpdatePosition();
	Paddle(sf::Vector2f size, sf::Vector2f& screenSize, PlayerKeyboard* keys, PlayerSide side);
	~Paddle();
};

