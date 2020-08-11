#include "GoToTims.h"
#include "Player.h"

using namespace std;

GoToTims::GoToTims (): Cell{"GO TO TIMS"} {}

void GoToTims::action (shared_ptr<Player> p, bool b) {
	p->goToTims();
}
