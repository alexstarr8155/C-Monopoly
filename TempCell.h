#ifndef TEMP_CELL_H
#define TEMP_CELL_H
#include <vector>
#include <string>

class TempCell {

	std::string cellName;
	int houses;
	std::vector<bool> players;


	public:
		TempCell(std::string cellName);
		~TempCell();
		std::string getName();
		int getHouses();
		std::vector<bool> getPlayers();

};

#endif
