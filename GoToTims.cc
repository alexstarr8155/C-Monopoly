#include "GoToTims.h"

using namespace std;

GoToTims::GoToTims (const string &name): Cell{name} {}

void GoToTims::action (shared::ptr<Player> p, bool b) {
	p->goToTims();
}
