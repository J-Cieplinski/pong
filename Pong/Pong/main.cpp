#include "Game.h"

#ifdef _WIN32
#define main WinMain
#endif // If Windows is target platform use WinMain

#define	WIDTH	800
#define	HEIGHT	600


int main()
{
    std::srand(std::time(nullptr));


    Game pong(sf::Vector2f(WIDTH, HEIGHT), "pong");
	pong.Run();
	
}