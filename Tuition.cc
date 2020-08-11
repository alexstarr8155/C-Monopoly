#include "Tuition.h"
#include "Player.h"

using namespace std;

Tuition::Tuition (): Cell{"TUITION"} {};

void Tuition::action (shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}
