#include "CollectOSAP.h"
#include "Player.h"

CollectOSAP::CollectOSAP (int playerNum): Cell{"COLLECT OSAP"} {
	std::vector<char> playerChar = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
	for (int i = 0; i < playerNum; ++i) {
		on_cell[playerChar[i]] = true;
	}
}

void CollectOSAP::action (std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}

