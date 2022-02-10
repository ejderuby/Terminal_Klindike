// Card Header File

#ifndef CARD_H
#define CARD_H

class Card{
  private:
    char suit;
    int value;
    char color;
    int conceal;
    Card* next;
    Card* prev;
  public:
    Card(); // Default Constructor
    ~Card(); // Destructor
    
    // Methods
    void displayCard();
    void assignCardFace(int index);
    void flipOver();
    char toCharValue();
    // Getters
    char getSuit();
    int getValue();
    char getColor();
    int getConceal();
    Card* getNext();
    Card* getPrev();
    // Setters
    void setSuit(char suit);
    void setValue(int value);
    void setColor(char color);
    void setConceal(int conceal);
    void setNext(Card* card);
    void setPrev(Card* card);
};

#endif // CARD_H
