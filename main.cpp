#include <iostream>
#include "board.h"

int main() {
	char stop;
	// main
	Board board;
	board.erase_board();
	board.draw_board();
	// stop
	std::cin >> stop;
}