#pragma once
#include "Board.h"

#include <string>

class Player {
private:
	// Zmienne prywatne
	std::string _name = "Unnamed";
	Board * _board = nullptr;

public:
	// Konstruktor, destruktor
	Player();
	Player(std::string);
	~Player();
	// Funkcje klasy
	void assign_board(Board * board); //dopisz plansze do gracza w trakcie gry
	void set_name();
	void add_symbol();
};