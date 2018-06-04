#include "Board.h"
#include <iostream>

Board::Board() {

}

Board::~Board() {

}

void Board::erase_board() {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			this->_field[i][j] = Empty;
}

void Board::draw_board() {
	// SYMBOLE ASCII
	char s_ur = 200, s_dr = 201, s_ul = 188, s_dl = 187, s_cr = 206; // cr = cross, u = up, d = down, l = left, r = right
	char s_d = 203, s_l = 185, s_u = 202, s_r = 204;
	char s_v = 186, s_h = 205; // v = vertical, h - horizontal
	// KONIEC SYMBOLI

	std::cout << "Aktualny stan gry:\n\n  " << s_dr << s_h << s_h << s_h << s_h << s_h << s_d << s_h << s_h << s_h << s_h << s_h << s_d << s_h << s_h << s_h << s_h << s_h << s_dl << '\n';
	std::cout << "  " << s_v << "1    " << s_v << "2    " << s_v << "3    " << s_v << '\n';
	std::cout << "  " << s_v << "  " << get_char(0, 0) << "  " << s_v << "  " << get_char(1, 0) << "  " << s_v << "  " << get_char(2, 0) << "  " << s_v << '\n';
	std::cout << "  " << s_v << "     " << s_v << "     " << s_v << "     " << s_v << '\n';
	std::cout << "  " << s_r << s_h << s_h << s_h << s_h << s_h << s_cr << s_h << s_h << s_h << s_h << s_h << s_cr << s_h << s_h << s_h << s_h << s_h << s_l << '\n';
	std::cout << "  " << s_v << "4    " << s_v << "5    " << s_v << "6    " << s_v << '\n';
	std::cout << "  " << s_v << "  " << get_char(0, 1) << "  " << s_v << "  " << get_char(1, 1) << "  " << s_v << "  " << get_char(2, 1) << "  " << s_v << '\n';
	std::cout << "  " << s_v << "     " << s_v << "     " << s_v << "     " << s_v << '\n';
	std::cout << "  " << s_r << s_h << s_h << s_h << s_h << s_h << s_cr << s_h << s_h << s_h << s_h << s_h << s_cr << s_h << s_h << s_h << s_h << s_h << s_l << '\n';
	std::cout << "  " << s_v << "7    " << s_v << "8    " << s_v << "9    " << s_v << '\n';
	std::cout << "  " << s_v << "  " << get_char(0, 2) << "  " << s_v << "  " << get_char(1, 2) << "  " << s_v << "  " << get_char(2, 2) << "  " << s_v << '\n';
	std::cout << "  " << s_v << "     " << s_v << "     " << s_v << "     " << s_v << '\n';
	std::cout << "  " << s_ur << s_h << s_h << s_h << s_h << s_h << s_u << s_h << s_h << s_h << s_h << s_h << s_u << s_h << s_h << s_h << s_h << s_h << s_ul << '\n';

}

char Board::get_char(int x, int y) {
	if (x < 0 || x > 2 || y < 0 || y > 2)
		return ' ';
	if (_field[x][y] == Empty)
		return ' ';
	else if (_field[x][y] == Cross)
		return 'X';
	else if (_field[x][y] == Circle)
		return 'O';

	return ' ';
}
