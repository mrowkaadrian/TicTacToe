#include "Computer.h"

#include <cstdlib>
#include <ctime>

Computer::Computer() {

}

Computer::~Computer() {

}

void Computer::add_symbol() { // Uposledzona "sztuczna inteligencja" polegajaca na randomie, jak bede mial czas, to napisze to inaczej
	srand((unsigned int)time(NULL));
	int x, y;

	if (_board2->get_char(1, 1) == ' ') {
		_board2->set_symbol(1, 1, Circle);
		return;
	}

	while (true) { // nieskonczona petla powodujaca wymuszenie wylosowania takiego pola, ktore w koncu bedzie wolne
		x = (rand() % 3);
		y = (rand() % 3);

		if (_board2->get_char(x, y) == ' ') {
			_board2->set_symbol(x, y, Circle);
			return;
		}
	}
}

void Computer::assign_board(Board * board) {

	this->_board2 = board;
}