#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "score.h"
#include "config.h"

SDL_Surface     *surface;
SDL_Texture     *texture;
SDL_Rect        text_rect;

void create_score_text(SDL_Renderer *renderer, TTF_Font *font) {

    std::string message = "Score : 0 | 0";
    SDL_Color color = {255, 255, 255, 255};

    surface = TTF_RenderText_Solid(font, message.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect text_rect;
    
    text_rect.x = (SCREEN_WIDTH - surface->w) / 2;
    text_rect.y = 10;
    text_rect.w = surface->w;
    text_rect.h = surface->h;

    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &text_rect);
}

void destroy_text() { 
    SDL_DestroyTexture(texture);
}
