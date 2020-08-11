#include "NeedlesHall.h"
#include <stdlib.h>

NeedlesHall::NeedlesHall (): Cell{"Needles Hall"} {}

void NeedlesHall::action(std::shared_ptr<Player> p, bool b) {
	
	int chance = rand() % 18;

	if (chance < 1) {
		p->removeMoney(200);
	} else if (chance < 3) {
		p->removeMoney(100);
	} else if (chance < 6) {
		p->removeMoney(50);
	} else if (chance < 12) {
		p->addMoney(25);
	} else if (chance < 15) {
		p->addMoney(50);
	} else if (chance < 17) {
		p->addMoney(100);
	} else if (chance < 18) {
		p->addMoney(200);
	} else {
		throw "Random Number failed";
	}

}
