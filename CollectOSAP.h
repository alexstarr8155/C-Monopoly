#ifndef _COLLECTOSAP_H_
#define _COLLECTOSAP_H_
#include "Cell.h"
#include <vector>

/* this class represents the Collect Osap Tile of the Board */

class CollectOSAP: public Cell {
	public:
		CollectOSAP();
		virtual void action(std::shared_ptr<Player> p, bool b) override;
};

#endif
