#ifndef _GYM_H_
#define _GYM_H_

#include "Property.h"

class Gym : public Property {
	public:
		Gym (const std::string &name, int price, int base_rent);
		int getRent () const override;
};

#endif
