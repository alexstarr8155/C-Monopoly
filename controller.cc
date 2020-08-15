#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Board.h"
#include "Player.h"
#include "Property.h"
#include "BoardDisplay.h"
#include "BankruptException.h"

Property* getProperty(std::string, std::shared_ptr<Player>);

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
	std::shared_ptr<Player> currPlayer = board.getCurrPlayer();
	return getProperty(propName, currPlayer);
}

Property* getProperty(std::string propName, std::shared_ptr<Player> currPlayer) {
	//auto currPlayer = board.getCurrPlayer();
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
		//std::cout << i << ", " << argv[i] << std::endl;
		args.push_back(temp);
	}
	
//	Board board;
	std::map<const std::string, std::shared_ptr<Player>> players;
	bool testingMode = false;
	if (argc > 1 && args[1].compare("-testing") == 0) {
		testingMode = true;
	}
	if ((argc > 2 && args[1].compare("-testing") == 0) || (argc > 1 && args[1].compare("-testing") != 0)) {
		
		std::string filename;
		if (argc > 2) {
			filename = args[2];
		} else {
			filename = args[1];
		}

		board = new Board(filename);
		players = board->getPlayers();

	} else {
		// "Starting game input needed"
		setupPlayers(players);
		board = new Board(players, players.size());
	}

	
	BoardDisplay display(*board);
	display.display();

	bool locked = false;
	bool canDeclare = false;

	std::shared_ptr<Player> creditor = nullptr;
	int amountOwed = 0;

	while (players.size() > 1 && !std::cin.eof()) {
		
		std::string cmd;
		std::cin >> cmd;

		std::shared_ptr<Player> curr = board->getCurrPlayer();

		//"For testing purposes"
		if (cmd.compare("r") == 0 && !locked) {
			int n;
			std::cin >> n;

			try {
				board->moveBy(n);
			} catch (BankruptException b) {
				locked = true;
				creditor = b.getCreditor();
				amountOwed = b.getOwed();
				std::cout << "You are in insolvency, you may only trade, mortgage, or sell improvements" << std::endl; 
				std::cout << "You have: $" << curr->getMoney() << " and owe: $" << amountOwed << std::endl;

			}

			display.display();
		} else if (cmd.compare("roll") == 0 && !locked) {
			
			if (testingMode) {
				int d1, d2;
				std::cin >> d1;
				std::cin >> d2;

				try {
					board->moveBy(d1 + d2);
				} catch (BankruptException b) {
					locked = true;
					creditor = b.getCreditor();
					amountOwed = b.getOwed();

					std::cout << "You are in insolvency, you may only trade, mortgage, or sell improvements" << std::endl; 
					std::cout << "You have: $" << curr->getMoney() << " and owe: $" << amountOwed << std::endl;

				}
				
				int numPlayers = players.size();
				int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
				board->setCurrPlayer(nextPlayer);
				

			} else {
				try {
					board->move();
				} catch (BankruptException b) {
					locked = true;
					creditor = b.getCreditor();
					amountOwed = b.getOwed();
					std::cout << "You are in insolvency, you may only trade, mortgage, or sell improvements" << std::endl; 
				std::cout << "You have: $" << curr->getMoney() << " and owe: $" << amountOwed << std::endl;

				}
			}

			display.display();

		} else if (cmd.compare("next") == 0 && !locked) {
			
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
			Property* pReceive = getProperty(receive, other);

			if (g != -1 && r != -1) {
				// "Trade with int version"
				//std::cout << other->getPlayerName() << std::endl;
				
				if (r-g > other->getMoney()) {
					std::cout << "Not enough money for this trade" << std::endl;
					break;
				}

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
			else if (buy == "buy" && !locked) {
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
			
			//std::cout << ", " << curr.get() << std::endl;	

			if (p == nullptr) {
				std::cout << "You do no own that property, and cannot mortgage it" << std::endl;
				break;	
			}
			
			try {
				p->mortgage();
			} catch (int num) {
				std::cout << "There are " << num << " improvements on this property, sell them before mortgaging" << std::endl;
			} catch (...) {
				std::cout << prop << " is already mortgaged" << std::endl;
				continue;
			}
			curr->addMoney(p->getValue()/2);
			
			
		} 
		else if (cmd.compare("unmortgage") == 0 && !locked) {
			std::string prop;
			std::cin >> prop;
			Property * p = getProperty(prop, *board);
			
			if (p == nullptr) {
				std::cout << "You do not own that property, so you can't unmortgage it" << std::endl;
				break;
			}

			try {
				p->unmortgage();
			} catch (...) {
				std::cout << prop << " is currently unmortgaged, you cannot unmortgage it" << std::endl;
			}
			curr->removeMoney(p->getValue()/2);
			//"unmortgage property
		} 
		else if (cmd.compare("bankrupt") == 0) {
			
			if (!canDeclare) {
				std::cout << "You are not allowed to declare bankruptcy as of now" << std::endl;
			} else {
			
				if (creditor == nullptr) {
					//"Give all back to the Bank"
					for (auto it = curr->getProperties().begin(); it != curr->getProperties().end(); ++it) {
						(*it)->setOwner(nullptr);
					}
				} else {
					// "Owed to another player"

					std::cout << curr->getProperties().size() << std::endl;

					for (auto it = curr->getProperties().begin(); it != curr->getProperties().end(); ++it) {
						curr->trade(creditor, *it, 0);
					}
					curr->pay(creditor, curr->getMoney());
				}

				//std::cout << "A" << std::endl;
				board->removePlayer(curr);
				//std::cout << "B" << std::endl;

				for (auto it = players.begin(); it != players.end(); ++it) {
					if (it->second->getPlayerName().compare(curr->getPlayerName()) == 0) {
						players.erase(it);
						break;
					}
				}
				canDeclare = false;

			}
			
			int numPlayers = players.size();
			//std::cout << numPlayers << std::endl;
			int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
			board->setCurrPlayer(nextPlayer);

			locked = false;

			continue;

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
			break;
		} else {
			if (!std::cin.eof()) {
				std::cout << "Invalid command, try again: ";
			}
		}

		if (curr->getMoney() >= amountOwed && locked) {
			std::cout << "You have raised enough money" << std::endl;

			if (creditor != nullptr) {
				curr->pay(creditor, amountOwed);
			}

			canDeclare = false;
			locked = false;
			amountOwed = 0;
		
			int numPlayers = players.size();
			int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
			board->setCurrPlayer(nextPlayer);


		} else if (curr->allPropertiesAreMortgaged() && curr->getMoney() < amountOwed) {
			canDeclare = true;
			std::cout << "You have mortgaged all your properties, unless you can raise enough money through trading, you must declare bankruptcy" << std::endl;
		} else if (locked) {
			std::cout << "You are in insolvency, you may only trade, mortgage, or sell improvements" << std::endl; 
			std::cout << "You have: $" << curr->getMoney() << " and owe: $" << amountOwed << std::endl;
		}

	}
	delete board;
}



