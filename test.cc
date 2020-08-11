#include "Player.h"
#include "Improvable.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


int main () {
	//auto p = make_shared<Player> ("James", 'G', 1500);
	//auto q = make_shared<Player> ("Alex", 'B', 1500);
	
	//cout << p->getPlayerName () << " has $" << p->getMoney() << endl;

	//Creation of the Math Set
	vector<string> set = {"MC", "DC"};

	vector<int> mc_tuition = {35, 175, 500, 1100, 1300, 1500};
	vector<int> dc_tuition = {50, 200, 600, 1400, 1700, 2000};
	auto MC = make_shared<ImprovableProperty> ("MC", 350, 200, set, mc_tuition);
	auto DC = make_shared<ImprovableProperty> ("DC", 400, 200, set, dc_tuition);
	
	//cout << "Im " << DC.getName () <<  " and my rent is: " << DC.getRent () << endl;
	
	MC->attach(DC.get());
//	DC->attach(MC.get());

//	cout << "IM " << MC->getName() << " and my rent is: " << MC->getRent() << endl;

//	MC->action(p, true);

/*	auto prop = p->getProperties ();

	for (auto it = prop.begin(); it != prop.end(); ++it) {
		cout << (*it)->getName () << endl;
	}

	cout << MC->getRent () << endl;

	DC->action(p, true);

	cout << MC->getRent () << endl; 

	cout << p->getPlayerName () << " has $" << p->getMoney () << endl; */
}
