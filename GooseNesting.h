#ifndef GOOSENESTING_H
#define GOOSENESTING_H
#include "Cell.h"
#include "Player.h"

/* this class represents the Goose Nesting of the Board */

class GooseNesting : public Cell {
	public:
		GooseNesting();
		virtual void action(std::shared_ptr<Player> p, bool b) override;
};

#endif
