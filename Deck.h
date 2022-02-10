// Deck Header File

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
  public:
    Card* c[52];
    Deck(); // Default Constructor
    ~Deck(); // Destructor

    // Methods
    void shuffle();
};

#endif // DECK_H
