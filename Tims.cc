#include "Tims.h"
#include "Player.h"
using namespace std;

Tims::Tims() : Cell{"DC TIMS LINE"} {}

// updates the on_cell member that there is a player on such cell
void Tims::action(shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

