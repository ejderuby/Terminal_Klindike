// Deck.cpp

#include <stdlib.h>
#include <time.h>
#include "Deck.h"
#include "Card.h"

// Default Constructor
Deck::Deck(){
  for (int i = 0; i < 52; i++) {
    c[i] = new Card;
    c[i]->assignCardFace(i);
  }
}


// Destructor
Deck::~Deck(){
  for(int i = 0; i < 52; i++){
    delete c[i];
  }
}


void Deck::shuffle(){
  srand(time(0));
  Card* temp;
  
  for (int i = 0; i <= 1500; i++){ // run loop 1000 times to shuffle deck fully
    int randNum1 = rand()%52; // First random card
    int randNum2 = rand()%52; // Second random card
    
    // swap first and second card
    temp = c[randNum1];
    c[randNum1] = c[randNum2];
    c[randNum2] = temp;
  } // end for

} // end shuffle


