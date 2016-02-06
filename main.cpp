#include "SDL.h"
#undef main
#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* args[]) {
	cout << "Prem ESC per tancar el programa." << endl;
	cout << "Prem F11 per canviar de pantalla completa a finestra." << endl;
	cout << "Si estas llegint aquest missatge, vol dir que tens el programa en mode finestra. Prem F11 per posar-lo a pantalla completa." << endl;
	if (!Game::GetInstance()->Init("Sonic Game", 100, 100, 900, 500, false)) {
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
