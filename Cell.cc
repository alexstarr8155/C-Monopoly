#include "Cell.h"
#include "Player.h"
using namespace std;

/* initial construction of the Cell class where there is no one on the cell */
Cell::Cell (const string & name): name{name} {
	numImprovements = -2;
	on_cell = {
		{'G', false},
		{'B', false},
		{'D', false},
		{'P', false},
		{'S', false},
		{'$', false},
		{'L', false},
		{'T', false}
	};
}

// returns the name of the cell
string Cell::getName() const {
	return name;
}

// the a player with 'playerChar' as character is on the cell
void Cell::setOnCell(char playerChar) {
	on_cell[playerChar] = true;
}

// returns the map representing which players are on the cell
map<char, bool> Cell::who_on_cell() {
	return on_cell;
}

// the player 'p' is now not on the cell
void Cell::leave(shared_ptr<Player> p){ 
	on_cell.at(p->getPlayerChar ()) = false;
}

// sets the number of improvements that Cell should have
void Cell::setNumImprov (int num) {
	this->numImprovements = num;
}

// returns the number of improvements on such cell
// Note: really only applicable for improvableProperty
int Cell::getNumImprov () const {
	return numImprovements;
}

/// set player 'p' to be the owner of Cell
void Cell::setOwner (std::shared_ptr<Player> p) {
	this->owner = p;
}

// returns the owner of Cell
shared_ptr<Player> Cell::getOwner () {
	return owner;
}

// sets if the Cell is mortgaged or not
void Cell::setMortgage(bool isMortgaged) {
	this->mortgaged = isMortgaged;
}

// returns if Cell is mortgaged or not
bool Cell::is_mortgaged () const {
	return mortgaged;
}

