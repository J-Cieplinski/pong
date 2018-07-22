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

struct PlayersInformation
{
public:
	sf::Vector2f PlayerOne;
	sf::Vector2f PlayerTwo;
private:
	int 		 PlayerOneScore;
	int 		 PlayerTwoScore;
public:
	PlayersInformation(const sf::Vector2f& one, const sf::Vector2f& two) : PlayerOne(one), PlayerTwo(two),
                                                                           PlayerOneScore(0), PlayerTwoScore(0) {};
	void IncreasePlayerOneScore() {++PlayerOneScore;}
	void IncreasePlayerTwoScore() {++PlayerTwoScore;}
	const int getPlayerOneScore() {return PlayerOneScore;}
    const int getPlayerTwoScore() {return PlayerTwoScore;}

};