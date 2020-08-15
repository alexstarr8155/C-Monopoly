#include "NeedlesHall.h"
#include "Player.h"
#include "Board.h"
#include <stdlib.h>

NeedlesHall::NeedlesHall(Board * owner): Cell{"NEEDLES HALL"}, owner{owner} {}

// updates the on_cell member that there is a player on such cell
// adds or removes a certain amount of money from the player landing (dependent on the probability)
void NeedlesHall::action(std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;	

	int timsChance = rand() % 100;
	
	if (timsChance == 1) {
		try {
			owner->addTimsCard();
			p->addTimsCard();
		}
		catch(...){
			std::cout << "You could have gotten a Get Out Of Tims Line card, but there are too many in circulation" << std::endl;
		}
		return;
	}

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
