#pragma once
#include <SFML/Graphics.hpp>
#include "misc.cpp"



class Ball
{
private:
	sf::CircleShape m_Ball;
	sf::Vector2f	m_ScreenSize;
	sf::Vector2f	m_Direction;
	sf::Vector2f	m_StartingPosition;
	float			m_Speed;
	float			m_BallRadius;
public:
	Ball(sf::Vector2f& screenSize);
	~Ball();
	const sf::CircleShape GetBall() const;
	void UpdatePosition(const PlayersPosition& paddlePositions, const sf::Vector2f& paddleSize);
private:
	void CheckCollisionAndMove(const sf::Vector2f& paddleSize, const PlayersPosition& paddlePositions);
	void ChangeDirectionAndMove(float& directionToChange);
	void RandomizeDirection();
};

