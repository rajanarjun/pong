#include "ball.h"
#include "config.h"
#include <iostream>
#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

Ball::Ball() {
    x = (SCREEN_WIDTH / 2);
    y = (SCREEN_HEIGHT / 2);
    r = BALL_RADIUS;
    speed = 6.0;
    init_max_angle = M_PI;

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<> angle_dist(-init_max_angle, init_max_angle);
    std::uniform_int_distribution<> flip_dist(0, 1);

    // random angle in radians
    double angle = angle_dist(gen);

    // random direction
    if (flip_dist(gen) == 0) angle = M_PI - angle;

    dir_x = speed * cos(angle);
    dir_y = speed * sin(angle);
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


void Ball::move_ball() {
    x += dir_x;
    y += dir_y;
}


void Ball::side_wall_collision() {
    if (y - r <= 0) {
        y = r;
        dir_y *= -1;
    } else if (y + r >= SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - r;
        dir_y *= -1;
    }
}

