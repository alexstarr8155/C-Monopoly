#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Subject;

class Observer {
	public:
		notify (Subject whoNotified) = 0;
};

#endif
