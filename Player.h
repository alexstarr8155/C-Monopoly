#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <map>
#include <vector>
#include <string>

class Property;

/* this class represents each player in the game */

class Player {

	private:
		std::string name; // represents the name
		char playerChar; // represents the player's character ($, T, G, etc)
		int money; // represents the player's available money
		int position; // represents the player's position on the board
		int netWorth; // represents the player's net worth
		int hasTimsCard = 0; // represents the number of Tims cards the player has
		bool inTims = false; // represents if the plyaer in DC Tims Line (aka jail)
		int turnsInTims = 0; // represents the number of turns player has been in DC Tims Line (aka jail)
		std::vector<Property *> owned; // represents the properites owned by the player
	
	public:
		Player(const std::string &name, char playerChar, int money);

		void goToTims();
		void getOutOfTims(bool b);
		void addTimsCard();
		void addMoney(int amount);
		void removeMoney(int amount);
		void updateNetWorth();
		void move(int amount);
		void moveTo(int pos);
		bool allPropertiesAreMortgaged();

		void buy(Property *p);
		void pay(std::shared_ptr<Player> other, int amount);
		void trade(std::shared_ptr<Player> other, Property* mine, Property* others);
		void trade(std::shared_ptr<Player> other, Property* mine, int money);
		void trade(std::shared_ptr<Player> other, int money, Property* others);

		void setName(std::string name);
		void setPlayerChar(char playerChar);
		void setMoney(int money);
		void setPosition(int position);
		void setTimsCups(int timsCups);
		void setInTims(bool inTims);
		void setTurnsInTims(int turnsInTims);
		void addProperty(Property *property);

		std::string getPlayerName() const;
		char getPlayerChar() const;
		int getMoney() const;
		int getPosition() const;
		int getNetWorth();
		int getTimsCards();
		bool getInTims();
		int getTurnsInTims();
		std::vector<Property *> getProperties() const;
};

#endif
