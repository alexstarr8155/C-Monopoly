#include "SLC.h"
#include "Board.h"
#include <stdlib.h>

SLC::SLC() : Cell{"SLC"} {}
SLC::SLC(Board* owner) : Cell{"SLC"}, owner{owner} {}

// updates the on_cell member that there is a player on such cell
// adds or removes a certain amount to the landing player's position (dependent on the probability)
void SLC::action(std::shared_ptr<Player> p, bool b) {
	
	std::cout << "You landed on SLC!" << std::endl;
	
	int timsChance = rand() % 100;

	if (timsChance == 1) {
		on_cell.at(p->getPlayerChar()) = true;

		try {
			owner->addTimsCard();
			p->addTimsCard();
			std::cout << "You got a Roll up the Rim Cup!" << std::endl;
		}
		catch (...){
			std::cout << "You could have gotten a Roll up the Rim Cup , but there are too many in circulation" << std::endl;
		}
		return;
	}

	int chance = rand() % 24;

	if (chance < 3) {
		owner->moveBy(-3);
	} else if (chance >= 3 && chance < 7) {
		owner->moveBy(-2);
	} else if (chance >= 7 && chance < 11) {
		owner->moveBy(-1);
	} else if (chance >= 11 && chance < 14) {
		owner->moveBy(1);
	} else if (chance >= 14 && chance < 18) {
		owner->moveBy(2);
	} else if (chance >= 18 && chance < 22) {
		owner->moveBy(3);
	} else if (chance == 22) {
		owner->moveTo(10);
		p->setInTims(true);
		owner->setRollDouble(0);
	} else if (chance == 23) {
		owner->moveTo(0);
	} else {
		throw "Ya done goofed";
	}
}
