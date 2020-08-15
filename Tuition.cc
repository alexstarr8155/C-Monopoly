#include "Tuition.h"
#include "Player.h"

using namespace std;

Tuition::Tuition (): Cell{"TUITION"} {};

void Tuition::action (shared_ptr<Player> p, bool b) {
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
			cout << "Please enter M or W" << endl;
		}
	}
}
