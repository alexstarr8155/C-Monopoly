#include "TempCell.h"

TempCell::TempCell(std::string cellName) : cellName{cellName} {
	this->houses = 0;
	this->players = {};
}

TempCell::~TempCell() {}

std::string TempCell::getName() {
	return cellName;
}

int TempCell::getHouses() {
	return houses;
}

std::vector<bool> TempCell::getPlayers() {
	return players;
}
