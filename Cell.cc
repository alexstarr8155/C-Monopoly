#include "Cell.h"
using namespace std;

Cell::Cell (const string & name): name{name} {
	numImprovements = -1;
}

string Cell::getName () const {
	return name;
}

map<char, bool> Cell::who_on_cell () {
	return on_cell;
}

int Cell::getNumImprov () const {
	return numImprovements;
}

