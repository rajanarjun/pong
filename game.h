#pragma once

#include <SDL2/SDL.h>
#include "paddle.h"
#include "ball.h"

void game_loop(SDL_Window *win, SDL_Renderer *renderer, Paddle &player_1, Paddle &player_2, Ball &ball, int delta);
