#include "SDL.h"
#undef main
#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* args[]) {
	if (!Game::GetInstance()->Init("Sonic Game", 100, 100, 999, 600, false)) {
		return 1;
	}
	while (Game::GetInstance()->IsRunning()) {
		Game::GetInstance()->EventHandler();
		Game::GetInstance()->Update();
		Game::GetInstance()->Render();
	}
	Game::GetInstance()->Clear();
	return 0;
}
