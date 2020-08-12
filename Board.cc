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

Board::Board(int playerNum) : playerNum{playerNum} {

    std::vector<char> playerChar = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
    std::vector<std::string> playerStr = {"Goose", "GRT Bus", "Tim Hortons Doughnut", "Professor", "Student", "Money", "Laptop", "Pink Tie"};

    for (int i = 0; i < playerNum; i++) {
        std::shared_ptr<Player> player = std::make_shared<Player>(playerStr[i], playerChar[i], 1500);
        players[i] = player;
    }

    std::vector<std::string> set = {};
    std::vector<int> tuitionFee = {};

    set = {"AL", "ML"};
    tuitionFee = {2, 10, 30, 90, 160, 250};
    auto AL = std::make_shared<ImprovableProperty>("AL", 40, 50, set, tuitionFee);

    set = {"AL", "ML"};
    tuitionFee = {4, 20, 60, 180, 320, 450};
    auto ML = std::make_shared<ImprovableProperty>("ML", 60, 50, set, tuitionFee);

    AL->attach(ML.get());
    ML->attach(AL.get());

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {6, 30, 90, 270, 400, 550};
    auto ECH = std::make_shared<ImprovableProperty>("ECH", 100, 50, set, tuitionFee);

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {6, 30, 90, 270, 400, 550};
    auto PAS = std::make_shared<ImprovableProperty>("PAS", 100, 50, set, tuitionFee);

    set = {"ECH", "PAS", "HH"};
    tuitionFee = {8, 40, 100, 300, 450, 600};
    auto HH = std::make_shared<ImprovableProperty>("HH", 120, 50, set, tuitionFee);

    ECH->attach(PAS.get());
    ECH->attach(HH.get());

    PAS->attach(ECH.get());
    PAS->attach(HH.get());

    HH->attach(ECH.get());
    HH->attach(PAS.get());

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {10, 50, 150, 450, 625, 750};
    auto RCH = std::make_shared<ImprovableProperty>("RCH", 140, 100, set, tuitionFee);

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {10, 50, 150, 450, 625, 750};
    auto DWE = std::make_shared<ImprovableProperty>("DWE", 140, 100, set, tuitionFee);

    set = {"RCH", "DWE", "CPH"};
    tuitionFee = {12, 60, 180, 500, 700, 900};
    auto CPH = std::make_shared<ImprovableProperty>("CPH", 160, 100, set, tuitionFee);

    RCH->attach(DWE.get());
    RCH->attach(CPH.get());

    DWE->attach(RCH.get());
    DWE->attach(CPH.get());

    CPH->attach(RCH.get());
    CPH->attach(DWE.get());

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {14, 70, 200, 550, 750, 950};
    auto LHI = std::make_shared<ImprovableProperty>("LHI", 180, 100, set, tuitionFee);

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {14, 70, 200, 550, 750, 950};
    auto BMH = std::make_shared<ImprovableProperty>("BMH", 180, 100, set, tuitionFee);

    set = {"LHI", "BMH", "OPT"};
    tuitionFee = {16, 80, 220, 600, 800, 1000};
    auto OPT = std::make_shared<ImprovableProperty>("OPT", 200, 100, set, tuitionFee);

    LHI->attach(BMH.get());
    LHI->attach(OPT.get());

    BMH->attach(LHI.get());
    BMH->attach(OPT.get());

    OPT->attach(LHI.get());
    OPT->attach(BMH.get());

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {18, 90, 250, 700, 875, 1050};
    auto EV1 = std::make_shared<ImprovableProperty>("EV1", 220, 150, set, tuitionFee);

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {18, 90, 250, 700, 875, 1050};
    auto EV2 = std::make_shared<ImprovableProperty>("EV2", 220, 150, set, tuitionFee);

    set = {"EV1", "EV2", "EV3"};
    tuitionFee = {20, 100, 300, 750, 925, 1100};
    auto EV3 = std::make_shared<ImprovableProperty>("EV3", 240, 150, set, tuitionFee);

    EV1->attach(EV2.get());
    EV1->attach(EV3.get());

    EV2->attach(EV1.get());
    EV2->attach(EV3.get());

    EV3->attach(EV1.get());
    EV3->attach(EV2.get());

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {22, 110, 330, 800, 975, 1150};
    auto PHYS = std::make_shared<ImprovableProperty>("PHYS", 260, 150, set, tuitionFee);

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {22, 110, 330, 800, 975, 1150};
    auto B1 = std::make_shared<ImprovableProperty>("B1", 260, 150, set, tuitionFee);

    set = {"PHYS", "B1", "B2"};
    tuitionFee = {24, 120, 360, 850, 1025, 1200};
    auto B2 = std::make_shared<ImprovableProperty>("B2", 280, 150, set, tuitionFee);    

    PHYS->attach(B1.get());
    PHYS->attach(B2.get());

    B1->attach(PHYS.get());
    B1->attach(B2.get());

    B2->attach(PHYS.get());
    B2->attach(B1.get());

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {26, 130, 390, 900, 1100, 1275};
    auto EIT = std::make_shared<ImprovableProperty>("EIT", 300, 200, set, tuitionFee);

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {26, 130, 390, 900, 1100, 1275};
    auto ESC = std::make_shared<ImprovableProperty>("ESC", 300, 200, set, tuitionFee);

    set = {"EIT", "ESC", "C2"};
    tuitionFee = {28, 150, 450, 1000, 1200, 1400};
    auto C2 = std::make_shared<ImprovableProperty>("C2", 320, 200, set, tuitionFee);

    EIT->attach(ESC.get());
    EIT->attach(C2.get());

    ESC->attach(EIT.get());
    ESC->attach(C2.get());

    C2->attach(EIT.get());
    C2->attach(ESC.get());

    set = {"MC", "DC"};
    tuitionFee = {35, 175, 500, 1100, 1300, 1500};
    auto MC = std::make_shared<ImprovableProperty>("MC", 350, 200, set, tuitionFee);

    set = {"MC", "DC"};
    tuitionFee = {50, 200, 600, 1400, 1700, 2000};
    auto DC = std::make_shared<ImprovableProperty>("DC", 400, 200, set, tuitionFee);

    MC->attach(DC.get());
    DC->attach(MC.get());

    set = {"MKV", "UWP", "V1", "REV"};
    auto MKV = std::make_shared<Residences>("MKV", set);

    set = {"MKV", "UWP", "V1", "REV"};
    auto UWP = std::make_shared<Residences>("UWP", set);

    set = {"MKV", "UWP", "V1", "REV"};
    auto V1 = std::make_shared<Residences>("V1", set);

    set = {"MKV", "UWP", "V1", "REV"};
    auto REV = std::make_shared<Residences>("REV", set);

    MKV->attach(UWP.get());
    MKV->attach(V1.get());
    MKV->attach(REV.get());

    UWP->attach(MKV.get());
    UWP->attach(V1.get());
    UWP->attach(REV.get());

    V1->attach(MKV.get());
    V1->attach(UWP.get());
    V1->attach(REV.get());

    REV->attach(MKV.get());
    REV->attach(UWP.get());
    REV->attach(V1.get());

    set = {"PAC", "CIF"};
    auto PAC = std::make_shared<Gym>("PAC", set);

    set = {"PAC", "CIF"};
    auto CIF = std::make_shared<Gym>("CIF", set);    

    PAC->attach(CIF.get());
    CIF->attach(PAC.get());

    auto collectOsap = std::make_shared<CollectOSAP>(playerNum);
    auto slc = std::make_shared<SLC>();
    auto tuition = std::make_shared<Tuition>();
    auto needlesHall = std::make_shared<NeedlesHall>();
    auto DCTimsLine = std::make_shared<Tims>();
    auto gooseNesting = std::make_shared<GooseNesting>();
    auto goToTims = std::make_shared<GoToTims>();
    auto coopFee = std::make_shared<CoopFee>();
    

    board[0] = collectOsap;
    board[1] = AL;
    board[2] = slc;
    board[3] = ML;
    board[4] = tuition;
    board[5] = MKV;
    board[6] = ECH;
    board[7] = needlesHall;
    board[8] = PAS;
    board[9] = HH;
    board[10] = DCTimsLine;
    board[11] = RCH;
    board[12] = PAC;
    board[13] = DWE;
    board[14] = CPH;
    board[15] = UWP;
    board[16] = LHI;
    board[17] = slc;
    board[18] = BMH;
    board[19] = OPT;
    board[20] = gooseNesting;
    board[21] = EV1;
    board[22] = needlesHall;
    board[23] = EV2;
    board[24] = EV3;
    board[25] = V1;
    board[26] = PHYS;
    board[27] = B1;
    board[28] = CIF;
    board[29] = B2;
    board[30] = goToTims;
    board[31] = EIT;
    board[32] = ESC;
    board[33] = slc;
    board[34] = C2;
    board[35] = REV;
    board[36] = needlesHall;
    board[37] = MC;
    board[38] = coopFee;
    board[39] = DC;
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

void Board::playRound() {
	std::cout << "Starting Round" << std::endl;
	std::cout << "Playing with " << playerNum << " players" << std::endl;

	for (int i = 0; i < playerNum; ++i) {
		int playerPosition = players[i]->getPosition();
		std::cout << "Player " << (i+1) << " is at position " << playerPosition << std::endl;
		board[playerPosition]->leave(players[i]);
		int diceRoll = roll();
		std::cout << "Player " << (i+1) << " rolled a " << diceRoll << std::endl;
		players[i]->move(diceRoll);
		playerPosition = players[i]->getPosition();
		std::cout << "Player " << (i+1) << " is at position " << playerPosition << std::endl;
		board[playerPosition]->action(players[i], false);
	}
}

