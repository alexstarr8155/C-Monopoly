#ifndef BOARD_DISPLAY_H
#define BOARD_DISPLAY_H
#include "Board.h"

/* this class is reponsible for the printing of the board (tiles, players, improvements, etc) */

class BoardDisplay {

	private:
		Board& game;

	public:
		BoardDisplay(Board& game);
		~BoardDisplay();
		void display();

};

#endif
