a: main.o Game.o Card.o Player.o
	g++ -o a main.o Game.o Card.o Player.o
main.o: main.cpp Game.h
	g++ -c main.cpp
Game.o: Game.cpp Game.h
	g++ -c Game.cpp
Card.o: Card.cpp Card.h
	g++ -c Card.cpp
Player.o: Player.cpp Player.h
	g++ -c Player.cpp

clean:
	rm a main.o Game.o Card.o Player.o