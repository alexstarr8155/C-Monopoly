#include "Cell.h"
#include "Player.h"

class SLC : public Cell {
	
	public:
		virtual void action(std::shared_ptr<Player> p, bool b) override;

}
