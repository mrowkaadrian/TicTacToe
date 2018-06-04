#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() {
	start_game();
}

Game::~Game() {

}

void Game::start_game() { // inicjalizacja gry (wybranie kto zaczyna, przypisanie planszy do gracza)

	srand((unsigned int)std::time(NULL));
	if ((std::rand() % 2) == 1) {   // coinflip: 1 - zaczyna gracz, 0 - zaczyna komputer
		_startingPlayer = true;
	}
	else {
		_startingPlayer = false;
	}

	this->_player->assign_board(this->_board);
	this->_computer->assign_board(this->_board);

	game_loop();
}

void Game::game_loop() { // petla gry: X - gracz, O - komputer
	bool exit = false;
	int winner;

	if (_startingPlayer)
		std::cout << "Ty zaczynasz!\n\n";
	else
		std::cout << "Zaczyna komputer!\n\n";

	while (!exit) {

		_board->draw_board();

		if (_startingPlayer == true) { // tura gracza
			_player->add_symbol();
		}
		else { // tura komputera
			_computer->add_symbol();
		}

		if (check_score(winner))
			exit = true;

		std::cout << ". . . wcisnij ENTER, aby kontynuowac . . .\n";
		std::cin.get();

		system("cls");

		_startingPlayer = !_startingPlayer; // zmiana tury
	}

	system("cls");
	_board->draw_board();
	print_score(winner);


	// koniec gry - wyswietlenie wynikow
}

bool Game::check_score(int & winner) { // Funkcja sprawdza, czy ktos wygral, a jesli nie, to czy nadal jest miejsce na planszy. jeœli ktorys z przypadkow zostal spelniony, zatrzymuje gre i printuje wynik.

	// uwaga, to bedzie biedacko napisane, ale nie mam w tej chwili weny algorytmowej, ¿eby zwiezlej to napisac (jakis pattern matching bylby potrzebny)
	bool p_won = false, c_won = false, draw = false;

	for (int i = 0; i < 3; ++i) { // wygrana/przegrana

		if (_board->get_char(i, 0) == 'X' && _board->get_char(i, 1) == 'X' && _board->get_char(i, 2) == 'X') // 3 krzyze pionowo - gracz wygral
			p_won = true;
		if (_board->get_char(i, 0) == 'O' && _board->get_char(i, 1) == 'O' &&  _board->get_char(i, 2) == 'O') // 3 kolka pionowo - komputer wygral
			c_won = true;
		if (_board->get_char(0, i) == 'X' && _board->get_char(1, i) == 'X' && _board->get_char(2, i) == 'X') // 3 krzyze poziomo - gracz wygral
			p_won = true;
		if (_board->get_char(0, i) == 'O' && _board->get_char(1, i) == 'O' && _board->get_char(2, i) == 'O') // 3 kolka poziomo - komputer wygral
			c_won = true;
	}

	if (_board->get_char(0, 0) == 'X' && _board->get_char(1, 1) == 'X' && _board->get_char(2, 2) == 'X') // 3 krzyze na skos - gracz wygral "\"
		p_won = true;
	if (_board->get_char(0, 0) == 'O' && _board->get_char(1, 1) == 'O' && _board->get_char(2, 2) == 'O') // 3 kolka na skos - komputer wygral "\"
		c_won = true;
	if (_board->get_char(2, 0) == 'X' && _board->get_char(1, 1) == 'X' && _board->get_char(0, 2) == 'X') // 3 krzyze na skos - gracz wygral "/"
		p_won = true;
	if (_board->get_char(2, 0) == 'O' && _board->get_char(1, 1) == 'O' && _board->get_char(0, 2) == 'O') // 3 kolka na skos - komputer wygral "/"
		c_won = true;
			

	if (!p_won && !c_won) {
		draw = true;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (_board->get_char(i,j) == ' ')
					draw = false;
	}
	
	bool stop_game = false;

	if (p_won || c_won || draw)
		stop_game = true;

	// ustawienie wyniku na adresie 'inta' podanego przy wywolaniu funkcji (0/1/2) 
	if (p_won)
		winner = 1;
	if (c_won)
		winner = 2;
	if (draw)
		winner = 0;

	return stop_game; // false - gra powinna nadal trwac / true - gra powinna sie zakonczyc
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