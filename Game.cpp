#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;

void Game::start(){
    bool isOver=false;
    int playersNum;
    int cardsNum;
    vector<Player> players;


    cout<<"how many players?"<<endl;
    cin>>playersNum;
    if(!(playersNum>0)){
        cout<<"invalid number,exiting"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"how many cards?"<<endl;
    cin>>cardsNum;
    if(!(cardsNum>0)){
        cout<<"invalid number,exiting"<<endl;
        exit(EXIT_FAILURE);
    }

    for(int i=1;i<=playersNum;++i){
        string name;
        cout<<"player number "<<i<<" name?"<<endl;
        cin>>name;
        players.push_back(Player(name,cardsNum));
    }


    Card randomCard=Card::generate_card();
    Card& currCard=randomCard;
   int j=0;
    while(!isOver){

            bool isPlayed=(players.at(j)).play(currCard);

           if((players.at(j)).get_cards_number()==0){
                cout<<(players.at(j)).get_name()<<" wins!"<<endl;
                isOver=true;
            }
            if(currDirection==direction::right){
                if(!isPlayed){
                  j--;
                } 
                else{
                    int index=(players.at(j)).get_turnsToSkip();
                  if((players.at(j)).get_turnsToSkip()!=0)for(int i=0;i<index;++i){
                      j--;
                   }
                 
                }
               
              j=j%(players.size());
             }
             else if(currDirection==direction::left){
                 if(!isPlayed){
                   j++;
                 }
                 else{
                     int index=(players.at(j)).get_turnsToSkip();
                   if((players.at(j)).get_turnsToSkip()!=0)for(int i=0;i<index;++i){
                    j++; 
                   } 
                 }

                  j=j%(players.size());
                
             }
        

             
    }
 

}