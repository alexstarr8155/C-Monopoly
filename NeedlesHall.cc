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
			std::cout << "You got a Roll up the Rim Cup!" << std::endl;
		}
		catch(...){
			std::cout << "You could have gotten a Roll up the Rim Cup, but there are too many in circulation" << std::endl;
		}
		return;
	}

	int chance = rand() % 18;

	if (chance < 1) {
		p->removeMoney(200);
		std::cout << "You lost $200" << std::endl;
	} else if (chance < 3) {
		p->removeMoney(100);
		std::cout << "You lost $100" << std::endl;
	} else if (chance < 6) {
		p->removeMoney(50);
		std::cout << "You lost $50" << std::endl;
	} else if (chance < 12) {
		p->addMoney(25);
		std::cout << "You got $25" << std::endl;
	} else if (chance < 15) {
		p->addMoney(50);
		std::cout << "You got $50" << std::endl;
	} else if (chance < 17) {
		p->addMoney(100);
		std::cout << "You got $100" << std::endl;
	} else if (chance < 18) {
		p->addMoney(200);
		std::cout << "You got $200" << std::endl;
	} else {
		throw "Random Number failed";
	}
}
