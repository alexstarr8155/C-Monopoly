#include "GoToTims.h"
#include "Player.h"
#include "Board.h"

using namespace std;

GoToTims::GoToTims (Board * owner): Cell{"GO TO TIMS"}, owner{owner} {}

void GoToTims::action (shared_ptr<Player> p, bool b) {
	cout << "You landed on GoToTims!" << endl;
	
	owner->moveBy(20);
	p->goToTims();
	//probably add a reference to the Tims Cell 
}
