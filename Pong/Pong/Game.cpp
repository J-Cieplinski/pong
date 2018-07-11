#include "Game.h"
#include "misc.cpp"

Game::Game(sf::Vector2f screenSize, std::string name) : m_Window(sf::VideoMode(screenSize.x, screenSize.y), name), 
			m_PlayerOnePaddle(sf::Vector2f(15, 100), screenSize, new PlayerKeyboard(sf::Keyboard::Left, sf::Keyboard::Right), PlayerSide::LEFT), 
			m_PlayerTwoPaddle(sf::Vector2f(15, 100), screenSize, new PlayerKeyboard(sf::Keyboard::A, sf::Keyboard::D), PlayerSide::RIGHT),
			m_Ball(screenSize)
{

	m_Window.setVerticalSyncEnabled(true);

}

Game::~Game()
{
}

void Game::Run()
{
	std::srand(std::time(nullptr));

	while(m_Window.isOpen())
	{
		while(m_Window.pollEvent(m_Event))
		{
			if(sf::Event::Closed == m_Event.type)
			{
				m_Window.close();
			}

		}
		m_PlayerOnePaddle.UpdatePosition();
		m_PlayerTwoPaddle.UpdatePosition();
		m_Ball.UpdatePosition();

		m_Window.clear();
		m_Window.draw(m_PlayerOnePaddle.GetPaddle());
		m_Window.draw(m_PlayerTwoPaddle.GetPaddle());
		m_Window.draw(m_Ball.GetBall());
		m_Window.display();
	}

}
