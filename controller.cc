#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Board.h"
#include "Player.h"

void setupPlayers(std::map<const std::string, Player> & players) {
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
					find(takenPieces.begin(), takenPieces.end(), piece) != takenPieces.end() && !std::cin.eof()) {

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

			Player p(name, piece, 1500);
			players.insert(players.begin(), std::pair<std::string, Player>(name, p));
		}

}

int main(int argc, char *argv[]) {
	
//	Board board;

	if (argc > 1) {
		// "Load file given"
	} else {
		// "Starting game input needed"
		
		std::map<const std::string, Player> players;
		setupPlayers(players);
	}

	while (players.size() > 1 && !std::cin.eof()) {
		
		std::string cmd;
		std::cin >> cmd;

		if (cmd.compare("roll") == 0) {
			//"Roll with board"
		} else if (cmd.compare("next") == 0) {
			// "Assign turn to next player if cannot roll"
			// "I believe this is a call to board"
		} else if (cmd.comapare("trade") == 0) {
			std::string otherPlayer;
			std::cin >> otherPlayer;

			std::string give;
			std::cin >> give;
			int g = -1;

			try {
				g = std::stoi(give)
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

		}

		// "Other command incomplete, will do later"

	}

}



