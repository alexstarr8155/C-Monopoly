#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <map>
#include <string>
#include "Cell.h"
#include "Player.h"

class Board {
	
	int playerNum;
	std::map<int, std::shared_ptr<Player>> players;
	std::map<int, std::shared_ptr<Cell>> board;

	bool rollDouble;

	public:
		Board(int playerNum);
		~Board();
		
		int roll();
		void playRound();

		friend class BoardDisplay;
};

#endif
