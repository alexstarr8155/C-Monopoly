#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Board.h"
#include "Player.h"
#include "BoardDisplay.h"

void setupPlayers(std::map<const std::string, std::shared_ptr<Player>> & players) {
		std::cout << "Enter the Number of Players: ";
		int numPlayers = 0;
		std::cin >> numPlayers;
		//std::cout << std::endl;

		std::vector<char> takenPieces;
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

			const std::string name = temp;
		
			char piece;
			std::cin >> piece;

			while (find(allowedPieces.begin(), allowedPieces.end(), piece) == allowedPieces.end() || 
					(find(takenPieces.begin(), takenPieces.end(), piece) != takenPieces.end() && !std::cin.eof())) {

				if (std::cin.eof()) {
					break;
				}
				std::cout << "Invalid or Duplicate piece, choose one of: ";

				for (int i = 0; i < allowedPieces.size(); i++) {
					if (find(takenPieces.begin(), takenPieces.end(), allowedPieces[i]) == takenPieces.end()) {
						std::cout << allowedPieces[i] << " ";
					}
				}

				std::cin >> piece;
			}

			takenPieces.push_back(piece);

			if (std::cin.eof()) {
				break;
			}

			auto p = std::make_shared<Player> (name, piece, 1500);
			players.insert(players.begin(), std::pair<std::string, std::shared_ptr<Player>>(name, p));
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
	BoardDisplay display;

	display.display(board);

	while (players.size() > 1 && !std::cin.eof()) {
		
		std::string cmd;
		std::cin >> cmd;

		if (cmd.compare("roll") == 0) {
		
			board.move();
			display.display(board);

		} else if (cmd.compare("next") == 0) {
			// "Assign turn to next player if cannot roll"
			// "I believe this is a call to board"
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
				// "Trade Property with in"
			} else {
				// "Trade Prop with Prop"
			}

		} else if (cmd.compare("improve") == 0) {
			std::string prop;
			std::cin >> prop;

			std::string buy;
			std::cin >> buy;

			bool b = buy.compare("buy") == 0;

			if (b) {
			
			} else {
			
			}
		} else if (cmd.compare("mortgage") == 0) {
			std::string prop;
			std::cin >> prop;

			//"Mortgage Property
		} else if (cmd.compare("unmortgage") == 0) {
			std::string prop;
			std::cin >> prop;

			//"unmortgage property
		} else if (cmd.compare("bankrupt") == 0) {
			//"Declare bankruptcy"
		} else if (cmd.compare("assets") == 0) {
			// "Display the assets of the current player"
		} else if (cmd.compare("all") == 0) {
			//"Display the assets of all players"
		} else if (cmd.compare("save") == 0) {
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



