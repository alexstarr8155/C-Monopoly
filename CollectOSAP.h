#ifndef _COLLECTOSAP_H_
#define _COLLECTOSAP_H_

#include "Cell.h"
#include <vector>

class CollectOSAP: public Cell {
	public:
		CollectOSAP (std::vector<char> & chars);
		virtual void action (std::shared_ptr<Player> p, bool b) override;
};

#endif
