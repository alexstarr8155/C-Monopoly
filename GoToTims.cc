#include "GoToTims.h"
#include "Player.h"

using namespace std;

GoToTims::GoToTims (const string &name): Cell{name} {}

void GoToTims::action (shared_ptr<Player> p, bool b) {
	p->goToTims();
}
