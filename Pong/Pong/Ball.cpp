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

void Ball::CheckCollisionAndMove(const sf::Vector2f& paddleSize, const PlayersPosition& paddlePositions)
{
	auto position = m_Ball.getPosition();
	const auto dividedBallBouncerY = position.y + m_Direction.y + m_BallRadius * 2;
	const auto multipliedBallBouncerY = position.y + m_Direction.y + m_BallRadius / 2;
	const auto dividedBallBouncerX = position.x + m_Direction.x + m_BallRadius / 2;
	const auto multipliedBallBouncerX = position.x + m_Direction.x + m_BallRadius * 2;

	m_Direction *= m_Speed;

	if(m_ScreenSize.y < dividedBallBouncerY) //bounce off of lower bound
	{
		ChangeDirectionAndMove(m_Direction.y);
	}
	else if(0 >= multipliedBallBouncerY) //bounce off of upper bound
	{
		ChangeDirectionAndMove(m_Direction.y);
	}
	else if(0 >= position.x + m_Direction.x)
	{
		//TODO Increase player 2 score, reset ball direction
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
	}
	else if (m_ScreenSize.x <= multipliedBallBouncerX)
	{
		//TODO Increase player 1 score, reset ball direction
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
	}
	else if(paddleSize.x >= dividedBallBouncerX) //check if within X range of paddle 
	{
		if(((paddlePositions.PlayerOne.y) < dividedBallBouncerY) && ((paddlePositions.PlayerOne.y + paddleSize.y) > dividedBallBouncerY)) //check if within Y range of paddle
		{			
			ChangeDirectionAndMove(m_Direction.x);
		}
		else
			m_Ball.move(m_Direction);
	}
	else if((m_ScreenSize.x - paddleSize.x) <= multipliedBallBouncerX)
	{
		if((paddlePositions.PlayerTwo.y) < multipliedBallBouncerY && ((paddlePositions.PlayerTwo.y + paddleSize.y) > multipliedBallBouncerY))
		{
			ChangeDirectionAndMove(m_Direction.x);
		}
		else
			m_Ball.move(m_Direction);
	}
	else
		m_Ball.move(m_Direction);
}

void Ball::ChangeDirectionAndMove(float& directionToChange)
{
	directionToChange *= -1;
	m_Ball.move(m_Direction);
}

void Ball::UpdatePosition(const PlayersPosition& paddlePositions, const sf::Vector2f& paddleSize)
{
	CheckCollisionAndMove(paddleSize, paddlePositions);
}
