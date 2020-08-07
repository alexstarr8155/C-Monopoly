#ifndef _SUBJECT_H_
#define _SUBJECT_H_

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
