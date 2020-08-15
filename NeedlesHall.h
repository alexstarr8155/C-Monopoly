#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include "Cell.h"
#include "Player.h"

/* this class represents the Needle Hall Tiles of the Board */

class NeedlesHall : public Cell {
	public:
		NeedlesHall();
		virtual void action(std::shared_ptr<Player> p, bool b) override;
};

#endif
