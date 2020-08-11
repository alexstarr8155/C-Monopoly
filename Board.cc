#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Property.h"
#include "Improvable.h"
#include "Gym.h"
#include "Residence.h"
#include "NeedlesHall.h"
#include "SLC.h"
#include "GoToTims.h"
#include "Tims.h"
#include "CoopFee.h"
#include "GooseNesting.h"
#include "Tuition.h"
#include "CollectOSAP.h"

Board::Board(int playerNum) {

    std::vector<char> playerChar = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
    std::vector<std::string> playerStr = {"Goose", "GRT Bus", "Tim Hortons Doughnut", "Professor", "Student", "Money", "Laptop", "Pink Tie"};

    for (int i = 0; i < playerNum; i++) {
        std::shared_ptr<Player> player = std::make_shared<Player>(playerStr[i], playerChar[i], 1500);
        players[playerChar[i]] = player;
    }

    std::vector<std::string> set = {};
    std::vector<int> tuitionFee = {};

    std::shared_ptr<Cell> property0 = std::make_shared<CollectOSAP>();
    board[0] = property0;

    set = {"AL", "ML"};
    tuitionFee = {2, 10, 30, 90, 160, 250};
    std::shared_ptr<Cell> property1 = std::make_shared<ImprovableProperty>("AL", 40, 50, set, tuitionFee);
    board[1] = property1;

    std::shared_ptr<Cell> property2 = std::make_shared<SLC>();
    board[2] = property2;

    set = {"AL", "ML"};
    tuitionFee = {4, 20, 60, 180, 320, 450};
    std::shared_ptr<Cell> property3 = std::make_shared<ImprovableProperty>("ML", 60, 50, set, tuitionFee);
    board[3] = property3;

    std::shared_ptr<Cell> property4 = std::make_shared<Tuition>();
    board[4] = property4;

    set = {"MKV", "UWP", "V1", "REV"};
    std::shared_ptr<Cell> property5 = std::make_shared<Residences>("MKV", set);
    board[5] = property5;

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {6, 30, 90, 270, 400, 550};
    std::shared_ptr<Cell> property6 = std::make_shared<ImprovableProperty>("ECH", 100, 50, set, tuitionFee);
    board[6] = property6;

    std::shared_ptr<Cell> property7 = std::make_shared<NeedlesHall>();
    board[7] = property7;

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {6, 30, 90, 270, 400, 550};
    std::shared_ptr<Cell> property8 = std::make_shared<ImprovableProperty>("PAS", 100, 50, set, tuitionFee);
    board[8] = property8;

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {8, 40, 100, 300, 450, 600};
    std::shared_ptr<Cell> property9 = std::make_shared<ImprovableProperty>("HH", 120, 50, set, tuitionFee);
    board[9] = property9;

    std::shared_ptr<Cell> property10 = std::make_shared<Tims>();
    board[10] = property10;

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {10, 50, 150, 450, 625, 750};
    std::shared_ptr<Cell> property11 = std::make_shared<ImprovableProperty>("RCH", 140, 100, set, tuitionFee);
    board[11] = property11;

    set = {"PAC", "CIF"};
    std::shared_ptr<Cell> property12 = std::make_shared<Gym>("PAC", set);
    board[12] = property12;

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {10, 50, 150, 450, 625, 750};
    std::shared_ptr<Cell> property13 = std::make_shared<ImprovableProperty>("DWE", 140, 100, set, tuitionFee);
    board[13] = property13;

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {12, 60, 180, 500, 700, 900};
    std::shared_ptr<Cell> property14 = std::make_shared<ImprovableProperty>("CPH", 160, 100, set, tuitionFee);
    board[14] = property14;

    set = {"MKV", "UWP", "V1", "REV"};
    std::shared_ptr<Cell> property15 = std::make_shared<Residences>("UWP", set);
    board[15] = property15;

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {14, 70, 200, 550, 750, 950};
    std::shared_ptr<Cell> property16 = std::make_shared<ImprovableProperty>("LHI", 180, 100, set, tuitionFee);
    board[16] = property16;

    std::shared_ptr<Cell> property17 = std::make_shared<SLC>();
    board[17] = property17;

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {14, 70, 200, 550, 750, 950};
    std::shared_ptr<Cell> property18 = std::make_shared<ImprovableProperty>("BMH", 180, 100, set, tuitionFee);
    board[18] = property18;

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {16, 80, 220, 600, 800, 1000};
    std::shared_ptr<Cell> property19 = std::make_shared<ImprovableProperty>("OPT", 200, 100, set, tuitionFee);
    board[19] = property19;

    std::shared_ptr<Cell> property20 = std::make_shared<GooseNesting>();
    board[20] = property20;

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {18, 90, 250, 700, 875, 1050};
    std::shared_ptr<Cell> property21 = std::make_shared<ImprovableProperty>("EV1", 220, 150, set, tuitionFee);
    board[21] = property21;

    std::shared_ptr<Cell> property22 = std::make_shared<NeedlesHall>();
    board[22] = property22;

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {18, 90, 250, 700, 875, 1050};
    std::shared_ptr<Cell> property23 = std::make_shared<ImprovableProperty>("EV2", 220, 150, set, tuitionFee);
    board[23] = property23;

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {20, 100, 300, 750, 925, 1100};
    std::shared_ptr<Cell> property24 = std::make_shared<ImprovableProperty>("EV3", 240, 150, set, tuitionFee);
    board[24] = property24;

    set = {"MKV", "UWP", "V1", "REV"};
    std::shared_ptr<Cell> property25 = std::make_shared<Residences>("V1", set);
    board[25] = property25;

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {22, 110, 330, 800, 975, 1150};
    std::shared_ptr<Cell> property26 = std::make_shared<ImprovableProperty>("PHYS", 260, 150, set, tuitionFee);
    board[26] = property26;

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {22, 110, 330, 800, 975, 1150};
    std::shared_ptr<Cell> property27 = std::make_shared<ImprovableProperty>("B1", 260, 150, set, tuitionFee);
    board[27] = property27;

    set = {"PAC", "CIF"};
    std::shared_ptr<Cell> property28 = std::make_shared<Gym>("CIF", set);
    board[28] = property28;

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {24, 120, 360, 850, 1025, 1200};
    std::shared_ptr<Cell> property29 = std::make_shared<ImprovableProperty>("B2", 280, 150, set, tuitionFee);
    board[29] = property29;

    std::shared_ptr<Cell> property30 = std::make_shared<GoToTims>();
    board[30] = property30;

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {26, 130, 390, 900, 1100, 1275};
    std::shared_ptr<Cell> property31 = std::make_shared<ImprovableProperty>("EIT", 300, 200, set, tuitionFee);
    board[31] = property31;

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {26, 130, 390, 900, 1100, 1275};
    std::shared_ptr<Cell> property32 = std::make_shared<ImprovableProperty>("ESC", 300, 200, set, tuitionFee);
    board[32] = property32;

    std::shared_ptr<Cell> property33 = std::make_shared<SLC>();
    board[33] = property33;

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {28, 150, 450, 1000, 1200, 1400};
    std::shared_ptr<Cell> property34 = std::make_shared<ImprovableProperty>("C2", 320, 200, set, tuitionFee);
    board[34] = property34;

    set = {"MKV", "UWP", "V1", "REV"};
    std::shared_ptr<Cell> property35 = std::make_shared<Residences>("REV", set);
    board[35] = property35;

    std::shared_ptr<Cell> property36 = std::make_shared<NeedlesHall>();
    board[36] = property36;

    set = {"MC", "DC"};
    tuitionFee = {35, 175, 500, 1100, 1300, 1500};
    std::shared_ptr<Cell> property37 = std::make_shared<ImprovableProperty>("MC", 350, 200, set, tuitionFee);
    board[37] = property37;

    std::shared_ptr<Cell> property38 = std::make_shared<CoopFee>();
    board[38] = property38;

    set = {"MC", "DC"};
    tuitionFee = {50, 200, 600, 1400, 1700, 2000};
    std::shared_ptr<Cell> property39 = std::make_shared<ImprovableProperty>("DC", 400, 200, set, tuitionFee);
    board[39] = property39;
}

Board::~Board() {}

int Board::roll() {
    
    std::srand((unsigned int)std::time(NULL));
    
    int dice1 = 1 + (std::rand() % 6);
    int dice2 = 1 + (std::rand() % 6);

    if (dice1 == dice2) {
        rollDouble = true;
    }
    else {
        rollDouble = false;
    }

    return (dice1 + dice2);
}
