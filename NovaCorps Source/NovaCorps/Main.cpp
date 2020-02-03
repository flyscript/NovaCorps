/*
	NovaCorps - main.cpp
		William Chapman

		12/11/2018 10:38:29 AM

		This is the code main entry point

*/

#include "NovaCorps.h"
#define NOMINMAX
#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	NovaCorps* m_game = new NovaCorps();

	m_game->run();

	delete m_game;

	return 0;
}
