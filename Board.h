#pragma once

enum Symbols {
	Empty,
	Cross,
	Circle
};

class Board {
private:
// Zmienne prywatne
	Symbols _field[3][3];
public:
// Konstruktor, destruktor
	Board();
	~Board();
// Funkcje klasy
	void erase_board(); 

	void draw_board();

	char get_char(int, int);
	void set_symbol(int, int, Symbols);
};