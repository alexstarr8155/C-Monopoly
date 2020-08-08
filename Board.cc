#include "Board.h"

Board::Board() {

    std::shared_ptr<TempCell> property1 =  std::make_shared<TempCell>("GOOSE NESTING");
    board[1] = property1;

    std::shared_ptr<TempCell> property2 =  std::make_shared<TempCell>("EV1");
    board[2] = property2;

    std::shared_ptr<TempCell> property3 =  std::make_shared<TempCell>("NEEDLES HALL");
    board[3] = property3;

    std::shared_ptr<TempCell> property4 =  std::make_shared<TempCell>("EV2");
    board[4] = property4;

    std::shared_ptr<TempCell> property5 =  std::make_shared<TempCell>("EV3");
    board[5] = property5;

    std::shared_ptr<TempCell> property6 =  std::make_shared<TempCell>("V1");
    board[6] = property6;

    std::shared_ptr<TempCell> property7 =  std::make_shared<TempCell>("PHYS");
    board[7] = property7;

    std::shared_ptr<TempCell> property8 =  std::make_shared<TempCell>("B1");
    board[8] = property8;

    std::shared_ptr<TempCell> property9 =  std::make_shared<TempCell>("CIF");
    board[9] = property9;

    std::shared_ptr<TempCell> property10 =  std::make_shared<TempCell>("B2");
    board[10] = property10;

    std::shared_ptr<TempCell> property11 =  std::make_shared<TempCell>("GO TO TIMS");
    board[11] = property11;

    std::shared_ptr<TempCell> property12 =  std::make_shared<TempCell>("OPT");
    board[12] = property12;

    std::shared_ptr<TempCell> property13 =  std::make_shared<TempCell>("EIT");
    board[13] = property13;

    std::shared_ptr<TempCell> property14 =  std::make_shared<TempCell>("BMH");
    board[14] = property14;

    std::shared_ptr<TempCell> property15 =  std::make_shared<TempCell>("ESC");
    board[15] = property15;

    std::shared_ptr<TempCell> property16 =  std::make_shared<TempCell>("SLC");
    board[16] = property16;

    std::shared_ptr<TempCell> property17 =  std::make_shared<TempCell>("SLC");
    board[17] = property17;

    std::shared_ptr<TempCell> property18 =  std::make_shared<TempCell>("LHI");
    board[18] = property18;

    std::shared_ptr<TempCell> property19 =  std::make_shared<TempCell>("C2");
    board[19] = property19;

    std::shared_ptr<TempCell> property20 =  std::make_shared<TempCell>("UWP");
    board[20] = property20;

    std::shared_ptr<TempCell> property21 =  std::make_shared<TempCell>("REV");
    board[21] = property21;

    std::shared_ptr<TempCell> property22 =  std::make_shared<TempCell>("CPH");
    board[22] = property22;

    std::shared_ptr<TempCell> property23 =  std::make_shared<TempCell>("NEEDLES HALL");
    board[23] = property23;

    std::shared_ptr<TempCell> property24 =  std::make_shared<TempCell>("DWE");
    board[24] = property24;

    std::shared_ptr<TempCell> property25 =  std::make_shared<TempCell>("MC");
    board[25] = property25;

    std::shared_ptr<TempCell> property26 =  std::make_shared<TempCell>("PAC");
    board[26] = property26;

    std::shared_ptr<TempCell> property27 =  std::make_shared<TempCell>("COOP FEE");
    board[27] = property27;

    std::shared_ptr<TempCell> property28 =  std::make_shared<TempCell>("RCH");
    board[28] = property28;

    std::shared_ptr<TempCell> property29 =  std::make_shared<TempCell>("DC");
    board[29] = property29;

    std::shared_ptr<TempCell> property30 =  std::make_shared<TempCell>("DC TIMS LINE");
    board[30] = property30;

    std::shared_ptr<TempCell> property31 =  std::make_shared<TempCell>("HH");
    board[31] = property31;

    std::shared_ptr<TempCell> property32 =  std::make_shared<TempCell>("PAS");
    board[32] = property32;

    std::shared_ptr<TempCell> property33 =  std::make_shared<TempCell>("NEEDLES HALL");
    board[33] = property33;

    std::shared_ptr<TempCell> property34 =  std::make_shared<TempCell>("ECH");
    board[34] = property34;

    std::shared_ptr<TempCell> property35 =  std::make_shared<TempCell>("MKV");
    board[35] = property35;

    std::shared_ptr<TempCell> property36 =  std::make_shared<TempCell>("TUITION");
    board[36] = property36;

    std::shared_ptr<TempCell> property37 =  std::make_shared<TempCell>("ML");
    board[37] = property37;

    std::shared_ptr<TempCell> property38 =  std::make_shared<TempCell>("SLC");
    board[38] = property38;

    std::shared_ptr<TempCell> property39 =  std::make_shared<TempCell>("AL");
    board[39] = property39;

    std::shared_ptr<TempCell> property40 =  std::make_shared<TempCell>("COLLECT OSAP");
    board[40] = property40;
}

Board::~Board() {}
