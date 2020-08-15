#include "CollectOSAP.h"
#include "Player.h"

CollectOSAP::CollectOSAP (): Cell{"COLLECT OSAP"} {}

// updates the on_cell member that there is a player on such cell
void CollectOSAP::action(std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

