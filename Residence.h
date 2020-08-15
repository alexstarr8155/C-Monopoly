#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_
#include "Property.h"

/* this class represents the Residence Property Tiles (MKV, UWP, V1, REV) of the Board */

class Residences : public Property {
	
	public:
		Residences(const std::string &name, std::vector<std::string> set);
		virtual int getRent() const override;
};

#endif
