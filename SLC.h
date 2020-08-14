#ifndef SLC_H
#define SLC_H

#include "Cell.h"
#include "Player.h"

class Board;

class SLC : public Cell{

	private:
		Board *owner;	
	public:
		SLC();
		SLC(Board* owner);
		virtual void action(std::shared_ptr<Player> p, bool b) override;


};

#endif
