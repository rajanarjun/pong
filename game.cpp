#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>
#include "paddle.h"
#include "input_handler.h"
#include "game.h"
#include "ball.h"
#include "score.h"

void game_loop(SDL_Renderer *renderer, Paddle &player_1, Paddle &player_2, Ball &ball, int paddle_y_delta, TTF_Font *font) {

	SDL_Event event; 
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        process_player_input(keystate, player_1, player_2, paddle_y_delta);
        ball.move_ball();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        player_1.render_paddle(renderer);
        player_2.render_paddle(renderer);
        ball.render_ball(renderer);

        create_score_text(renderer, font);

		SDL_RenderPresent(renderer);
        SDL_Delay(16);
	}
    destroy_text();
}
