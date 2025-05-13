#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL could not initialize, SDL_Error:" << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("game window", 
                                        SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										SCREEN_WIDTH,
										SCREEN_HEIGHT,
										SDL_WINDOW_SHOWN);
	if (!win) {
		cerr << "Window could not be created, SDL_Error:" << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Surface* screenSurface = SDL_GetWindowSurface(win);
	SDL_UpdateWindowSurface(win);

	SDL_Event event; 
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				cout << "Closing window" << endl;
				running = false;
			}
			if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN || event.type == SDLK_RIGHT || event.type == SDLK_LEFT) {
				cout << "Key Pressed: " << SDL_GetKeyName(event.key.keysym.sym) << endl;
			}
		}
	}

	SDL_DestroyWindow(win);
	SDL_Quit();

    return 0;
}
