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
  const vector<Card>& cardsTemp=this->get_cards();
  cout<<"current: "<<currCard<<endl;
  cout<<Player::get_name()<<" its your turn"<<endl;
  cout<<"your cards:";
  

  int counter=1;
  vector<Card>::const_iterator iter = get_cards().cbegin();
   decltype(get_cards().cend()) end_iter = get_cards().cend();
    while (iter != end_iter) { 
    cout <<"("<<counter<<")"<<*iter<<"  ";
    counter++;
    ++iter;
    }
    cout<<endl;

  int choice;
  cin>> choice;

  if(choice<=0||choice>get_cards_number()){
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
           vector<Card> cardsVec=get_cards();
           cardsVec.erase (cardsVec.begin()+choice-1);
           set_cards(cardsVec);

           cardNum--;

          

      }
      
      
      
      else{ //is not legal
      cout<<"you can't put "<<c<<" on: "<<currCard<<endl<<flush;
        turnsToSkip=0;
      }
    
  }
  return true;
}


