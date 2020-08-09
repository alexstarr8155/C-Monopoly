#ifndef _CELL_H_
#define _CELL_H_

#include <memory>
#include <string>
#include <map>
#include <iostream>
#include "Subject.h"
#include "Observer.h"


class Player;

class Cell : public Subject, public Observer {
	protected:
		std::string name;
		std::map<char, bool> on_cell;
		int numImprovements;
	public:
		Cell (const std::string &name);

		std::string getName () const;
		/* change back to virtual after */
		virtual void action (std::shared_ptr<Player> p, bool b) {
			std::cout << "I am performing an action" << std::endl;	
		}
		std::map<char, bool> who_on_cell ();
		int getNumImprov () const;
		/* delete after */
		void notify (Subject &whoNotified);
		std::shared_ptr<Player> getOwner();
};

#endif
