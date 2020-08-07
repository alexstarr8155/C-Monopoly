#include "Cell.h"
using namespace std;

Cell::Cell (const string & name): name{name} {}

string Cell::getName () const {
	return name;
}
