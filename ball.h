#pragma once

#include <SDL2/SDL.h>

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
        void side_wall_collision();
};

