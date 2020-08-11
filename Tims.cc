#include "Tims.h"
#include "Player.h"

using namespace std;

Tims::Tims(): Cell{"DC TIMS LINE"} {}

void Tims::action (shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

