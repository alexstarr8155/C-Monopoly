#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H

#include "Cell.h"
#include "Player.h"

class NeedlesHall : public Cell {
	public:
		NeedlesHall();
		virtual void action(std::shared_ptr<Player> p, bool b) override;

};

#endif
