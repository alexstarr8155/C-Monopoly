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

int main(int argc, char *argv[]) {
	
//	Board board;

	std::map<const std::string, std::shared_ptr<Player>> players;
	if (argc > 1) {
		// "Load file given"
	} else {
		// "Starting game input needed"
		
		setupPlayers(players);
	}

	Board board(players, players.size());
	BoardDisplay display(board);

	display.display();

	while (players.size() > 1 && !std::cin.eof()) {
		
		std::string cmd;
		std::cin >> cmd;

		//"For testing purposes"
		if (cmd.compare("r") == 0) {
			int n;
			std::cin >> n;

			board.moveBy(n);
			display.display();
		} else if (cmd.compare("roll") == 0) {
			
			board.move();
			display.display();

		} else if (cmd.compare("next") == 0) {
			
		} else if (cmd.compare("trade") == 0) {
			std::string otherPlayer;
			std::cin >> otherPlayer;

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


			if (g != -1 && r != -1) {
				// "Trade with int version"	

			} else if (g != -1) {
				// "Trade int for Property"
			} else if (r != -1) {
				// "Trade Property with int"
			} else {
				// "Trade Prop with Prop"
			}

		} 
		else if (cmd.compare("improve") == 0) {
			std::string propName;
			std::cin >> propName;

			std::string buy;
			std::cin >> buy;

			auto currPlayer = board.getCurrPlayer();
			auto props = currPlayer->getProperties();
			
			Property* prop;

			for (auto it = props.begin(); it != props.end(); ++it){
				if ((*it)->getName() == propName){
					prop = (*it);
				}
			}
			
			if (!prop) {
				std::cout << "You don't own that property" << std::endl;
			}
			else if (buy == "buy") {
				prop->upgrade(1);
			}
			else if (buy == "sell") {
				prop->downgrade(1);
			}
			
		} 
		else if (cmd.compare("mortgage") == 0) {
			std::string prop;
			std::cin >> prop;

			//"Mortgage Property
		} 
		else if (cmd.compare("unmortgage") == 0) {
			std::string prop;
			std::cin >> prop;

			//"unmortgage property
		} 
		else if (cmd.compare("bankrupt") == 0) {
			//"Declare bankruptcy"
		} 
		else if (cmd.compare("assets") == 0) {
			// "Display the assets of the current player"
			printAssets(board.getCurrPlayer());
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
			// "Save the game"
		} else {
			if (!std::cin.eof()) {
				std::cout << "Invalid command, try again";
			}
		}
	}

}



