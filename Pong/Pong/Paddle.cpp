#include "Paddle.h"

bool Paddle::Move(float direction)
{
	auto position = m_Shape.getPosition();

	if ((position.y + m_Shape.getSize().y) >= m_ScreenSize.y)
		return false;
	else
	{
		position.y += direction;
		m_Shape.setPosition(position);
		return true;
	}
}

const sf::RectangleShape& Paddle::getPaddle()
{
	return m_Shape;
}


void Paddle::UpdatePosition()
{
	if (sf::Keyboard::isKeyPressed(m_Keys.Down))
	{
		Move(1);
		
	}
	else if(sf::Keyboard::isKeyPressed(m_Keys.Up))
	{
		Move(-1);
	}
	

}

Paddle::Paddle(sf::Vector2f size, sf::Vector2f screenSize, PlayerKeyboard* keys) : m_Shape(size), m_ScreenSize(screenSize), m_Keys(*keys)
{
	m_Shape.setFillColor(sf::Color(255, 255, 255));
	m_Shape.setPosition(0, ((screenSize.y)/2)-(size.y/2));
}


Paddle::~Paddle()
{
}
