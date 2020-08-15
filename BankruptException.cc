#include "BankruptException.h"

BankruptException::BankruptException(int owed, std::shared_ptr<Player> creditor): owed{owed}, creditor{creditor} {
	
}

std::shared_ptr<Player> BankruptException::getCreditor() {
	return creditor;
}

int BankruptException::getOwed() {
	return owed;
}
