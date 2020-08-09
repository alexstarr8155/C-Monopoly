#include "CoopFee.h"

CoopFee::CoopFee() : Cell{"CoopFee"} {}

void CoopFee::action(std::shared_ptr<Player> p, bool b) {
	p->removeMoney(150);
}
