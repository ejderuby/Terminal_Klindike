Klondike: Card.o Deck.o main.o
	g++ Card.o Deck.o main.o -o Klondike
Card.o: Card.cpp Card.h
	g++ -c Card.cpp
Deck.o: Deck.cpp Deck.h
	g++ -c Deck.cpp
main.o: main.cpp Card.h Deck.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm Klondike
run: Klondike
	./Klondike
