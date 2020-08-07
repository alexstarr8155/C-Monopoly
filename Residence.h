#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_

#include "Property.h"

class Residences : public Property {
	int getRent () const override;
	void notify (Subject & whoNotified) override;
};

#endif
