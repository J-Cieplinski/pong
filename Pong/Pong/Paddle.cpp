#include "Paddle.h"

/*
void Paddle::drawPaddle(sf::RenderWindow const& window)
{
	window.draw(m_Shape);
}
*/
const sf::RectangleShape& Paddle::getPaddle()
{
	return m_Shape;
}

void Paddle::UpdatePosition()
{
	auto position = m_Shape.getPosition();
	if (!reverse)
	{
		position += sf::Vector2f(0, 1);
		
		if((position.y + m_Shape.getSize().y) >= m_ScreenSize.y)
		{
			reverse = true;
		}
	}
	else if(reverse)
	{
		position += sf::Vector2f(0, -1);

		if(position.y <= 0)
		{
			reverse = false;
		}
	}
	
	m_Shape.setPosition(position);
}

Paddle::Paddle(sf::Vector2f size, sf::Vector2f screenSize) : m_Shape(size), m_ScreenSize(screenSize)
{
	m_Shape.setFillColor(sf::Color(255, 255, 255));
	m_Shape.setPosition(0, ((screenSize.y)/2)-(size.y/2));

}


Paddle::~Paddle()
{
}
