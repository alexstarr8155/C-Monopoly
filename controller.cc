#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Board.h"
#include "Player.h"
#include "Property.h"
#include "BoardDisplay.h"

void setupPlayers(std::map<const std::string, std::shared_ptr<Player>> & players) {
		std::cout << "Enter the Number of Players: ";
		int numPlayers = 0;
		std::cin >> numPlayers;
		//std::cout << std::endl;
		
		if (numPlayers < 2 || numPlayers > 8) {
			throw "Number of players must be between 2 and 8";
		}

		std::vector<char> takenPieces;
		std::vector<std::string> takenNames;
		std::vector<char> allowedPieces = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
		for (int i = 1; i <= numPlayers; i++) {
			std::string suffix = "th";

			if (i == 1) {
				suffix = "st";
			} else if (i == 2) {
				suffix = "nd";
			} else if (i == 3) {
				suffix = "rd";
			}

			std::cout << "Enter " << i << suffix << " player's name, then their board character: ";

			std::string temp;
			std::cin >> temp;

			//std::cout << players.size() << std::endl;

			char piece;
			std::cin >> piece;

			while (find(allowedPieces.begin(), allowedPieces.end(), piece) == allowedPieces.end() || 
					(find(takenPieces.begin(), takenPieces.end(), piece) != takenPieces.end() && !std::cin.eof()) ||
					(players.find(temp) != players.end()) || temp.compare("BANK") == 0) {


				if (std::cin.eof()) {
					break;
				}

				if (temp.compare("BANK") == 0) {
					std::cout << "Player's name cannot be BANK, choose name, followed by character: ";
					std::cin >> temp;
				} else if (players.find(temp) != players.end()) {
					std::cout << "Someone already has that name, choose another name, followed by character: ";
					std::cin >> temp;
				} else {
					std::cout << "Invalid or Duplicate piece, choose one of: ";

					for (int i = 0; i < allowedPieces.size(); i++) {
						if (find(takenPieces.begin(), takenPieces.end(), allowedPieces[i]) == takenPieces.end()) {
							std::cout << allowedPieces[i] << " ";
						}
					}

					std::cin >> piece;
				}
			}
			
			const std::string name = temp;	
			takenPieces.push_back(piece);

			if (std::cin.eof()) {
				break;
			}

			auto p = std::make_shared<Player> (name, piece, 1500);
			players.insert(players.begin(), std::pair<std::string, std::shared_ptr<Player>>(name, p));
		}

}

void printAssets (std::shared_ptr<Player> p){
	std::cout << p->getPlayerName() << ":" << std::endl;
	std::cout << "$" << p->getMoney() << std::endl;
	
	std::cout << "Properties:" << std::endl;
	auto prop = p->getProperties();
	for (auto it = prop.begin(); it != prop.end(); ++it){
		std::cout << (*it)->getName() << std::endl;
	}
}

Property* getProperty(std::string propName, Board& board) {
	auto currPlayer = board.getCurrPlayer();
	auto props = currPlayer->getProperties();
	
	Property* prop;

	for (auto it = props.begin(); it != props.end(); ++it){
		if ((*it)->getName() == propName){
			prop = (*it);
		}
	}

	return prop;
}

