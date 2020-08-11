#include "SLC.h"
#include <stdlib.h>

SLC::SLC () : Cell{"SLC"} {}


void SLC::action(std::shared_ptr<Player> p, bool b) {
	
	std::cout << "This is a temp msg to let you know you landed on SLC" << std::endl;
	
	int chance = rand() % 24;

	if (chance < 3) {
		p->move(-3);
	} else if (chance >= 3 && chance < 7) {
		p->move(-2);
	} else if (chance >= 7 && chance < 11) {
		p->move(-1);
	} else if (chance >= 11 && chance < 14) {
		p->move(1);
	} else if (chance >= 14 && chance < 18) {
		p->move(2);
	} else if (chance >= 18 && chance < 22) {
		p->move(3);
	} else if (chance == 22) {
		p->moveTo(10);
	} else if (chance == 23) {
		p->moveTo(0);
	} else {
		throw "Ya done goofed";
	}
}
