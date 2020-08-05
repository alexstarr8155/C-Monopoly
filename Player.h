#ifndef PLAYER_H
#define PLAYER_H

#include "Subject.h"
#include <string>

class Property

class Player : public Subject {

private:
	int playerNum;
	int netWorth;
	int money;	
	std::string name;
	std::vector<std::shared_ptr<Property>> owned;
public:
	int getPlayerNum();
	std::string getPlayerName();
	int getMoney();
	std::vector<std::shared_ptr<Property>> getProperties();
	void updateNetWorth();
	void buy(std::shared_ptr<Property> p);
	void pay(std::shared_ptr<Player> other, int amount);
	void trade(std::shared_ptr<Player> other, std::shared_ptr<Property> mine, std::shared_ptr<Property> others);
	void trade(std::shared_ptr<Player> other, std::shared_ptr<Property> mine, int money);
	void trade(std::shared_ptr<Player> other, int money, std::shared_ptr<Property> others);

};

#endif
