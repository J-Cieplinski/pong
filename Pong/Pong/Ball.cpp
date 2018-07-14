#include "Ball.h"
#include <chrono>
#include <thread>



Ball::Ball(sf::Vector2f& screenSize) : m_ScreenSize(screenSize), m_StartingPosition(m_ScreenSize.x / 2, m_ScreenSize.y / 2)
{
	m_Speed = 1;
	m_BallRadius = 10.f;
	m_Ball.setFillColor(sf::Color(255, 255, 255));
	m_Ball.setRadius(m_BallRadius);
	m_Ball.setPosition(m_StartingPosition);


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

void Ball::CheckCollision(const sf::Vector2f& paddleSize, const PlayersPosition& paddlePositions)
{
	auto position = m_Ball.getPosition();

	m_Direction *= m_Speed;

	if(m_ScreenSize.y < (position.y + m_Direction.y + m_BallRadius*2)) //bounce off of lower bound
	{
		m_Direction.y *= -1;
		m_Ball.move(m_Direction);
	}
	else if(0 >= position.y + m_Direction.y + m_BallRadius/2) //bounce off of upper bound
	{
		m_Direction.y *= -1;
		m_Ball.move(m_Direction);
	}
	else if(0 >= position.x + m_Direction.x)
	{
		//TODO Increase player 2 score, reset ball direction
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
	}
	else if (m_ScreenSize.x <= position.x + m_Direction.x)
	{
		//TODO Increase player 1 score, reset ball direction
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
	}
	//TODO Add Collision with paddle
	else if(paddleSize.x >= (position.x + m_Direction.x + m_BallRadius/2)) //check if within X range of paddle 
	{
		if (((paddlePositions.PlayerOne.y + paddleSize.y)) > (position.y + m_Direction.y + m_BallRadius / 2)) //check if within Y range of paddle
		{			
			m_Direction.x *= -1;
			m_Ball.move(m_Direction);
		}
	}
	else if((m_ScreenSize.x - paddleSize.x) <= (position.x + m_Direction.x + m_BallRadius * 2))
	{
		if((paddlePositions.PlayerTwo.y + paddleSize.y) < (position.y + m_Direction.y + m_BallRadius *2))
		{
			m_Direction.x *= -1;
			m_Ball.move(m_Direction);
		}
	}
	else		
		m_Ball.setPosition(position + m_Direction);
}

void Ball::UpdatePosition(const PlayersPosition& paddlePositions, const sf::Vector2f& paddleSize)
{
	CheckCollision(paddleSize, paddlePositions);
}
