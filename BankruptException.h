#ifndef BANKRUPT_EXCEPTION_H
#define BANKRUPT_EXCEPTION_H
#include <memory>

class Player;

class BankruptException {
	private:
		int owed;
		std::shared_ptr<Player> creditor;
	public:
		BankruptException(int owed, std::shared_ptr<Player> creditor);
		int getOwed();
		std::shared_ptr<Player> getCreditor();
};


#endif
