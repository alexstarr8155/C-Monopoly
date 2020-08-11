#ifndef _COLLECTOSAP_H_
#define _COLLECTOSAP_H_

#include "Cell.h"

class CollectOSAP: public Cell {
	public:
		CollectOSAP ();
		virtual void action (std::shared_ptr<Player> p, bool b) override;
};

#endif
