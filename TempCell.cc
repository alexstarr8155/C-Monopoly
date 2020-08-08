#include "TempCell.h"

TempCell::TempCell(std::string cellName, int houses, std::map<char, bool> players) : cellName{cellName}, houses{houses}, players{players} {}
TempCell::~TempCell() {}

std::string TempCell::getName() {
	return cellName;
}

int TempCell::getHouses() {
	return houses;
}

std::map<char, bool> TempCell::getPlayers() {
	return players;
}
