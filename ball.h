#pragma once

#include <SDL2/SDL.h>
#include "paddle.h"

class Ball {
    private:
        double r;
        double dir_x;
        double dir_y;
        double speed;
        double init_max_angle;

    public:
        double x;
        double y;

        Ball();

        void render_ball(SDL_Renderer* renderer) const;
        void move_ball();
        void check_collision(Paddle &p1, Paddle &p2);
};

