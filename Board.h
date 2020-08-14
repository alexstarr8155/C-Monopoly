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
		Board(std::string fileName);
		~Board();
		
		std::map<const std::string, std::shared_ptr<Player>> getPlayers();

		void initBoard();	
		int roll();
		void move();
		void moveBy(int diceRoll);
		void moveTo(int loc);
		void playRound();
		int getCurrPlayerInt() const;
		void setCurrPlayer (int i);
		
		void removePlayer(std::shared_ptr<Player> player);

		void auction (int loc, int from);
		std::shared_ptr<Player> getCurrPlayer();
		void save(std::string fileName);
		void load(std::string fileName);

		friend class BoardDisplay;
};

#endif
