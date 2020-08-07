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
		int owner;
	public:
		Property (const std::string & name, int price, int base_rent);
		
		int getPrice () const;
		virtual int getRent () const = 0;
		bool is_mortgaged () const;
		void setOwner (int player);
		int getOwner () const;

		void mortgage ();
		void unmortgage ();
		virtual int getValue () const;
		void action (std::shared_ptr<Player> p, bool b);
};

#endif 
