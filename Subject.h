#ifndef SUBJECT_H
#define SUBJECT_H

#include <memory>
#include <vector>

class Observer;
class Subject {

private:
	std::vector<std::shared_ptr<Observer>> observers;

public:
	void attach(std::shared_ptr<Observer> o);
	virtual void notifyObservers();

};

#endif
