// Card.cpp

#include <iostream>
#include "Card.h"

// Default Constructor
Card::Card(){
  suit = ' ';
  value = 0;
  color = ' ';
  conceal = 1;
  prev = 0;
  next = 0;
}


// Destructor
Card::~Card(){
  
}


void Card::displayCard(){
  if (getConceal() == 1) // If card is concealed, display card as three X's
    std::cout << "X X X";
  else 
    std::cout << Card::getSuit() << " " << Card::toCharValue() << " " << Card::getColor();
} // end displayCard


void Card::assignCardFace(int index){ // set correct suit, value, and color
  // Set card's suit and color
  if (index/13 == 0){
    setSuit('S');  // Spade
    setColor('B'); // Black
  } else if (index/13 == 1){
    setSuit('H');  // Heart
    setColor('R'); // Red
  } else if (index/13 == 2){
    setSuit('C');  // Club
    setColor('B'); // Black
  } else if (index/13 == 3){
    setSuit('D');  // Diamond
    setColor('R'); // Red
  } // end else if

  // Set card's value
  setValue(index%13);
} // end assignCardFace


char Card::toCharValue(){
  char charValue;
  int value = (getValue() + 1)%13; // get value 1 to 13

  if (value == 1) // value 1 is an Ace
    charValue = 'A'; 
  if (value <= 9 && value >= 2) // if value from 2 to 9
    charValue = value + '0'; // converts value to char by adding char '0'
  if (value == 10) 
    charValue = 'T'; // 10: Ten
  if (value == 11)
    charValue = 'J'; // 11: Jack
  if (value == 12)
    charValue = 'Q'; // 12: Queen
  if (value == 0) // 13%13 == 0
    charValue = 'K'; // 13: King

  return charValue;
} // end valueToChar


void Card::flipOver(){
  if (getConceal() == 1)
    setConceal(0);
  // No need to conceal cards again
} // end flipOver


// Getters
char Card::getSuit(){
  return suit;
}

int Card::getValue(){
  return value;
}

char Card::getColor(){
  return color;
}

int Card::getConceal(){
  return conceal;
}

Card* Card::getNext(){
  return next;
}

Card* Card::getPrev(){
  return prev;
}


// Setters
void Card::setSuit(char suit){
  Card::suit = suit;
}

void Card::setValue(int value){
  Card::value = value;
}

void Card::setColor(char color){
  Card::color = color;
}

void Card::setConceal(int conceal){
  Card::conceal = conceal;
}

void Card::setNext(Card* next){
  Card::next = next;
}

void Card::setPrev(Card* prev){
  Card::prev = prev;
}


