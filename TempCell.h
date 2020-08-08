#ifndef TEMP_CELL_H
#define TEMP_CELL_H
#include <map>
#include <string>

class TempCell {

	std::string cellName;
	int houses;
	std::map<char, bool> players;


	public:
		TempCell(std::string cellName, int houses, std::map<char, bool> players);
		~TempCell();
		std::string getName();
		int getHouses();
		std::map<char, bool> getPlayers();

};

#endif
