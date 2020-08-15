#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <map>
#include <string>
#include "Cell.h"
#include "Player.h"

/* this class represents the board */

class Board {
	
	int playerNum; // represents the number of players in the game
	int currPlayer; // represents the whose turn it is
	std::map<int, std::shared_ptr<Player>> players; // represents every player in the game (map provides an index method to the players for O(1) search)
	std::map<int, std::shared_ptr<Cell>> board; // represents every Tile in the game (map provides an index method to the Cell for O(1) search)
	int rollDouble = 0; // represents how many times a player rolled doubles
	int numTimsCard = 0; // represents the number of Tims Cards in circulation

	public:
		Board(std::map<const std::string, std::shared_ptr<Player>> & players, int num);
		Board(std::string fileName);
		~Board();

		void initBoard();

		int roll();
		void incRollDouble();
		void setRollDouble(int num);
		int getRollDouble();

		void move();
		void move(int diceRoll);
		void moveBy(int diceRoll);
		void moveTo(int loc);

		void playRound();

		void removePlayer(std::shared_ptr<Player> player);
		std::map<const std::string, std::shared_ptr<Player>> getPlayers();
		
		void setCurrPlayer(int i);
		int getCurrPlayerInt() const;
		std::shared_ptr<Player> getCurrPlayer();
		
		void addTimsCard();
		void removeTimsCard();

		void auction(int loc, int from);
		void save(std::string fileName);

		friend class BoardDisplay; // allows the BoardDisplay class to access the members of board to display the board's current state
};

#endif
