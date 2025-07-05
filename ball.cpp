#include "ball.h"
#include "config.h"

void RenderCircle(SDL_Renderer* renderer, int x0, int y0) {

    int x = BALL_RADIUS - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (BALL_RADIUS << 1);

	while (x >= y){
		SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);

		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}
		
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (BALL_RADIUS << 1);
		}
	}
}
