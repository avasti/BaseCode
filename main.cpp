#include "Game.h"

int main(int argc, char* args[])
{
	if (Game::Instance()->init("Exerici 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)) {
		while (Game::Instance()->isRunning()) {
			Game::Instance()->render();
			Game::Instance()->handleEvents();
			Game::Instance()->update();

		}
		Game::Instance()->clean();
	}
	return 0;
}
