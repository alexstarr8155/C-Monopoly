#ifndef _TIMS_H_
#define _TIMS_H_

#include "Cell.h"

class Tims: public Cell {
	public:
		Tims(const std::string &name);
		virtual void action (std::shared_ptr<Player> p, bool b) override;

};

#endif
