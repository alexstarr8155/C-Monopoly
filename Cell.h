#ifndef _CELL_H_
#define _CELL_H_
#include <memory>
#include <string>
#include <map>
#include <iostream>

class Player;

/* this class represents each tile in the games (properites, collect osap etc) */

class Cell {

	protected:
		std::string name; // name of cell
		int numImprovements; // number of improvements on a cell
		bool mortgaged; // bool representing if a cell is mortgaged or not
		
		std::map<char, bool> on_cell; // a map representing who is on the cell and who is not on the cell
		std::shared_ptr<Player> owner; // represents which player owns the cell

	public:
		
		Cell(const std::string &name);
		virtual void action(std::shared_ptr<Player> p, bool b) = 0;

		std::string getName() const;
		
		void setOnCell(char playerChar);
		std::map<char, bool> who_on_cell();
		void leave(std::shared_ptr<Player> p);

		void setNumImprov(int num);
		int getNumImprov() const;

		virtual void setOwner(std::shared_ptr<Player> p);
		std::shared_ptr<Player> getOwner();
		
		void setMortgage(bool isMortgaged);
		bool is_mortgaged() const;
};

#endif
