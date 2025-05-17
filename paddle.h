#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>

class Paddle {
    private:
        SDL_Rect rect;
    public:
        Paddle(int startX, int startY);

        void move(int dy);
        void render(SDL_Renderer* renderer) const;
        const SDL_Rect& getRect() const;
};
        
#endif
