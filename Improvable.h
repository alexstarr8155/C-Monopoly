#ifndef _IMPROVABLE_H_
#define _IMPROVABLE_H_
#include "Property.h"

/* this class represents the Improvable Property Tiles (AL, ML, MC, DC, etc) of the Board */

class ImprovableProperty : public Property {
	
	int improv_cost; // represents the cost of adding an improvement to such property
	std::vector<int> tuition; // represents the cost of the property (dependent on the number of improvements)
	bool completeSet() const; // bool representing if the set is complete

	public:
		ImprovableProperty(const std::string &name, int purch_cost, int up_cost, std::vector<std::string> set, std::vector<int> tuition);
		
		virtual void mortgage();
		virtual void upgrade() override;
		virtual void downgrade() override;
		virtual int getRent() const override;
		int getValue() const override;
};

#endif

