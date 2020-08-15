#ifndef COOPFEE_H
#define COOPFEE_H
#include "Cell.h"
#include "Player.h"

/* this class represents the Coop Fee Tile of the Board */

class CoopFee : public Cell {

	public:
		CoopFee();
		virtual void action(std::shared_ptr<Player> p, bool b) override;
};

#endif
