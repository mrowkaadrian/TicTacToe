#pragma once
#include "Player.h"
class Computer :
	public Player
{
private:
	Board * _board2;
public:
	Computer();
	~Computer();

	void add_symbol();
	void assign_board(Board * board); //dopisz plansze do gracza w trakcie gry
};

