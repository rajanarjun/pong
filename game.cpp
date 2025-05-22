#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include "config.h"
#include "paddle.h"
#include "input_handler.h"

using namespace std;

int main() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Error intitializing SDL" << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		cout << "Error creating window:" << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		cout << "Error creating renderer:" << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

    Paddle player_1(0, (SCREEN_HEIGHT/2) - (PADDLE_HEIGHT / 2));
    Paddle player_2((SCREEN_WIDTH - 30), (SCREEN_HEIGHT/2) - (PADDLE_HEIGHT / 2));

	SDL_Event event; 
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				cout << "Closing window" << endl;
				running = false;
			}
		}

        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        process_player_input(keystate, player_1, player_2);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        player_1.render(renderer);
        player_2.render(renderer);

		SDL_RenderPresent(renderer);
        SDL_Delay(16);

	}
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();

    return 0;
}
