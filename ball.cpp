#include "ball.h"
#include "config.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void fill_circle(SDL_Renderer *renderer, Ball *b) {

    filledCircleRGBA(renderer, b->x, b->y, b->r, 255, 255, 255, 255);

}
