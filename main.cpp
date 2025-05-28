#include "game.h"

int main() {
	if (initialize_game() != 0) {
		return 1;
	}
	game_loop();
	destroy_game();
    return 0;
}
