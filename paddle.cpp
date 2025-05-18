#include "paddle.h"
#include "config.h"

Paddle::Paddle(int startX, int startY) {
    rect.x = startX;
    rect.y = startY;
    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;
}

void Paddle::move_up(int dy) {
    rect.y = rect.y - dy;
}

void Paddle::move_down(int dy) {
    rect.y = rect.y + dy;
}

void Paddle::render(SDL_Renderer* renderer) const {
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Paddle::getRect() const {
    return rect;
}
