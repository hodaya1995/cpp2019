/*Hodaya Tabibian 313418923*/
/*Guy Fadida  204289599*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <iostream>
class Game {
	
private:
	Game(const Game& game); //copy constructor
	Game& operator=(const Game& game); //operator=
public:

	 Game(){};
	void start();
};

#endif




