#pragma once
#include <SFML/Window/Keyboard.hpp>

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