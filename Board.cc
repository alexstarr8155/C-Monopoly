#include <map>
#include <string>
#include "Board.h"

Board::Board(int playerNum) {

    std::vector<char> playerChar = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
    std::vector<std::string> playerStr = {"Goose", "GRT Bus", "Tim Hortons Doughnut", "Professor", "Student", "Money", "Laptop", "Pink Tie"};

    for (int i = 0; i < playerNum; i++) {
        std::shared_ptr<Player> player = std::make_shared<Player>(playerStr[i], playerChar[i], 1500);
        players[playerChar[i]] = player;
    }

    std::shared_ptr<Cell> property0 = std::make_shared<Cell>("COLLECT OSAP");
    board[0] = property0;

    std::shared_ptr<Property> property1 = std::make_shared<Property>("AL", 40, 2);
    board[1] = property1;

    std::shared_ptr<Cell> property2 = std::make_shared<Cell>("SLC");
    board[2] = property2;

    std::shared_ptr<Property> property3 = std::make_shared<Property>("ML", 60, 4);
    board[3] = property3;

    std::shared_ptr<Cell> property4 = std::make_shared<Cell>("TUITION");
    board[4] = property4;

    std::shared_ptr<Property> property5 = std::make_shared<Property>("MKV", 200, 25);
    board[5] = property5;

    std::shared_ptr<Property> property6 = std::make_shared<Property>("ECH", 100, 6);
    board[6] = property6;

    std::shared_ptr<Cell> property7 = std::make_shared<Cell>("NEEDLES HALL");
    board[7] = property7;

    std::shared_ptr<Property> property8 = std::make_shared<Property>("PAS", 100, 6);
    board[8] = property8;

    std::shared_ptr<Property> property9 = std::make_shared<Property>("HH", 120, 8);
    board[9] = property9;

    std::shared_ptr<Cell> property10 = std::make_shared<Cell>("DC TIMS LINE");
    board[10] = property10;

    std::shared_ptr<Property> property11 = std::make_shared<Property>("RCH", 140, 10);
    board[11] = property11;

    std::shared_ptr<Property> property12 = std::make_shared<Property>("PAC", 150, 0);
    board[12] = property12;

    std::shared_ptr<Property> property13 = std::make_shared<Property>("DWE", 140, 10);
    board[13] = property13;

    std::shared_ptr<Property> property14 = std::make_shared<Property>("CPH", 160, 12);
    board[14] = property14;

    std::shared_ptr<Property> property15 = std::make_shared<Property>("UWP", 200, 25);
    board[15] = property15;

    std::shared_ptr<Property> property16 = std::make_shared<Property>("LHI", 180, 14);
    board[16] = property16;

    std::shared_ptr<Cell> property17 = std::make_shared<Cell>("SLC");
    board[17] = property17;

    std::shared_ptr<Property> property18 = std::make_shared<Property>("BMH", 180, 14);
    board[18] = property18;

    std::shared_ptr<Property> property19 = std::make_shared<Property>("OPT", 200, 16);
    board[19] = property19;

    std::shared_ptr<Cell> property20 = std::make_shared<Cell>("GOOSE NESTING");
    board[20] = property20;

    std::shared_ptr<Property> property21 = std::make_shared<Property>("EV1", 220, 18);
    board[21] = property21;

    std::shared_ptr<Cell> property22 = std::make_shared<Cell>("NEEDLES HALL");
    board[22] = property22;

    std::shared_ptr<Property> property23 = std::make_shared<Property>("EV2", 220, 18);
    board[23] = property23;

    std::shared_ptr<Property> property24 = std::make_shared<Property>("EV3", 240, 20);
    board[24] = property24;

    std::shared_ptr<Property> property25 = std::make_shared<Property>("V1", 200, 25);
    board[25] = property25;

    std::shared_ptr<Property> property26 = std::make_shared<Property>("PHYS", 260, 22);
    board[26] = property26;

    std::shared_ptr<Property> property27 = std::make_shared<Property>("B1", 260, 22);
    board[27] = property27;

    std::shared_ptr<Property> property28 = std::make_shared<Property>("CIF", 150, 0);
    board[28] = property28;

    std::shared_ptr<Property> property29 = std::make_shared<Property>("B2", 280, 24);
    board[29] = property29;

    std::shared_ptr<Cell> property30 = std::make_shared<Cell>("GO TO TIMS");
    board[30] = property30;

    std::shared_ptr<Property> property31 = std::make_shared<Property>("EIT", 300, 26);
    board[31] = property31;

    std::shared_ptr<Property> property32 = std::make_shared<Property>("ESC", 300, 26);
    board[32] = property32;

    std::shared_ptr<Cell> property33 = std::make_shared<Cell>("SLC");
    board[33] = property33;

    std::shared_ptr<Property> property34 = std::make_shared<Property>("C2", 320, 28);
    board[34] = property34;

    std::shared_ptr<Property> property35 = std::make_shared<Property>("REV", 200, 25);
    board[35] = property35;

    std::shared_ptr<Cell> property36 = std::make_shared<Cell>("NEEDLES HALL");
    board[36] = property36;

    std::shared_ptr<Property> property37 = std::make_shared<Property>("MC", 350, 35);
    board[37] = property37;

    std::shared_ptr<Cell> property38 = std::make_shared<Cell>("COOP FEE");
    board[38] = property38;

    std::shared_ptr<Property> property39 = std::make_shared<Property>("DC", 400, 50);
    board[39] = property39;
}

Board::~Board() {}
