#include "Paddle.h"
#include <ctime>
#include <cstdlib>

bool Paddle::Move(float direction)
{
	auto position = m_Shape.getPosition();

	if ((position.y + m_Shape.getSize().y + direction) > m_ScreenSize.y)
	{
		position.y = m_ScreenSize.y - m_Shape.getSize().y;
		m_Shape.setPosition(position);
		return false;
	}
	else if((position.y + direction) < 0)
	{
		position.y = 0;
		m_Shape.setPosition(position);
		return false;
	}
	else
	{
		position.y += direction;
		m_Shape.setPosition(position);
		return true;
	}
}

const sf::RectangleShape& Paddle::GetPaddle() const
{
	return m_Shape;
}


void Paddle::UpdatePosition()
{
	if (sf::Keyboard::isKeyPressed(m_Keys.Down))
	{
		Move(1*m_Speed);
		
	}
	else if(sf::Keyboard::isKeyPressed(m_Keys.Up))
	{
		Move(-1*m_Speed);
	}
	

}

Paddle::Paddle(sf::Vector2f size, sf::Vector2f& screenSize, PlayerKeyboard* keys, PlayerSide side) : m_Shape(size), m_ScreenSize(screenSize), m_Keys(*keys)
{
	m_Speed = 2;
	auto* color = new sf::Color(1 + std::rand() / ((RAND_MAX + 1u) / 255),
	                                 1 + std::rand() / ((RAND_MAX + 1u) / 255),
	                                 1 + std::rand() / ((RAND_MAX + 1u) / 255)); //Randomize individual paddles color
	m_Shape.setFillColor(*color);
	delete color;
	if (PlayerSide::LEFT == side)
		m_Shape.setPosition(0, ((screenSize.y) / 2) - (size.y / 2));
	else if (PlayerSide::RIGHT == side)
		m_Shape.setPosition(screenSize.x-size.x, ((screenSize.y) / 2) - (size.y / 2));
}


Paddle::~Paddle()
{
}
