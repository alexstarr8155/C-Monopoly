#ifndef _CELL_H_
#define _CELL_H_

#include <memory>
#include <string>
#include <map>
#include <iostream>


class Player;

class Cell {
	protected:
		std::string name;
		std::map<char, bool> on_cell;
		int numImprovements;
	public:
		Cell (const std::string &name);

		std::string getName () const;
		
		virtual void action (std::shared_ptr<Player> p, bool b) = 0;
		void leave (std::shared_ptr<Player> p);

		std::map<char, bool> who_on_cell ();
		int getNumImprov () const;
};

#endif
