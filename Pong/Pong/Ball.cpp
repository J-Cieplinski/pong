#include "Ball.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

Ball::Ball(sf::Vector2f& screenSize) : m_ScreenSize(screenSize), m_StartingPosition(m_ScreenSize.x / 2, m_ScreenSize.y / 2)
{
	m_Acceleration = 1.2f;
	m_BallRadius = 10.f;
	m_Ball.setFillColor(sf::Color(255, 255, 255));
	m_Ball.setRadius(m_BallRadius);
	m_Ball.setPosition(m_StartingPosition);

	m_lossSound.loadFromFile("assets/sounds/loss.ogg");
	m_paddleSound.loadFromFile("assets/sounds/withPaddle.ogg");
	m_wallSound.loadFromFile("assets/sounds/withWall.ogg");


    RandomizeDirection();
}


Ball::~Ball()
{
}

const sf::CircleShape & Ball::GetBall() const
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

	if(m_ScreenSize.y < dividedBallBouncerY) //bounce off of lower bound
	{
		ChangeDirectionAndMove(m_Direction.y);
		m_Sound.setBuffer(m_wallSound);
		m_Sound.play();
	}
	else if(0 >= multipliedBallBouncerY) //bounce off of upper bound
	{
		ChangeDirectionAndMove(m_Direction.y);
        m_Sound.setBuffer(m_wallSound);
        m_Sound.play();
	}
	else if(0 >= position.x + m_Direction.x)
	{
		//TODO Increase player 2 score
        m_Sound.setBuffer(m_lossSound);
        m_Sound.play();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
		RandomizeDirection();
	}
	else if (m_ScreenSize.x <= multipliedBallBouncerX)
	{
		//TODO Increase player 1 score
        m_Sound.setBuffer(m_lossSound);
        m_Sound.play();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1s, let that defeat sink in
		m_Ball.setPosition(m_StartingPosition);
        RandomizeDirection();
	}
	else if(paddleSize.x >= dividedBallBouncerX) //check if within X range of paddle 
	{
		if(((paddlePositions.PlayerOne.y) < dividedBallBouncerY) && ((paddlePositions.PlayerOne.y + paddleSize.y) > dividedBallBouncerY)) //check if within Y range of paddle
		{
            m_Direction*=m_Acceleration;
            m_Sound.setBuffer(m_paddleSound);
		    m_Sound.play();
			ChangeDirectionAndMove(m_Direction.x);
		}
		else
			m_Ball.move(m_Direction);
	}
	else if((m_ScreenSize.x - paddleSize.x) <= multipliedBallBouncerX)
	{
		if((paddlePositions.PlayerTwo.y) < multipliedBallBouncerY && ((paddlePositions.PlayerTwo.y + paddleSize.y) > multipliedBallBouncerY))
		{
            m_Direction*=m_Acceleration;
            m_Sound.setBuffer(m_paddleSound);
            m_Sound.play();
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
    if(directionToChange>=4)                //Don't let the ball move too fast
        directionToChange/=m_Acceleration;

	directionToChange *= -1;
	m_Ball.move(m_Direction);
}

void Ball::UpdatePosition(const PlayersPosition& paddlePositions, const sf::Vector2f& paddleSize)
{
	CheckCollisionAndMove(paddleSize, paddlePositions);
}

void Ball::RandomizeDirection() {

    std::mt19937 generator(std::time(nullptr));
    std::uniform_real_distribution<float> distribution(-1.0,1.0);
    m_Direction.x = distribution(generator);
    while(0.4 > std::fabs(m_Direction.x) )
		m_Direction.x = distribution(generator);
    m_Direction.y = distribution(generator);
	while (0.4 > std::fabs(m_Direction.y))
		m_Direction.y = distribution(generator);
}
