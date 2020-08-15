#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include "Cell.h"

class Board;

/* this class represents the Go To Tims Tile of the Board */

class GoToTims : public Cell {
	
	Board * owner;

	public:
		GoToTims (Board * owner);
		virtual void action (std::shared_ptr<Player> p, bool b) override;
};

#endif
