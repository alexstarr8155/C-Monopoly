#include "Player.h"
#include "Improvable.h"
#include <string>
#include <iostream>

using namespace std;


int main () {
	auto p = make_shared<Player> ("James", 1, 1500);
	
	cout << p->getPlayerName() << ", " << p->getPlayerNum() << ", " << p->getMoney() << ", " << p->getNetWorth() << endl;

	auto mc = make_shared<ImprovableProperty> ("MC", 350, 35);
	
	cout << mc->getName() << ", " << mc->getPrice() << ", " << mc->getRent() << ", " << mc->getNumImprov() << endl;
	cout << "Owned by player " << mc->getOwner () << endl;

	p->buy(mc);
	cout << "Owned by player " << mc->getOwner () << endl;
	auto p_prop = p->getProperties (); 
	for (auto it = p_prop.begin(); it != p_prop.end(); ++it){
		cout << (*it)->getName () << endl;
	}

}
