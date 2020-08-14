#ifndef BOARD_DISPLAY_H
#define BOARD_DISPLAY_H
#include "Board.h"

class BoardDisplay {

	private:
		Board & game;
	public:
		BoardDisplay(Board& game);
		~BoardDisplay();

		void display(Board game);
		void display();

};

#endif
