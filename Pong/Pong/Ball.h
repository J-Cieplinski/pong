#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape m_Ball;
	sf::Vector2f	m_ScreenSize;
	float			m_Speed;
	float			m_BallRadius;
	sf::Vector2f	m_Direction;
public:
	Ball(sf::Vector2f& screenSize);
	~Ball();
	const sf::CircleShape GetBall() const;
	void Move(float speed);
	void UpdatePosition();
};

