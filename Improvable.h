#ifndef _IMPROVABLE_H_
#define _IMPROVABLE_H_

#include "Property.h"

class ImprovableProperty : public Property {
	int numImprovements;

	public:
		ImprovableProperty (std::string &name, int price, int base_rent);

		void upgrade (int num);
		void downgrade (int num);
		int getValue () const;
		int getRent () const override;
};

#endif

