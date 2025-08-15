#pragma once

#include <SDL2/SDL.h>

typedef struct {
    double x;
    double y;
    double r;
} Ball;

void fill_circle(SDL_Renderer *renderer, Ball *b);
