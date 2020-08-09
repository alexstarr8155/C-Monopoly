#include "Cell.h"
#include "Player.h"

class SLC : public Cell{
	
	public:
		SLC();
		virtual void action(std::shared_ptr<Player> p, bool b) override;
		virtual void notify(Subject & whoNotified) override {};
		
		// "Remove the following method eventually"
		virtual std::shared_ptr<Player> getOwner() override {return nullptr;};


};
