#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include "paddle.h"
#include "input_handler.h"
#include "game.h"
#include "ball.h"

using namespace std;

void game_loop(SDL_Window *win, SDL_Renderer *renderer, Paddle &player_1, Paddle &player_2, Ball &ball, int delta) {

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
        process_player_input(keystate, player_1, player_2, delta);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        player_1.render(renderer);
        player_2.render(renderer);

        fill_circle(renderer, &ball);

		SDL_RenderPresent(renderer);
        SDL_Delay(16);
	}
}
