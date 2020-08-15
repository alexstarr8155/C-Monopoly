#include <iostream>
#include <map>
#include <string>
#include "BoardDisplay.h"

/* below are some initial size constants that we can modify to change the height and width of the game */
int width = 8;
int topWidth = ((width + 1) * 11) + 1;
int middleSpace = ((width + 1) * 8) + width;
int logoWidth = 46;
int logoSpace = ((middleSpace - logoWidth) / 2) - 1;

BoardDisplay::BoardDisplay(Board & game) : game{game} {}

// will print 'c' 'n' amount of times
void printMany(char c, int n) {
	std::cout << std::string(n, c);
}

/* the below prints are used to help display board */
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

/* the below code is here help showcases the different features of Cell (improvements, improvableProperty vs Non-improvableProperty) */
void printData(std::string name, int nameSize, int houses, std::map<char, bool> players, int line) {
    int extraSpace = 0;

    if (line == 0 && houses != -2) {
	extraSpace = width - houses;
        std::cout << "|";
	    printMany('I', houses);
        printMany(' ', extraSpace);
    }
    else if (line == 0) {
        std::size_t found = name.find(" ", 5);
        name = name.substr(0, found);
        extraSpace = width - name.length();
        std::cout << "|" << name;
        printMany(' ', extraSpace);
    }
    else if (line == 1 && houses != -2) {
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
    else if (line == 2 && houses != -2) {
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

/* the below prints help display the logo in the middle of the board */
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

void BoardDisplay::display() {
	printTopLine();
    
    /* the below prints the first row of display */
    for (int i = 0; i < 4; ++i) {
        for (int j = 20; j <= 30; ++j) {
            std::string name = (game.board[j])->getName();
            int nameSize = name.length();
            int houses = (game.board[j])->getNumImprov();
            std::map<char, bool> players = (game.board[j])->who_on_cell();

                    printData(name, nameSize, houses, players, i);
        }
        std::cout << "|\n";
    } 
    printEndTopBottom();
    
    /* the below prints all the Cells until the beginning of logo */
    for (int i = 0; i < 3; ++i) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        for (int j = 0; j < 4; ++j) {
            index = (-1 * i) + 19;
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getNumImprov();
            players = (game.board[index])->who_on_cell();

            printData(name, nameSize, houses, players, j);
            std::cout << "|";
            printMany(' ', middleSpace);

            index = 50 - ((-1 * i) + 19);
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getNumImprov();
            players = (game.board[index])->who_on_cell();

            printData(name, nameSize, houses, players, j);
            std::cout << "|\n";
        }
        printEndMiddle();
    }
    
    /* the below prints the Cells that are in the logo, as well as prints the logo */
    for (int j = 0; j < 4; ++j) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        index = 16;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

        printData(name, nameSize, houses, players, j);
        std::cout << "|";

        if (j == 3) {
                printLogo1();
        }
        else {
                printMany(' ', middleSpace);
        }

        index = 34;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

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

        index = 15;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

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

        index = 35;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

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

        index = 14;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

        printData(name, nameSize, houses, players, j);
        std::cout << "|";

        if (j == 0) {
                printLogo8();
        }
        else {
                printMany(' ', middleSpace);
        }

        index = 36;
        name = (game.board[index])->getName();
        nameSize = name.length();
        houses = (game.board[index])->getNumImprov();
        players = (game.board[index])->who_on_cell();

        printData(name, nameSize, houses, players, j);
        std::cout << "|\n";
    }
    printEndMiddle();
    
    /* the below prints the all the Cells after the logo */
    for (int i = 0; i < 3; ++i) {
        int index = 0;
        std::string name = "";
        int nameSize = 0;
        int houses = 0;
        std::map<char, bool> players = {};

        for (int j = 0; j < 4; ++j) {
            index = (-1 * i) + 13; 
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getNumImprov();
            players = (game.board[index])->who_on_cell();

            printData(name, nameSize, houses, players, j);
            std::cout << "|";
            printMany(' ', middleSpace);

            index = 50 - ((-1 * i) + 13);
            name = (game.board[index])->getName();
            nameSize = name.length();
            houses = (game.board[index])->getNumImprov();
            players = (game.board[index])->who_on_cell();

            printData(name, nameSize, houses, players, j);
            std::cout << "|\n";
        }
        if (i == 2) {
            printEndEndMiddle();
        }
        else {
            printEndMiddle();
        }
    }
    
    /* the below prints out the last row of board */
    for (int i = 0; i < 4; ++i) {
        for (int j = 10; j >= 0; --j) {
            std::string name = (game.board[j])->getName();
            int nameSize = name.length();
            int houses = (game.board[j])->getNumImprov();
            std::map<char, bool> players = (game.board[j])->who_on_cell();

            printData(name, nameSize, houses, players, i);
        }
        std::cout << "|\n";
    }    
    printEndTopBottom();
}

