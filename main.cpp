// Klondike main.cpp

#include <iostream>
#include <string>
#include <algorithm> // max_element()
#include "Card.h"
#include "Deck.h"

using namespace std;

//Card* dealCol(Deck deck, Card* colHead[7]);
//Card* dealRemaining(Deck deck, Card* remainingHead);

void dealGame(Deck deck, Card* colHead[7], Card* remainingHead, Card* foundationHead[4]);
void displayWaste(Card* remainingHead);
void displayColumns(Card* colHead[7]);
void displayFoundations(Card* foundationHead[4]);
void displayMenu();
void displayGame(Card* colHead[7], Card* remainingHead,
    Card* foundationHead[4]);

Card* addCards(Card* head, Card* c);
void moveCardsCol2Col(Card* headFrom, Card* headTo, int cardNum);

Card* findCard(Card* head, int cardNum);
int findLength(Card* head);
int findLongestLen(Card* head[]);


int main(){
  Deck deck;
  deck.shuffle();
  
  // Columns
  Card* colHead[7];
    for (int i = 0; i < 7; i++) 
      colHead[i] = new Card;
  
  // Cards Remaining
  Card* remainingHead;
  remainingHead = new Card;

  // Foundations
  Card* foundationHead[4];
  for (int i = 0; i < 4; i++)
    foundationHead[i] = new Card;

  // Deal the game
  //remainingHead = dealRemaining(deck, remainingHead);
  dealGame(deck, colHead, remainingHead, foundationHead);

  



  return 0;
} // end main

void dealGame(Deck deck, Card* colHead[7], Card* remainingHead, Card* foundationHead[4]){
  int index = 0;
  // 1 card in 1st col, 2 in 2nd, etc.
  for (int i = 0; i < 7; i++){
    for (int j = 0; j <= i; j++){
      colHead[i] = addCards(colHead[i], deck.c[index]);
      index++;
    } // end for
  } // end for

  for (; index < 52; index++){
    remainingHead = addCards(remainingHead, deck.c[index]);
  } // end for
  
  displayGame(colHead, remainingHead, foundationHead);
} // end dealGame


void displayGame(Card* colHead[7], Card* remainingHead, Card* foundationHead[4]){
/* Displays the game */

  displayWaste(remainingHead);
  displayColumns(colHead);
  displayFoundations(foundationHead);
  displayMenu();

} // end displayGame


void displayWaste(Card* remainingHead){
  // Display waste and how many cards are left in it
  int wasteLen = findLength(remainingHead);
  cout << "Waste [" << wasteLen  << "]: ";
  
  cout << endl;
} // end displayWaste


void displayColumns(Card* colHead[7]){
  // List column numbers
  cout << "col   ";
  for (int i = 1; i <= 6; i++){
    cout << i << "       "; 
  } // end for
  cout << "7    row" << endl;

  Card* current;
  int maxLen = findLongestLen(colHead);
  for (int p = 0; p < maxLen; p++){ // maxLen is number of rows displayed
    cout << "    ";
    for (int q = 0; q < 7; q++){
      current = colHead[q];
      current = current->getNext();

      for (int x = 0; x <= p; x++){
        // if on 1st row, display 1st card in each list
        // 2nd row, 2nd card in list, and so on
        if (x == p){
          if (current != 0){
            if (current->getNext() == 0)
              current->flipOver(); // flip over last card in each list
            current->displayCard();
            cout << "   ";
          } else {
            cout << "        ";
          } // end else if
        } // end if
        if (current != 0){
          current = current->getNext();
        } // end if
      } // end for
    } // end for

    cout << (p + 1) << endl; // List row numbers
  } // end for
} // end displayColumns


void displayFoundations(Card* foundationHead[4]){
  cout << "| Spades  | Hearts  |  Clubs  | Diamonds|" << endl;
  Card* current;
  int maxLen = findLongestLen(foundationHead);
  for (int i = 0; i < maxLen; i++){ // maxLen is number of rows
    cout << "  ";
    for (int j = 0; j < maxLen; j++){
      current = foundationHead[j];
      current = current->getNext();

      for (int k = 0; k <= i; k++){
        // if on 1st row, display 1st card in each list
        // 2nd row, 2nd card in list, and so on
        if (k == i){ 
          if (current != 0){
            current->displayCard();
            cout << "   ";
          } else {
            cout << "          ";
          } // end if else
        } // end if
      } // end for
    } // end for
    cout << endl;
  } // end for
} // end displayFoundations


void displayMenu(){
  cout << "Options: " << endl;
  cout << "(Z) Draw from Waste" << endl;
  cout << "(X) Move card from the Waste" << endl;
  cout << "(C) Move card(s) between columns" << endl;
  cout << "(V) Move card to a foundation" << endl;
  cout << "(B) Move card from a foundation" << endl;
  cout << "Make a selection: ";
} // end displayMenu


void moveCardsCol2Col(Card* headFrom, Card* headTo, int cardNum){
  Card* currentFrom;
  Card* currentTo;
  
  currentFrom = findCard(headFrom, cardNum);
  headTo = addCards(headTo, currentFrom);
} // end moveCards


Card* addCards(Card* head, Card* c){
/* Add card to a linked list
 * addCard(list to be added to, card being added) 
 * Place the card at the end of the list and set next and prev pointers */
  Card* current;
  current = head;

  int keepgoing = 1;
  while (keepgoing){
    // Set next of last node, set prev of added node
    if (current->getNext() == 0){
      current->setNext(c);
      c->setPrev(current);
      keepgoing = 0;
    } // end if

    current = current->getNext();
  } // end for

  return head;
} // end addCard


Card* findCard(Card* head, int cardNum){
/* Find a certain card in a list */
  Card* current;
  current = head;
  current = current->getNext();
  
  // Traverse the list
  int i = 1;
  while (1){
    if (i == cardNum)
      return current;

    current = current->getNext();
    i++;
  } // end for

  return 0;
} // end findCard


int findLength(Card* head){
/* Returns the length of a linked list */
  Card* current;
  
  int count = 0;
  for (current = head->getNext(); current != 0; current = current->getNext()){
    count++;
  } // end for

  return count;
}


int findLongestLen(Card* head[]){
/* Returns length of the longest colHead[] */
  int len[7];
  int keepgoing = 1;

  for (int i = 0; i < 7; i++){
    len[i] = findLength(head[i]);
  } // end for
  
  int max;
  max = *max_element(len, (len + 7));
  return max;
} // end findLongestCol


