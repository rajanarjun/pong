#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "paddle.h"
#include "ball.h"

void game_loop(SDL_Renderer *renderer, Paddle &player_1, Paddle &player_2, Ball &ball, int delta, TTF_Font *font);
