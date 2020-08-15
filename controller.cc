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

//	std::cout << argc << std::endl;

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

	int numPlayers = players.size();
	std::shared_ptr<Player> curr = board->getCurrPlayer();

	while (numPlayers > 1 && !std::cin.eof()) {
		

		curr = board->getCurrPlayer();

		//"For testing purposes"

		if (curr->getInTims()) {
			//"Make choices"
	
			std::cout << "You are in jail, you can either roll for doubles, pay the bail or use a RollUp the Rim Cup" << std::endl;

			std::cout << "You have: " << curr->getTimsCards() << " RollUp the Rim Cups" << std::endl;
			std::cout << "You have: $" << curr->getMoney() << std::endl;
	
			std::cout << "Enter D to roll doubles, B to pay bail, T to use Tim's Cup" << std::endl;

			char c = 0;
			bool done = false;
			int lastRoll = -1;
			while (done || (c != 'D' && c != 'B' && c != 'T')) {
				std::cin >> c;
	
				if (c == 'D') {
					//"Do something with doubles"
					
					
					std::cout << "Type roll, to roll the dice" << std::endl;
					int roll = 0;

					std::string d;
					std::cin >> d;

					if (testingMode) {
						int num1;
						int num2;

						std::cin >> num1;
						std::cin >> num2;

						if (num1 == num2) {
							board->incRollDouble();	
						} else {
							board->setRollDouble(0);
						}
						roll = num1 + num2;	


					} else {
						roll = board->roll();
					}

					if (curr->getTurnsInTims() == 2 && board->getRollDouble() == 0) {
						std::cout << "This was your last turn in jail, and you failed to get doubles, you must pay bail, or use a RollUp the Rim Cup" << std::endl;
						c = 0;
						lastRoll = roll;
						continue;
					}

					if (board->getRollDouble() > 0) {
						board->setRollDouble(0);
						std::cerr << "Moving" << std::endl;
						board->move(roll);

						display.display();

						done = true;
						break;
					} else {
						std::cout << "You did not get doubles, are still in jail" << std::endl;
						curr->setTurnsInTims(curr->getTurnsInTims() + 1);

						int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
						board->setCurrPlayer(nextPlayer);
						//currPlayer = (currPlayer + 1) % playerNum;		
						
						break;
					}
				} else if (c == 'B'){
					// "Pay bail"
					if (curr->getMoney() < 50) {
						std::cout << "Not enough money to pay bail, try T for Tims Cup or D for roll for Doubles" << std::endl;
						c = 0;
					} else if (lastRoll != -1) {
						curr->removeMoney(50);
						std::cout << "You are being moved according to you last doubles attempt" << std::endl;
						done = true;
						board->move(lastRoll);
						display.display();
						break;
					} else {
						curr->removeMoney(50);
						std::cout << "You are now free, continue your turn as desired" << std::endl;
						done = true;
						break;
					}
				} else if (c == 'T') {
					//"Use Card"
					
					if (curr->getTimsCards() <= 0) {
						std::cout << "You do not have a RollUp the Rim Cup, try again" << std::endl;
						c = 0;
					} else {
						curr->setTimsCups(curr->getTimsCard() - 1);
						std::cout << "You are now free, continue you turn as desired" << std::endl;
						done = true;
						break;
					}
			
				} else {
					std::cout << "Please select one of D, B or T" << std::endl;
					c = 0;
	
				}		
			}

		//	board->move();
		}
	


		std::string cmd;
		std::cin >> cmd;

		std::cout << cmd.length() << std::endl;

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
					if (d1 == d2) {
						board->incRollDouble();
						
					} else {
						board->setRollDouble(0);
					}
					board->move(d1 + d2);
				} catch (BankruptException b) {
					locked = true;
					creditor = b.getCreditor();
					amountOwed = b.getOwed();

					std::cout << "You are in insolvency, you may only trade, mortgage, or sell improvements" << std::endl; 
					std::cout << "You have: $" << curr->getMoney() << " and owe: $" << amountOwed << std::endl;

				}
				
				//int nextPlayer = (board->getCurrPlayerInt() + 1) % numPlayers;
				//board->setCurrPlayer(nextPlayer);
				

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
			curr->addMoney(p->getValue() * 0.6);
			
			
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

					int n = curr->getProperties().size();
					
					for (int i = n - 1; i >= 0; i--) {
						creditor->addProperty(curr->getProperties()[i]);
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
	
				std::cout << board->getCurrPlayerInt() << std::endl;	
				int nextPlayer = board->getCurrPlayerInt();
				
				if (nextPlayer >= numPlayers) {
					nextPlayer = 0;
				}

				//std::cout << numPlayers << std::endl;
				board->setCurrPlayer(nextPlayer);
				locked = false;
				numPlayers--;

				continue;
			}

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

	std::cout << curr->getPlayerName() << " has won the game!" << std::endl;

	delete board;
}



