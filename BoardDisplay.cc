#include <iostream>
#include <map>
#include <string>
#include "BoardDisplay.h"

int width = 8;
int topWidth = ((width + 1) * 11) + 1;
int middleSpace = ((width + 1) * 8) + width;
int logoWidth = 46;
int logoSpace = ((middleSpace - logoWidth) / 2) - 1;

BoardDisplay::BoardDisplay() {}
BoardDisplay::~BoardDisplay() {}

void printMany(char c, int n) {
	std::cout << std::string(n, c);
}

void printEmptyTopBottom() {
    for (int i = 0; i < 11; ++i) {
            std::cout << "|";
	printMany(' ', width);
    }
    std::cout << "|\n";
}

void printEmptyMiddle() {
	std::cout << "|";
    printMany(' ', width);
	std::cout << "|";

	printMany(' ', middleSpace);

	std::cout << "|";
    printMany(' ', width);
    std::cout << "|\n";
}

void printEndTopBottom() {
    for (int i = 0; i < 11; ++i) {
        std::cout << "|";
        printMany('_', width);
    }
	std::cout << "|\n";
}

void printEndMiddle() {
	std::cout << "|";
    printMany('_', width);
    std::cout << "|";

	printMany(' ', middleSpace);

	std::cout << "|";
    printMany('_', width);
    std::cout << "|\n";
}

void printEndEndMiddle() {
    std::cout << "|";
    printMany('_', width);
    std::cout << "|";

    printMany('_', middleSpace);

    std::cout << "|";
    printMany('_', width);
    std::cout << "|\n";
}

void printTopLine() {
	printMany('_', topWidth);
    std::cout << "\n";
}

void printData(std::string name, int nameSize, int houses, std::map<char, bool> players, int line) {
    int extraSpace = 0;

    if (line == 0 && houses != -1) {
        std::cout << "|";
        printMany(' ', width);
    }
    else if (line == 0) {
        std::size_t found = name.find(" ", 5);
        name = name.substr(0, found);
        extraSpace = width - name.length();
        std::cout << "|" << name;
        printMany(' ', extraSpace);
    }
    else if (line == 1 && houses != -1) {
        std::cout << "|";
        printMany('-', width);
    }
    else if (line == 1 && nameSize > width) {
        std::size_t found = name.find(" ", 5);
        name = name.substr(found+1);
        extraSpace = width - name.length();
        std::cout << "|" << name;
        printMany(' ', extraSpace);
    }
    else if (line == 2 && houses != -1) {
        extraSpace = width - nameSize;
        std::cout << "|" << name;
        printMany(' ', extraSpace);
    }
	else if (line == 3) {
		std::cout << "|";
		for (auto &player : players) {
        	if (player.second) {
                	std::cout << player.first;
        	}
        	else {
                	std::cout << " ";
       		}
        }
	}		
    else {
        std::cout << "|";
        printMany(' ', width);
    }
}

void printLogo1() {
	printMany(' ', logoSpace + 1);
	printMany('_', logoWidth);
	printMany(' ', logoSpace + 1);
}

void printLogo2() {
	std::cout << "|";
    printMany('_', width);
    std::cout << "|";

	printMany(' ', logoSpace);
	std::cout << "|";
	printMany(' ', logoWidth);
	std::cout << "|";
	printMany(' ', logoSpace);

	std::cout << "|";
    printMany('_', width);
    std::cout << "|\n";
}

void printLogo3() {
	printMany(' ', logoSpace);
    std::cout << "|";
	std::cout << " #   #  ##  #####  ###  ###   ###  #    #   # ";
	std::cout << "|";
	printMany(' ', logoSpace);
}

void printLogo4() {
    printMany(' ', logoSpace);
    std::cout << "|";
    std::cout << " #   # #  #   #   #   # #  # #   # #    #   # ";
    std::cout << "|";
    printMany(' ', logoSpace);
}

void printLogo5() {
    printMany(' ', logoSpace);
    std::cout << "|";
    std::cout << " # # # ####   #   #   # ###  #   # #     # #  ";
    std::cout << "|";
    printMany(' ', logoSpace);
}

