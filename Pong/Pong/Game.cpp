#include "Game.h"
#include "misc.cpp"
#include <chrono>
#include <thread>

Game::Game(sf::Vector2f screenSize, std::string name) : m_Window(sf::VideoMode(screenSize.x, screenSize.y), name), m_PaddleSize(15, 100),
			m_PlayerOnePaddle(m_PaddleSize, screenSize, new PlayerKeyboard(sf::Keyboard::Left, sf::Keyboard::Right), PlayerSide::LEFT), 
			m_PlayerTwoPaddle(m_PaddleSize, screenSize, new PlayerKeyboard(sf::Keyboard::A, sf::Keyboard::D), PlayerSide::RIGHT),
			m_Ball(screenSize), m_PlayersInfo(m_PlayerOnePaddle.GetPaddle().getPosition(), m_PlayerTwoPaddle.GetPaddle().getPosition())
{
    m_Font.loadFromFile("arial.ttf");

    int* i = new int(0);
    *i = -30;
    for(auto& x: m_Score)
    {
        x.setFont(m_Font);
        x.setFillColor(sf::Color::White);
        x.setStyle(sf::Text::Bold);
        x.setCharacterSize(30);
        x.setString("0");
        x.setPosition(screenSize.x / 2 + (*i), 0);
        *i = 0;
    }
    delete i;
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
		UpdatePlayersInfo();
		m_Ball.UpdatePosition(m_PlayersInfo, m_PaddleSize);
        UpdateScores();

		m_Window.clear();
		m_Window.draw(m_PlayerOnePaddle.GetPaddle());
		m_Window.draw(m_PlayerTwoPaddle.GetPaddle());
		m_Window.draw(m_Ball.GetBall());
		for(auto& x : m_Score) {
            m_Window.draw(x);
        }
		m_Window.display();
	}

}

void Game::UpdateScores()
{
    m_Score[0].setString(std::to_string(m_PlayersInfo.getPlayerOneScore()));
    m_Score[1].setString(std::to_string(m_PlayersInfo.getPlayerTwoScore()));

}

void Game::UpdatePlayersInfo()
{
    m_PlayersInfo.PlayerOne = m_PlayerOnePaddle.GetPaddle().getPosition();
    m_PlayersInfo.PlayerTwo = m_PlayerTwoPaddle.GetPaddle().getPosition();

}
