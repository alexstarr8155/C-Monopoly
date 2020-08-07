#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include "Cell.h"

// In the case of a property, it's observers are not only the board,
// 	but also any other property in it's set. Ex: If this cell was 
// 	DC, then it would also be observing MC and vice versa.

class Property : public Cell {
	protected:
		int price; //the price to buy this property
		int rent;
		bool owned;
		bool mortgaged;
		std::shared_ptr<Player> owner;
	public:
		Property (std::string & name, int price, int base_rent);
		
		int getPrice () const;
		virtual int getRent () const = 0;
		bool is_mortgaged () const;
		void setOwner (std::shared_ptr <Player> p);
		std::shared_ptr<Player> getOwner ();

		void mortgage ();
		void unmortgage ();
		virtual int getValue () const = 0; //returns the value of the property including all upgrades
		void action (std::shared_ptr<Player> p, bool b);
};

#endif 
