#include "Player.h"

#include <iostream>
#include <string>

Player::Player() {

}

Player::Player(std::string name) {
	this->_name = name;
}

Player::~Player() {

}

void Player::set_name() {
	std::cout << "Podaj swoje imie: ";
	std::cin >> this->_name;
}

void Player::add_symbol() {
	int number;
	bool correct = false;
	bool inserted = false;

	while (!inserted) {
		while (!correct) {
			std::cout << "Gdzie chcesz wstawic 'X'?\nPodaj numer od 1 do 9: ";
			std::cin >> number;
			if (std::cin.good() && number > 0 && number < 10)
				correct = true;
			std::cin.clear();
			std::cin.sync();
		}

		switch (number) { 
		case 1:
			if(_board->get_char(0,0) == ' ') {
				_board->set_symbol(0, 0, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 2:
			if (_board->get_char(1,0) == ' ') {
				_board->set_symbol(1, 0, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 3:
			if (_board->get_char(2,0) == ' ') {
				_board->set_symbol(2, 0, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 4:
			if (_board->get_char(0,1) == ' ') {
				_board->set_symbol(0, 1, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 5:
			if (_board->get_char(1,1) == ' ') {
				_board->set_symbol(1, 1, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 6:
			if (_board->get_char(2,1) == ' ') {
				_board->set_symbol(2, 1, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 7:
			if (_board->get_char(0,2) == ' ') {
				_board->set_symbol(0, 2, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 8:
			if (_board->get_char(1,2) == ' ') {
				_board->set_symbol(1, 2, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		case 9:
			if (_board->get_char(2,2) == ' ') {
				_board->set_symbol(2, 2, Cross);
				inserted = true;
			}
			else {
				std::cout << "Pole jest zajete, podaj inne miejsce...\n";
			}
			break;
		default:
			std::cout << "Cos poszlo nie tak\nSprobuj ponownie...\n"; 
		}
	}
}

void Player::assign_board(Board * board) {

	this->_board = board;
}