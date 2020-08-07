#include "Subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> o) {
	observers.push_back(o);
}

void Subject::notifyObservers() {
	
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->notify(*this);
	}
}
