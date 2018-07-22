#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "misc.cpp"



class Ball
{
    //TODO maybe clean this class up and figure out a way to make this slimmer
private:
	sf::CircleShape m_Ball;
	sf::Vector2f	m_ScreenSize;
	sf::Vector2f	m_Direction;
	sf::Vector2f	m_StartingPosition;
	sf::SoundBuffer m_lossSound;
	sf::SoundBuffer m_paddleSound;
	sf::SoundBuffer m_wallSound;
	sf::Sound       m_Sound;
    float			m_Acceleration;
    float			m_BallRadius;
public:
	Ball(sf::Vector2f& screenSize);
	~Ball();
	const sf::CircleShape & GetBall() const;
	void UpdatePosition(PlayersInformation &paddlePositions, const sf::Vector2f &paddleSize);
private:
	void CheckCollisionAndMove(const sf::Vector2f &paddleSize, PlayersInformation &paddleInfo);
	void ChangeDirectionAndMove(float& directionToChange);
	void RandomizeDirection();
};