int main(int argc, char *argv[]) {

	Board *board;

	std::vector<std::string> args;

	for (int i = 0; i < argc; i++) {
		std::string temp(argv[i]);
		args.push_back(temp);
	}
	
//	Board board;
	std::map<const std::string, std::shared_ptr<Player>> players;
	bool testingMode = false;
	if (argc > 1 && args[1].compare("-testing") == 0) {
		testingMode = true;
	}
	if ((argc > 2 && args[1].compare("-testing") == 0) || (argc > 1 && args[1].compare("-testing") != 0)) {
		
		std::string filename = args[2];
		board = new Board(filename);

	} else {
		// "Starting game input needed"
		board = new Board(players, players.size());
		setupPlayers(players);
	}

	
	BoardDisplay display(*board);

	display.display();

	while (players.size() > 1 && !std::cin.eof()) {
		
		std::string cmd;
		std::cin >> cmd;

		//"For testing purposes"
		if (cmd.compare("r") == 0) {
			int n;
			std::cin >> n;

			board->moveBy(n);
			display.display();
		} else if (cmd.compare("roll") == 0) {
			
			if (testingMode) {
				int d1, d2;
				std::cin >> d1;
				std::cin >> d2;

				board->moveBy(d1 + d2);
				
				int numPlayers = players.size();
				int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
				board->setCurrPlayer(nextPlayer);
				

			} else {
				board->move();
			}

			display.display();

		} else if (cmd.compare("next") == 0) {
			
			int numPlayers = players.size();
			int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
			board->setCurrPlayer(nextPlayer);

		} else if (cmd.compare("trade") == 0) {
			std::string otherPlayer;
			std::cin >> otherPlayer;

			std::shared_ptr<Player> other = nullptr;
			for (auto it = players.begin(); it != players.end(); it++) {
				if ((it->second)->getPlayerName().compare(otherPlayer) == 0) {
					other = it->second;
					break;	
				}
			}
			if (other == nullptr) {
				std::cout << "That is not a valid other player" << std::endl;
				continue;
			}
			
			std::string give;
			std::cin >> give;
			int g = -1;

			try {
				g = std::stoi(give);
			} catch (...) {}

			std::string receive;
			std::cin >> receive;
			int r = -1;

			try {
				r = std::stoi(receive);
			} catch (...) {}

			Player* curr = board->getCurrPlayer().get();
			Property* pGive = getProperty(give, *board);
			Property* pReceive = getProperty(receive, *board);

			if (g != -1 && r != -1) {
				// "Trade with int version"
				std::cout << other->getPlayerName() << std::endl;
				

				curr->addMoney(r-g);
				other->removeMoney(r-g);
			} else if (g != -1) {
				// "Trade int for Property"
				curr->trade(other, g, pReceive);
			} else if (r != -1) {
				// "Trade Property with int"
				curr->trade(other, pGive, r);
			} else {

				curr->trade(other, pGive, pReceive);
			}

		} 
		else if (cmd.compare("improve") == 0) {
			std::string propName;
			std::cin >> propName;

			std::string buy;
			std::cin >> buy;	
			
			Property* prop = getProperty(propName, *board);

			if (!prop) {
				std::cout << "You don't own that property" << std::endl;
			}
			else if (buy == "buy") {
				prop->upgrade();
			}
			else if (buy == "sell") {
				prop->downgrade();
			}

			display.display();
			
		} 
		else if (cmd.compare("mortgage") == 0) {
			std::string prop;
			std::cin >> prop;
			Property* p = getProperty(prop, *board);

			try {
				p->mortgage();
			} catch (...) {
				std::cout << "There are improvements on this property, sell them before mortgaging" << std::endl;
			}
			
		} 
		else if (cmd.compare("unmortgage") == 0) {
			std::string prop;
			std::cin >> prop;
			Property * p = getProperty(prop, *board);

			p->unmortgage();
			//"unmortgage property
		} 
		else if (cmd.compare("bankrupt") == 0) {
			//"Declare bankruptcy"
		} 
		else if (cmd.compare("assets") == 0) {
			// "Display the assets of the current player"
			printAssets(board->getCurrPlayer());
		} 
		else if (cmd.compare("all") == 0) {
			//"Display the assets of all players"
			for (auto it = players.begin(); it != players.end(); ++it){
				printAssets(it->second);
			}
		} 
		else if (cmd.compare("save") == 0) {
			std::string filename;
			std::cin >> filename;
			board->save(filename);
		} else {
			if (!std::cin.eof()) {
				std::cout << "Invalid command, try again: ";
			}
		}
	}
	delete board;
}



