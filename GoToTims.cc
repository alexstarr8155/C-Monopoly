#include "GoToTims.h"
#include "Player.h"
#include "Board.h"
using namespace std;

GoToTims::GoToTims (Board * owner): Cell{"GO TO TIMS"}, owner{owner} {}

// moves the player to the DC Tims Line Tile of the board
void GoToTims::action (shared_ptr<Player> p, bool b) {
	cout << "You landed on GoToTims!" << endl;
	owner->moveBy(-20);
	p->goToTims();
}
