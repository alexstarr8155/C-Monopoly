#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "Cell.h"
#include "Player.h"

class GooseNesting : public Cell {
	public:
		GooseNesting();

		virtual void action (std::shared_ptr<Player> p, bool b) override;
};

#endif
