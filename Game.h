#pragma once
#include "Board.h"
#include "Player.h"
#include "Computer.h"

class Game {
private:
	// Zmienne prywatne
	Board * _board = new Board();
	Player * _player = new Player();
	Computer * _computer = new Computer();
	bool _startingPlayer;
public:
	// Konstruktor, destruktor
	Game();
	~Game();
	// Funkcje klasy
	void start_game();
	void game_loop();
	bool check_score(int & winner);
	void print_score(int);
};