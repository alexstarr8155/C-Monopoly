#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_

#include "Property.h"

class Residences : public Property {

	public:
		Residences (const std::string &name, int price, int base_rent);
		int getRent () const override;
};

#endif
