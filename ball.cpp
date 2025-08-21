#include "ball.h"
#include "config.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

Ball::Ball(double x_coord, double y_coord, double radius) {
    x = x_coord;
    y = y_coord;
    r = radius;
}

void Ball::render_ball(SDL_Renderer *renderer) const {
    if (filledCircleRGBA(renderer,
                     static_cast<Sint16>(x),
                     static_cast<Sint16>(y),
                     static_cast<Sint16>(r), 
                     255, 255, 255, 255) != 0) {
        std::cout << "Failed to render ball" << std::endl;
    }
}
