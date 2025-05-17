#include "paddle.h"
#include "config.h"

Paddle::Paddle(int startX, int startY) {
    rect.x = startX;
    rect.y = startY;
    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;
}

void Paddle::move(int dy) {
    rect.y += dy;
}

void Paddle::render(SDL_Renderer* renderer) const {
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Paddle::getRect() const {
    return rect;
}
