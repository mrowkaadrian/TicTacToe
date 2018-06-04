#include "Game.h"

#include <iostream>

Game::Game() {

}

Game::~Game() {

}

void Game::start_game() {
	
}

void Game::game_loop() { // petla gry: X - gracz, O - komputer
	bool exit = false;

	while (!exit) {

	}
}

bool Game::check_score() { // Funkcja sprawdza, czy ktos wygral, a jesli nie, to czy nadal jest miejsce na planszy. jeœli ktorys z przypadkow zostal spelniony, zatrzymuje gre i printuje wynik.

	// uwaga, to bedzie biedacko napisane, ale nie mam w tej chwili weny algorytmowej, ¿eby bardziej zwiezle to napisac
	bool p_won = false, c_won = false, draw = false;

	for (int i = 0; i < 3; ++i) { // wygrana/przegrana

		if (_board->get_char(i, 0) == _board->get_char(i, 1) == _board->get_char(i, 2) == Cross) // 3 krzyze pionowo - gracz wygral
			p_won = true;
		if (_board->get_char(i, 0) == _board->get_char(i, 1) == _board->get_char(i, 2) == Circle) // 3 kolka pionowo - komputer wygral
			c_won = true;
		if (_board->get_char(0, i) == _board->get_char(1, i) == _board->get_char(2, i) == Cross) // 3 krzyze poziomo - gracz wygral
			p_won = true;
		if (_board->get_char(0, i) == _board->get_char(1, i) == _board->get_char(2, i) == Circle) // 3 kolka poziomo - komputer wygral
			c_won = true;
	}

	if (_board->get_char(0, 0) == _board->get_char(1, 1) == _board->get_char(2, 2) == Cross) // 3 krzyze na skos - gracz wygral "\"
		p_won = true;
	if (_board->get_char(0, 0) == _board->get_char(1, 1) == _board->get_char(2, 2) == Circle) // 3 kolka na skos - komputer wygral "\"
		c_won = true;
	if (_board->get_char(2, 0) == _board->get_char(1, 1) == _board->get_char(0, 2) == Cross) // 3 krzyze na skos - gracz wygral "/"
		p_won = true;
	if (_board->get_char(2, 0) == _board->get_char(1, 1) == _board->get_char(0, 2) == Circle) // 3 kolka na skos - komputer wygral "/"
		c_won = true;
			

	if (!p_won && !c_won) {
		draw = true;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (_board->get_char(i,j) == Empty)
					draw = false;
	}
		
	return true;
}

void Game::print_score(int number) { // 0 = remis, 1 = gracz wygral, 2 = komputer wygral
	if (number == 0) {
		std::cout << "O nie! Brak mozliwych ruchow. Remis.\n";
	} else if (number == 1) {
		std::cout << "Gratulacje, wygrales!\n";
	} else if (number == 2) {
		std::cout << "Przegrales, postaraj sie bardziej nastepnym razem...\n";
	}
}

void Game::exit() {

}