#include <SDL2/SDL.h>
#include "paddle.h"
#include "input_handler.h"
#include "config.h"

void process_player_input(const Uint8* keyState, Paddle& p1, Paddle& p2, int delta) {

    const SDL_Rect& p1_rect = p1.getRect();
    const SDL_Rect& p2_rect = p2.getRect();

    if (keyState[SDL_SCANCODE_W] && p1_rect.y >= 0) {
        //cout << "W is held down\n";
        p1.move_up(delta);
    }
    if (keyState[SDL_SCANCODE_S] && p1_rect.y <= (SCREEN_HEIGHT - PADDLE_HEIGHT)) {
        //cout << "S is held down\n";
        p1.move_down(delta);
    }
    if (keyState[SDL_SCANCODE_UP] && p2_rect.y >= 0) {
        //cout << "A is held down\n";
        p2.move_up(delta);
    }
    if (keyState[SDL_SCANCODE_DOWN] && p2_rect.y <= (SCREEN_HEIGHT - PADDLE_HEIGHT)) {
        //cout << "D is held down\n";
        p2.move_down(delta);
    }

}
