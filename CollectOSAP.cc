#include "CollectOSAP.h"
#include "Player.h"

CollectOSAP::CollectOSAP (std::vector<char>& chars): Cell{"COLLECT OSAP"} {
	for (int i = 0; i < chars.size(); ++i) {
		on_cell[chars[i]] = true;
	}
}

void CollectOSAP::action (std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

