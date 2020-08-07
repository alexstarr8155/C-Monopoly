#ifndef _GYM_H_
#define _GYM_H_

#include "Property.h"

class Gym : public Property {
	int getRent () const override;
	void notify (Subject & whoNotified) override;
};

#endif
