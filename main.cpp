#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "config.h"
#include "paddle.h"
#include "ball.h"
 
using namespace std;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Error intitializing SDL" << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, 
                                   SDL_WINDOWPOS_CENTERED, 
                                   SCREEN_WIDTH, 
                                   SCREEN_HEIGHT, 
                                   SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        cout << "Error creating window:" << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		cout << "Error creating renderer:" << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

    Paddle player_1(0, (SCREEN_HEIGHT/2) - (PADDLE_HEIGHT / 2));
    Paddle player_2((SCREEN_WIDTH - 30), (SCREEN_HEIGHT/2) - (PADDLE_HEIGHT / 2));
    Ball ball;
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.r = BALL_RADIUS;

	game_loop(win, renderer, player_1, player_2, ball, DELTA);

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
    return 0;
}
