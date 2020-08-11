#ifndef _GYM_H_
#define _GYM_H_

#include "Property.h"

class Gym : public Property {
	
	int base_rent;

	public:
		Gym (const std::string &name, int price, int base_rent, std::vector<std::string> set);
		int getRent () const override;
};

#endif
