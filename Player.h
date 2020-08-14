#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <map>
#include <vector>
#include <string>

class Property;

class Player {

private:
	int position;
	char playerChar;
	int netWorth;
	int money;
	bool inTims = false;
	int turnsInTims = 0; // will have to add this to jail time
	int hasTimsCard = 0;	
	std::string name;
	std::vector<Property *> owned;
public:
	Player (const std::string &name, char playerChar, int money);

	char getPlayerChar() const;
	std::string getPlayerName() const;
	int getMoney() const;
	std::vector<Property *> getProperties() const;
	
	void goToTims();
	void getOutOfTims(bool b);
	int getTimsCards();
	bool getInTims();
	int getTurnsInTims();

	void addMoney(int amount);
	void removeMoney(int amount);

	void updateNetWorth();
	int getNetWorth () const;
	int getPosition() const;
	void move(int amount);
	void moveTo(int pos);

	void buy(Property *p);
	void pay(std::shared_ptr<Player> other, int amount);
	void trade(std::shared_ptr<Player> other, Property* mine, Property* others);
	void trade(std::shared_ptr<Player> other, Property* mine, int money);
	void trade(std::shared_ptr<Player> other, int money, Property* others);

};

#endif
