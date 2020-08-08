#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <map>
#include <string>
#include "TempCell.h"

class Board {

	std::map<int, std::shared_ptr<TempCell>> board;

	public:
		Board();
		~Board();
		friend class BoardDisplay;
};

#endif
