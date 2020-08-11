#include "GoToTims.h"
#include "Player.h"

using namespace std;

GoToTims::GoToTims (): Cell{"GO TO TIMS"} {}

void GoToTims::action (shared_ptr<Player> p, bool b) {

	cout << "This is a temp msg to let you know you landed on GoToTims" << endl;

	p->goToTims();
	//probably add a reference to the Tims Cell 
}
