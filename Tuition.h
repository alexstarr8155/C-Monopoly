#ifndef _TUITION_H_
#define _TUITION_H_

#include "Cell.h"

class Tuition : public Cell {
	public:
		Tuition (const std::string &name);
		virtual void action (std::shared_ptr<Player> p, bool b) override;

};

#endif
