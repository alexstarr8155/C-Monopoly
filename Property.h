#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include "Cell.h"
#include <map>
#include <vector>

// In the case of a property, it's observers are not only the board,
// 	but also any other property in it's set. Ex: If this cell was 
// 	DC, then it would also be observing MC and vice versa.

class Property : public Cell {
	protected:
		int purchase_cost; //the price to buy this property
		int up_cost;
		bool owned;
		bool mortgaged;
		std::shared_ptr<Player> owner;
		std::map<std::string, char> set_ownership; // string is property name, char is player on property


		//Observers
		std::vector<Property*> observers;
	public:
		Property (const std::string & name, int purchase_cost, std::vector<std::string> set);
		
		int getPrice () const;
		virtual int getRent () const;
		bool is_mortgaged () const;
		void setOwner (std::shared_ptr<Player> p);
		std::shared_ptr<Player> getOwner ();

		void mortgage ();
		void unmortgage ();
		virtual int getValue () const;
		void action (std::shared_ptr<Player> p, bool b);


		// Subject methods
		void attach (Property * neighbour);
		void notifyObservers ();
		// Observer methods
		virtual void notify (Property & whoNotified);
};

#endif 
