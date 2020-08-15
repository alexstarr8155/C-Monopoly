#include "Player.h"
#include <algorithm>
#include <iostream>
#include "Improvable.h"
#include "BankruptException.h"

Player::Player (const std::string &name, char playerChar, int money): name{name}, playerChar{playerChar}, money{money}, netWorth{money} {
	position = 0;
}

char Player::getPlayerChar() const {
	return playerChar;
}

std::string Player::getPlayerName() const {
	return name;
}

int Player::getMoney() const {
	return money;
}

//"Perhaps this should return a shared pointer instead?"
std::vector<Property *> Player::getProperties() const{
	return owned;
}

void Player::updateNetWorth() {
	int worth = 0;

	for (int i = 0; i < owned.size(); i++) {
		worth += owned[i]->getValue();
	}
	netWorth = worth + money;
}

void Player::goToTims() {
	inTims = true;
	moveTo(10);	
}
void Player::getOutOfTims(bool bail) {

	if (!inTims) {
		return;
	}

	if (bail && (hasTimsCard > 0)) {
		hasTimsCard--;
	} else if (bail) {
		removeMoney(50);
	}
	inTims = false;
}

int Player::getTimsCards() {
	return hasTimsCard;
}

bool Player::getInTims() {
	return inTims;
}

int Player::getTurnsInTims() {
	return turnsInTims;
}

void Player::addMoney(int amount) {
	money += amount;
} 

void Player::removeMoney(int amount) {
	if (amount > money) {
		throw BankruptException(amount - money, nullptr);
	}
	money -= amount;
}

int Player::getNetWorth () {
	updateNetWorth();
	return netWorth;
}

int Player::getPosition() const {
	return position;
}

void Player::move(int amount) {
	if (position + amount < 0) {
		position = position + amount + 40;
	}

	if (position + amount >= 40) {
		money += 200;
	}

	position = (position + amount) % 40;
}

void Player::moveTo(int pos) {
	position = pos;
}

bool Player::allPropertiesAreMortgaged() {
	
	bool mortgaged = true;
	for (auto it = owned.begin(); it != owned.end(); ++it) {
		mortgaged = mortgaged && (*it)->is_mortgaged();
	}

	return mortgaged;

}

void Player::buy(Property * p) {
	if (p->getPrice() > money){
		throw "Not enough money";
	}
	removeMoney(p->getPrice());
	owned.push_back(p);
}

void Player::pay(std::shared_ptr<Player> other, int amount) {
	if (amount > money) {
		throw BankruptException(amount - money, other);
	} else {
		removeMoney(amount);
		other->money += amount;
	}
}

void Player::trade(std::shared_ptr<Player> other, int money, Property* others) {

	auto it = find(other->owned.begin(), other->owned.end(), others);

	if (money > this->money) { // "Checking if the current player has enough money for the trade"
		//"Throw some exception to disallow this trade"
	} else if (it == other->owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	} else {
		pay(other, money);
		owned.push_back(others);
		other->owned.erase(it);

		others->setOwner(this);
	}
}

void Player::trade(std::shared_ptr<Player> other, Property* mine, int money) {
	auto it = find(owned.begin(), owned.end(), mine);

	if (money > other->money) { // "Checking if the current player has enough money for the trade"
		//"Throw some exception to disallow this trade"
	} else if (it == owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	} else {
		other->removeMoney(money);
		this->money += money;
		other->owned.push_back(*it);
		owned.erase(it);

		mine->setOwner(other);
	}
}

void Player::trade(std::shared_ptr<Player> other, Property* mine, Property* others) {
	
	auto first = find(owned.begin(), owned.end(), mine);
	auto second = find(other->owned.begin(), other->owned.end(), others);

	//std::cout << "    " << mine->getName() << ", " << others->getName() << std::endl;

	if (first == owned.end()) {
		//"Throw some exception, since this player does not have the property to trade"
//		std::cout << "First = ownded.end()" << std::endl;
	} else if (second == other->owned.end()) {
		//"Throw some exception, since other player does own its property ro trade"
//		std::cout << "Second = other->owned.end()" << std::endl;
	} else {
	
	//	std::cout << (*first)->getName() << ", " << (*second)->getName() << std::endl;

		owned.push_back(others);
		other->owned.push_back(mine);

		for (auto it = owned.begin(); it != owned.end(); ++it) {
			if (*it == mine) {
				owned.erase(it);
				break;
			}
		}

		for (auto it = other->owned.begin(); it != other->owned.end(); ++it) {
			if (*it == others) {
				other->owned.erase(it);
			}
		}

		mine->setOwner(other);
		others->setOwner(this);

		//owned.erase(first);
		//other->owned.erase(second);

	}

}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::setPlayerChar(char playerChar) {
	this->playerChar = playerChar;
}

void Player::setMoney(int money) {
	this->money = money;
}

void Player::setPosition(int position) {
	this->position = position;
}

void Player::setTimsCups(int timsCups) {
	this->hasTimsCard = timsCups;
}

void Player::setInTims(bool inTims) {
	this->inTims = inTims;
}

void Player::setTurnsInTims(int turnsInTims) {
	this->turnsInTims = turnsInTims;
}

void Player::addProperty(Property *property) {
	(this->owned).push_back(property);
}