void printLogo6() {
    printMany(' ', logoSpace);
    std::cout << "|";
    std::cout << " # # # #  #   #   #   # #    #   # #      #   ";
    std::cout << "|";
    printMany(' ', logoSpace);
}

void printLogo7() {
	std::cout << "|";
    printMany('_', width);
    std::cout << "|";

    printMany(' ', logoSpace);
    std::cout << "|";
    std::cout << " ##### #  #   #    ###  #     ###  ####   #   ";
    std::cout << "|";
    printMany(' ', logoSpace);

    std::cout << "|";
    printMany('_', width);
    std::cout << "|\n";
}

void printLogo8() {
	printMany(' ', logoSpace);
    std::cout << "|";
	printMany('_', logoWidth);
    std::cout << "|";
    printMany(' ', logoSpace);
}

void BoardDisplay::display(Board game) {
	
	printTopLine();

	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j <= 11; ++j) {
			std::string name = (game.board[j])->getName();
			int nameSize = name.length();
			int houses = (game.board[j])->getHouses();
			std::map<char, bool> players = (game.board[j])->getPlayers();

            printData(name, nameSize, houses, players, i);
		}
		std::cout << "|\n";
	} 
	printEndTopBottom();
	
	for (int i = 0; i < 3; ++i) {
		int index = 0;
		std::string name = "";
		int nameSize = 0;
		int houses = 0;
		std::map<char, bool> players = {};

		for (int j = 0; j < 4; ++j) {
			index = 11 + (i*2) + 1;
			name = (game.board[index])->getName();
			nameSize = name.length();
			houses = (game.board[index])->getHouses();
			players = (game.board[index])->getPlayers();

			printData(name, nameSize, houses, players, j);
			std::cout << "|";
			printMany(' ', middleSpace);

			index = 11 + (i*2) + 2;
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getHouses();
			players = (game.board[index])->getPlayers();

            printData(name, nameSize, houses, players, j);
            std::cout << "|\n";
		}
		printEndMiddle();
	}
	
	for (int j = 0; j < 4; ++j) {
		int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        index = 18;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|";

        if (j == 3) {
            printLogo1();
        }
        else {
            printMany(' ', middleSpace);
        }

        index = 19;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|\n";
    }
	printLogo2();

	for (int j = 0; j < 4; ++j) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        index = 20;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|";
                        
		if (j == 0) {
			printLogo3();
		}
		else if (j == 1) {
			printLogo4();
		}
		else if (j == 2) {
			printLogo5();
		}
        else {
            printLogo6();
        }

        index = 21;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|\n";
    }
	printLogo7();

	for (int j = 0; j < 4; ++j) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        index = 22;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|";

        if (j == 0) {
            printLogo8();
        }
        else {
            printMany(' ', middleSpace);
        }

        index = 23;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getHouses();
        players = (game.board[index])->getPlayers();

        printData(name, nameSize, houses, players, j);
        std::cout << "|\n";
    }
	printEndMiddle();

    for (int i = 0; i < 3; ++i) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        for (int j = 0; j < 4; ++j) {
            index = 23 + (i*2) + 1;
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getHouses();
            players = (game.board[index])->getPlayers();

            printData(name, nameSize, houses, players, j);
            std::cout << "|";
            printMany(' ', middleSpace);

            index = 23 + (i*2) + 2;
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getHouses();
            players = (game.board[index])->getPlayers();

            printData(name, nameSize, houses, players, j);
            std::cout << "|\n";
        }
        if (i == 2) {
            printEndEndMiddle();
        } else {
            printEndMiddle();
        }
    }
	
    for (int i = 0; i < 4; ++i) {
        for (int j = 30; j <= 40; ++j) {
            std::string name = (game.board[j])->getName();
            int nameSize = name.length();
            int houses = (game.board[j])->getHouses();
            std::map<char, bool> players = (game.board[j])->getPlayers();

            printData(name, nameSize, houses, players, i);
        }
        std::cout << "|\n";
    } 
    printEndTopBottom();
}

