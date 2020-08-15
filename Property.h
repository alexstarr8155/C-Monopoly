#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include <vector>
#include "Cell.h"
#include <map>

// In the case of a property, it's observers are not only the board,
// 	but also any other property in it's set. Ex: If this cell was 
// 	DC, then it would also be observing MC and vice versa.

/* this class represents the Property Tiles (AL, MKV, PAC, etc) of the Board */

class Property : public Cell {
	protected:
		int purchase_cost; // represents the cost to buy this property
		bool owned; // represents if the property is owned or not
		std::map<std::string, char> set_ownership; // string is property name, char is player on property
		std::vector<Property*> observers; // Observers

	public:
		Property(const std::string & name, int purchase_cost, std::vector<std::string> set);

		virtual int getRent() const = 0;
		virtual void mortgage();
		virtual int getValue() const;
		virtual void upgrade();
		virtual void downgrade();
		
		void action(std::shared_ptr<Player> p, bool b);
		int getPrice() const;
		void unmortgage();
		void setOwner(Player* p);	
		void setOwner(std::shared_ptr<Player> p) override;

		// Subject methods
		void attach (Property * neighbour);
		void notifyObservers();
		// Observer methods
		virtual void notify(Property & whoNotified);
};

#endif 
