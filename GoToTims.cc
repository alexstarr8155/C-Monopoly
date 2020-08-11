#include "GoToTims.h"
#include "Player.h"

using namespace std;

GoToTims::GoToTims (): Cell{"Go To Tims"} {}

void GoToTims::action (shared_ptr<Player> p, bool b) {
	p->goToTims();
}
