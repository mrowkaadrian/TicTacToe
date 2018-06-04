#pragma once
#include "Board.h"
#include "Player.h"
#include "Computer.h"

class Game {
private:
	// Zmienne prywatne
	Board _board;
	Player _player;
	Computer _computer;
public:
	// Konstruktor, destruktor
	Game();
	~Game();
	// Funkcje klasy
	void start_game();
	void game_loop();
	bool check_score();
	void print_score(int);
	void exit();
};