#include "Game.h"
#include "misc.cpp"

Game::Game(unsigned int width, unsigned int height, std::string name) : m_Window(sf::VideoMode(width, height), name), m_PlayerOnePaddle(sf::Vector2f(15,100), sf::Vector2f(width,height), new PlayerKeyboard(sf::Keyboard::Left, sf::Keyboard::Right))
{

	m_Window.setVerticalSyncEnabled(true);

}

Game::~Game()
{
}

void Game::Run()
{
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

		m_Window.clear();
		m_Window.draw(m_PlayerOnePaddle.getPaddle());
		m_Window.display();
	}

}
