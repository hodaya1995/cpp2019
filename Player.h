/*Hodaya Tabibian 313418923*/
/*Guy Fadida  204289599*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Player {
private:
	string name;// name;
	int cardNum;// num_of_cards;
	vector<Card> cards;// container of cards
	int turnsToSkip;


public:

  Player(string name, int cardNum);
	Player(const Player& player) : name{player.name}, cardNum{player.cardNum} ,cards{player.cards}{}; //copy constructor

    Player& operator=(const Player& player) {
		name = player.name;
		 cardNum = player.cardNum;
		 cards=player.cards;
		  return *this;
		}; 

	const string get_name()const{return name;};
	string get_name(){return name;};
	int get_cards_number() const {return cardNum;};
	int get_turnsToSkip() const {return turnsToSkip;};
	vector<Card> get_cards() const {return cards;};
    void set_cards(const vector<Card>& c){cards=move(c);};
	void set_cards_number(const int number){cardNum=number;};
	void set_turnsToSkip(const int turns){turnsToSkip=turns;};
    bool play(Card& currCard);
};
enum class direction { right,left };	
extern direction currDirection;
#endif



