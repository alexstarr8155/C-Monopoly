#include "CollectOSAP.h"
#include "Player.h"

CollectOSAP::CollectOSAP (): Cell{"COLLECT OSAP"} {}

void CollectOSAP::action (std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

