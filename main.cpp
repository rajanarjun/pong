#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"
#include "config.h"
#include "paddle.h"
#include "ball.h"

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error intitializing SDL" << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, 
                                   SDL_WINDOWPOS_CENTERED, 
                                   SCREEN_WIDTH, 
                                   SCREEN_HEIGHT, 
                                   SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "Error creating window:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
        std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

    Paddle player_1(0, (SCREEN_HEIGHT / 2) - (PADDLE_HEIGHT / 2));
    Paddle player_2((SCREEN_WIDTH - 30), (SCREEN_HEIGHT / 2) - (PADDLE_HEIGHT / 2));
    Ball ball( (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), BALL_RADIUS);

    TTF_Init();
    TTF_Font *font = TTF_OpenFont("font/FSEX302.ttf", 20);
    if (!font) std::cout << "Could not open font" << std::endl;

	game_loop(renderer, player_1, player_2, ball, PADDLE_Y_DELTA, font);

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
    return 0;
}
