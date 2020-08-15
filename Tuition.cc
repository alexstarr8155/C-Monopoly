#include "Tuition.h"
#include "Player.h"
using namespace std;

Tuition::Tuition(): Cell{"TUITION"} {};

// updates the on_cell member that there is a player on such cell
// will remove a certain amount of money from the player that landed (dependent on if player chooses to remove percentage of net worth or $300)
void Tuition::action(shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;

	cout << "Choose between paying $300 (M) or 10% of your total worth(W)" << endl;
	cout << "Your current net worth is: " << p->getNetWorth() << endl;

	while (true){
		string in;
		cin >> in;

		if (in == "M" || in == "m"){
			p->removeMoney(300);
			break;
		}
		else if (in == "W" || in == "w"){
			p->removeMoney(p->getNetWorth()/10);
			break;
		}
		else {
			if (cin.fail ()) {
				break;
			}
			cout << "Please enter M or W" << endl;
		}
	}
}
