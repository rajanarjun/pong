#pragma once

#include <SDL2/SDL.h>

class Ball {
    private:
        double x;
        double y;
        double r;

    public:
        Ball(double x_coord, double y_coord, double radius);

        void render_ball(SDL_Renderer* renderer) const;
};

