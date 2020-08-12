#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <map>
#include <string>
#include "Cell.h"
#include "Player.h"

class Board {
	
	int playerNum;
	int currPlayer;
	std::map<int, std::shared_ptr<Player>> players;
	std::map<int, std::shared_ptr<Cell>> board;

	bool rollDouble;

	public:
		Board(std::map<const std::string, std::shared_ptr<Player>> & players, int num);
		Board(int playerNum);
		~Board();
	
		void initBoard();	
		int roll();
		void move();
		void playRound();
		std::shared_ptr<Player> getCurrPlayer();
		void save(std::string fileName);

		friend class BoardDisplay;
};

#endif
