#include "Ball.h"



Ball::Ball(sf::Vector2f& screenSize) : m_ScreenSize(screenSize)
{
	m_Speed = 1;
	m_BallRadius = 10.f;
	m_Ball.setFillColor(sf::Color(255, 255, 255));
	m_Ball.setRadius(m_BallRadius);
	m_Ball.setPosition(sf::Vector2f(m_ScreenSize.x/2, m_ScreenSize.y/2));


	//TODO Figure out how to generate random number between -1 and 1
	m_Direction.x = rand() % (3) - 1;
	m_Direction.y = rand() % (3) - 1;
}


Ball::~Ball()
{
}

const sf::CircleShape Ball::GetBall() const
{
	return m_Ball;
}

void Ball::Move(float speed)
{
	auto position = m_Ball.getPosition();

	m_Direction *= m_Speed;

	if(m_ScreenSize.y < (position.y + m_Direction.y + m_BallRadius*2))
	{
		position.y = m_ScreenSize.y - m_BallRadius*2;
		m_Direction.y *= -1;
		m_Ball.setPosition(position + m_Direction);
	}
	else if(0 >= position.y + m_Direction.y + m_BallRadius/2)
	{
		position.y = 0;
		m_Direction.y *= -1;
		m_Ball.setPosition(position + m_Direction);
	}
	else if(0 >= position.x + m_Direction.x)
	{
		//TODO Increase player 2 score, reset ball position and direction
	}
	else if (m_ScreenSize.x <= position.x + m_Direction.x)
	{
		//TODO Increase player 1 score, reset ball position and direction
	}
	//TODO Add Collision with paddle
	else		
		m_Ball.setPosition(position + m_Direction);
}

void Ball::UpdatePosition()
{
	Move(m_Speed);
}