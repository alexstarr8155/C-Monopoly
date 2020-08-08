#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "BoardDisplay.h"

BoardDisplay::BoardDisplay() {}
BoardDisplay::~BoardDisplay() {}

void printMany(char c, int n) {
	std::cout << std::string(n, c);
}

void printEmptyTopBottom() {
	for (int i = 0; i < 11; ++i) {
                std::cout << "|";
                printMany(' ', 14);
        }
	std::cout << "|\n";
}

void printEmptyMiddle() {
	std::cout << "|";
        printMany(' ', 14);
	std::cout << "|";

	printMany(' ', 134);

	std::cout << "|";
        printMany(' ', 14);
        std::cout << "|\n";
}

void printEndTopBottom() {
	for (int i = 0; i < 11; ++i) {
                std::cout << "|";
                printMany('_', 14);
        }
	std::cout << "|\n";
}

void printEndMiddle() {
	std::cout << "|";
        printMany('_', 14);
        std::cout << "|";

	printMany(' ', 134);

	std::cout << "|";
        printMany('_', 14);
        std::cout << "|\n";
}

void printEndEndMiddle() {
        std::cout << "|";
        printMany('_', 14);
        std::cout << "|";

        printMany('_', 134);

        std::cout << "|";
        printMany('_', 14);
        std::cout << "|\n";
}

void printTopLine() {
	printMany('_', 166);
        std::cout << "\n";
}

void BoardDisplay::display(Board game) {
	
	printTopLine();	
	printEmptyTopBottom();
	for (int i = 1; i <= 11; ++i) {
		std::string name = (game.board[i])->getName();
		int extraSpace = 14 - name.length();
		std::cout << "|" << name;
		printMany(' ', extraSpace);
	}
	std::cout << "|\n";
	for (int i = 0; i < 5; ++i) {
		printEmptyTopBottom();
	}
	printEndTopBottom();
	
	for (int i = 0; i < 9; ++i) {
		int index = 0;
		std::string name = "";
		int extraSpace = 0;

		printEmptyMiddle();

		index = 11 + (i*2) + 1;
		name = (game.board[index])->getName();
		extraSpace = 14 - name.length();
		std::cout << "|" << name;
		printMany(' ', extraSpace);
		std::cout << "|";

        	printMany(' ', 134);

		index = 11 + (i*2) + 2;
                name = (game.board[index])->getName();
                extraSpace = 14 - name.length();
                std::cout << "|" << name;
                printMany(' ', extraSpace);
                std::cout << "|\n";

		for (int i = 0; i < 5; ++i) {
			printEmptyMiddle();
		}
		if (i == 8) {
			printEndEndMiddle();
		} else {
			printEndMiddle();
		}
	}

	printEmptyTopBottom();
        for (int i = 30; i <= 40; ++i) {
                std::string name = (game.board[i])->getName();
                int extraSpace = 14 - name.length();
                std::cout << "|" << name;
                printMany(' ', extraSpace);
        }
        std::cout << "|\n";
        for (int i = 0; i < 5; ++i) {
                printEmptyTopBottom();
        }
        printEndTopBottom();
}
