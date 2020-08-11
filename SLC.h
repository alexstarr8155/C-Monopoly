#ifndef SLC_H
#define SLC_H

#include "Cell.h"
#include "Player.h"

class SLC : public Cell{
	
	public:
		SLC();
		virtual void action(std::shared_ptr<Player> p, bool b) override;


};

#endif
