#include "game.h"

	//Iniciar SDL

	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;

	int main(int argc, char* args[])
	{

		Game game;

		if (game.init("videojocs 1", 100, 100, 800, 600, true) == false) {

			return 1;
		}

		while (game.IsRunning()) {

			game.EventHandler();
			game.Update();
			game.Render();
		}

		game.Clear();
		return 0;
		
		// clear the window to black
		SDL_RenderClear(g_pRenderer);

		// show the window
		SDL_RenderPresent(g_pRenderer);

		return 0;
	}