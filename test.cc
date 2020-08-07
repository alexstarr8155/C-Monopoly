#include "Player.h"
#include <string>
#include <iostream>

using namespace std;


int main () {
	auto p = make_shared<Player> ("James", 1, 1500);
	
	cout << p->getPlayerName() << ", " << p->getPlayerNum() << ", " << p->getMoney() << endl;	
}
