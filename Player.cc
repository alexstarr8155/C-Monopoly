#include <algorithm>
#include <iostream>
#include "Player.h"
#include "Improvable.h"
#include "BankruptException.h"

// the initial construction of the Player class
Player::Player (const std::string &name, char playerChar, int money) : name{name}, playerChar{playerChar}, money{money}, netWorth{money} {
	position = 0;
}

// player is in DC Tims Line (aka jail)
void Player::goToTims() {
	inTims = true;	
}

// player is out of DC Tims Line (aka jail)
void Player::getOutOfTims(bool bail) {

	if (!inTims) {
		return;
	}

	if (bail && (hasTimsCard > 0)) {
		hasTimsCard--;
	}
	else if (bail) {
		removeMoney(50);
	}
	inTims = false;
}

// increases the number of Tims Cards that the player has by 1
void Player::addTimsCard (){
	hasTimsCard++;
}

// increases the player's available money by the value of 'amount'
void Player::addMoney(int amount) {
	money += amount;
}

// decreases the player's available money by the value of 'amount'
// if player does not have enough money to withdraw will thrown an exception
void Player::removeMoney(int amount) {
	if (amount > money) {
		throw BankruptException(amount, nullptr);
	}
	money -= amount;
}

// updates the Net Worth of Player
void Player::updateNetWorth() {
	int worth = 0;

	for (unsigned i = 0; i < owned.size(); i++) {
		worth += owned[i]->getValue();
	}
	netWorth = worth + money;
}

// updates the player's position on the board by the value of 'amount'
// if player pass the Collect Osap Tile in board increases the player's available money by $200
void Player::move(int amount) {
	if (position + amount < 0) {
		position = position + amount + 40;
	}

	if (position + amount >= 40) {
		money += 200;
	}

	position = (position + amount) % 40;
}

// will move the player to a specific part of the board (dependent on 'pos')
void Player::moveTo(int pos) {
	position = pos;
}

// returns a bool representing if all the properties owned by player are mortgaged
bool Player::allPropertiesAreMortgaged() {
	
	bool mortgaged = true;
	for (auto it = owned.begin(); it != owned.end(); ++it) {
		mortgaged = mortgaged && (*it)->is_mortgaged();
	}

	return mortgaged;
}

// will check if the player is able to buy the property
// if not will throw an exception
// if they are will update the vector representing the properties that the player owns
void Player::buy(Property * p) {
	if (p->getPrice() > money){
		throw "Not enough money";
	}
	removeMoney(p->getPrice());
	owned.push_back(p);
}

// player will attempt to pay 'other' the value of 'amount'
// if they cannot will throw an exception
void Player::pay(std::shared_ptr<Player> other, int amount) {
	if (amount > money) {
		throw BankruptException(amount - money, other);
	}
	else {
		removeMoney(amount);
		other->money += amount;
	}
}

void Player::trade(std::shared_ptr<Player> other, int money, Property* others) {

	auto it = find(other->owned.begin(), other->owned.end(), others);

	if (money > this->money) { // "Checking if the current player has enough money for the trade"
		//"Throw some exception to disallow this trade"
	}
	else if (it == other->owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	}
	else {
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
	}
	else if (it == owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	}
	else {
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

	if (first == owned.end()) {
		//"Throw some exception, since this player does not have the property to trade"
//		std::cout << "First = ownded.end()" << std::endl;
	}
	else if (second == other->owned.end()) {
		//"Throw some exception, since other player does own its property ro trade"
//		std::cout << "Second = other->owned.end()" << std::endl;
	}
	else {
	
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

// set the name member of player
void Player::setName(std::string name) {
	this->name = name;
}

// set the playerChar member of player
void Player::setPlayerChar(char playerChar) {
	this->playerChar = playerChar;
}

// set the money member of player
void Player::setMoney(int money) {
	this->money = money;
}

// set the position member of player
void Player::setPosition(int position) {
	this->position = position;
}

// set the hasTimsCard member of player
void Player::setTimsCups(int timsCups) {
	this->hasTimsCard = timsCups;
}

// set the inTims member of player
void Player::setInTims(bool inTims) {
	this->inTims = inTims;
}

// set the turnsInTims member of player
void Player::setTurnsInTims(int turnsInTims) {
	this->turnsInTims = turnsInTims;
}

// adds a property to the owned memeber of player
void Player::addProperty(Property *property) {
	(this->owned).push_back(property);
}

// returns the player's name
std::string Player::getPlayerName() const {
	return name;
}

// returns the player's character
char Player::getPlayerChar() const {
	//std::cout << "A" << std::endl;
	//std::cout << name << std::endl;
	return playerChar;
}

// returns the player's avaliable money
int Player::getMoney() const {
	return money;
}

// returns the player's current position
int Player::getPosition() const {
	return position;
}

// updates the player's net worth and then returns it
int Player::getNetWorth () {
	updateNetWorth();
	return netWorth;
}

// returns the number of Tims Cards that the player has
int Player::getTimsCards() {
	return hasTimsCard;
}

// returns if player is in DC Tims Line (aka jail) or not
bool Player::getInTims() {
	return inTims;
}

// returns the number of turns that player has been in jail
int Player::getTurnsInTims() {
	return turnsInTims;
}

// returns a vector of properties that the player owns
std::vector<Property *> Player::getProperties() const{
	return owned;
}
