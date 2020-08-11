#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_

#include "Property.h"

class Residences : public Property {
	
	int base_rent;

	public:
		Residences (const std::string &name, int price, int base_rent, std::vector<std::string> set);
		int getRent () const override;
};

#endif
