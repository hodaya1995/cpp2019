#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Player {

//=direction::left;

private:
	string name;// name;
	int cardNum;// num_of_cards;
	vector<Card> cards;// container of cards
	int turnsToSkip;


public:
    Player(string name, int cardNum);
	Player(const Player& player) : name{player.name}, cardNum{player.cardNum} ,cards{player.cards}{}; //copy constructor
	Player(Player&& player) : name{player.name}, cardNum{player.cardNum} ,cards{player.cards}{}; //copy constructor
	Player& operator=(Player&& player) {
		name = player.name;
		 cardNum = player.cardNum;
		 cards=player.cards;
		  return *this;
		};
    Player& operator=(const Player& player) {
		name = player.name;
		 cardNum = player.cardNum;
		 cards=player.cards;
		  return *this;
		}; 

	const string& get_name()const{return name;};
	string get_name(){return name;};
	int get_cards_number()  {return cardNum;};
	int get_turnsToSkip() {return turnsToSkip;};
	vector<Card>& get_cards(){return cards;};
    void set_cards(vector<Card>& c){cards=move(c);};
	void set_cards_number(int number){cardNum=number;};
	void set_turnsToSkip(int turnsToSkip){turnsToSkip=turnsToSkip;};
    bool play(Card& currCard);
};
enum class direction { right,left };	
extern direction currDirection;
#endif



