#include "Game.h"

#ifdef _WIN32
#define main WinMain
#endif // If Windows is target platform use WinMain

int main()
{
	Game pong(800, 600, "pong");
	pong.Run();
	
}