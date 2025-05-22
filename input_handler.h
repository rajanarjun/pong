#pragma once

class Paddle;

// using unsigned char* instead of Uint8* to avoid including SDL header here
void process_player_input(const unsigned char* keyState, Paddle& p1, Paddle& p2);