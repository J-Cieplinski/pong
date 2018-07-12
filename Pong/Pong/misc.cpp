#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

class PlayerKeyboard
{
public:
	sf::Keyboard::Key Up;
	sf::Keyboard::Key Down;
	PlayerKeyboard(sf::Keyboard::Key u, sf::Keyboard::Key d) : Up(u), Down(d) {};
};

enum PlayerSide
{
		LEFT,
		RIGHT
};

struct PlayersPosition
{
	sf::Vector2f PlayerOne;
	sf::Vector2f PlayerTwo;
	PlayersPosition(const sf::Vector2f& one, const sf::Vector2f& two) : PlayerOne(one), PlayerTwo(two) {};
};