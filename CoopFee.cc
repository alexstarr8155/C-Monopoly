#include "CoopFee.h"
#include "Player.h"


CoopFee::CoopFee() : Cell{"Coop Fee"} {}

void CoopFee::action(std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;

	p->removeMoney(150);
}
