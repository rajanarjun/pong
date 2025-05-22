#pragma once

#include <SDL2/SDL.h>

class Paddle {
    private:
        SDL_Rect rect;
    public:
        Paddle(int startX, int startY);

        void move_up(int dy);
        void move_down(int dy);
        void render(SDL_Renderer* renderer) const;
        const SDL_Rect& getRect() const;
};
        