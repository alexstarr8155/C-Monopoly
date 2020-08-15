#include "CoopFee.h"
#include "Player.h"

CoopFee::CoopFee() : Cell{"Coop Fee"} {}

// updates the on_cell member that there is a player on such cell and removes $150 from that player
void CoopFee::action(std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
	p->removeMoney(150);
}
