#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
direction currDirection=direction::left;

Player::Player(string name, int cardNum): name{name}, cardNum{cardNum} {
    for(int i=0;i<cardNum;++i)this->cards.push_back(Card::generate_card());
};


bool Player::play(Card& currCard){
  const vector<Card>& cardsTemp=cards;
  cout<<"current: "<<currCard<<endl;
  cout<<Player::get_name()<<" its your turn"<<endl;
  cout<<"your cards:";
  

  int counter=1;
  vector<Card>::const_iterator iter = cards.cbegin();
   decltype(cards.cend()) end_iter = cards.cend();
    while (iter != end_iter) { 
    cout <<"("<<counter<<")"<<*iter<<"  ";
    counter++;
    ++iter;
    }
    cout<<endl;

  int choice;
  cin>> choice;

  if(choice<=0||choice>cardNum){
      cards.push_back(Card::generate_card());
       turnsToSkip=1;
       cardNum++;
      return false;
  }
  else{
     Card card=cards.at(choice-1);
      const Card& c=card;
      if(currCard.is_legal(c)){

        if(card.get_sign()== sign::PLUS){
            turnsToSkip=0;
        }else if(card.get_sign()== sign::CD){
           turnsToSkip=1;
            if(currDirection==direction::right)currDirection=direction::left;
            else                               currDirection=direction::right; 
        }else if(card.get_sign()== sign::STOP){
            turnsToSkip=2;
        }else{
           turnsToSkip=1;
        }
        


           currCard=card;
           cards.erase (cards.begin()+choice-1);
           cardNum--;

          

      }
      
      
      
      else{ //is not legal
      cout<<"you can't put "<<c<<" on: "<<currCard<<endl<<flush;
        turnsToSkip=0;
      }
    
  }
  return true;
}


