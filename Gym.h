#ifndef _GYM_H_
#define _GYM_H_
#include "Property.h"

/* this class represents the Gym Tiles (PAC and CIF) of the Board */

class Gym : public Property {

	public:
		Gym(const std::string &name, std::vector<std::string> set);
		virtual int getRent() const override;
};

#endif
