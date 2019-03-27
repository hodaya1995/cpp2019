a: main.o Game.o Card.o Player.o
	g++ -std=c++11 -o a main.o Game.o Card.o Player.o
main.o: main.cpp Game.h
	g++ -std=c++11 -c main.cpp
Game.o: Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp
Card.o: Card.cpp Card.h
	g++ -std=c++11 -c Card.cpp
Player.o: Player.cpp Player.h
	g++ -std=c++11 -c Player.cpp

clean:
	rm a main.o Game.o Card.o Player.o