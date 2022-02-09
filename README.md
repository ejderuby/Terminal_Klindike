# Terminal_Klindike - Practice: C++, OOP

In this project, the goal is to create the classic game of Klondike solitaire using C++, played in the Terminal. It uses Object Oriented Programming (OOP) and linked lists for each stack of cards on the playing table, the remaining cards, and the four foundations.
* It will have a start screen to load the previous saved game or start a new one. 
* Each card will be an object in a linked list.
* Each card will have one suit (S, H, C, D), color (R, B), and value (A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2). 
* Linked lists will be used for each of the 7 stacks on the playing table, one for each of the 4 foundation piles, one for the cards to be dealt, and one for the waste pile where the top card is playable. 
* The game has seven columns of cards to play with, with only the top card initially “flipped over”.
* Four foundation piles, one for each suit. The goal of the game is to fill all of these stacks one card consecutively on the other of the same suit from ace to king. 
* The game will present three cards at a time, and only the top one is playable. 
* The game will allow the user to move any amount of cards on the playing field that are in a row consecutively from high to low and alternating red and black and put it on another card that is valid on the playing field. 
* Game congratulates the user when the user has won.

## UI Display
```
Waste [24]: 
col   1       2       3       4       5       6       7    row
    S B Q   X X X   X X X   X X X   X X X   X X X   X X X   1
            S B 2   X X X   X X X   X X X   X X X   X X X   2
	            H R 5   X X X   X X X   X X X   X X X   3
		  	    D R A   X X X   X X X   X X X   4
				    C B 4   X X X   X X X   5
					    H R 9   X X X   6
						    C B J   7

| Spades  | Hearts |  Clubs  | Diamonds|



Options:
(Z) Draw from waste
(X) Move card from the waste
(C) Move card(s) between columns
(V) Move card to a foundation
(B) Move card from a foundation
Make a selection: 
```

## Move options
Draw from waste: displays next three cards from the waste linked list.
Move card from the waste: selects the top card on the waste pile that is displayed and asks user where they want to place it. 
Move card(s) between columns: Asks user for column then the row to move from, then the column where they want to place it. 
Move card to a foundation: Asks user for the column the card to be moved from, then places the last card in the correct foundation because you can’t move a middle card, nor could you move more than one card at once to a foundation.
Move card from a foundation: Asks user which foundation to be moved from, then what column to place the card on. 
 
## Algorithm
###### Objects:
###### Card
Private:
  * `char suit`
  * `int value`
  * `char color`
  * `int conceal`
  * `Card* next`
  * `Card* prev`
  
Public:
  * Constructor: `Card();` - Creates a default card object with all the properties above. All ints and pointers equal 0, and chars equal a ASCII space character in single quotes.
  * Destructor: `~Card();`
  * `void displayCard();` - If the card is concealed, print “X X X”. Otherwise, use getSuit, toCharValue, and getColor to print the card.
  * `void assignCardFace(int index);` - Uses the index (0 to 52) to assign the suit, color, and value of int from 0 to 12
  * `void flipOver();` - changes conceal from 1 to 0 so that displayCard will print the card
  * `char toCharValue();` - changes the int value from 0 to 12 to a char value of A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, or K.
  * getters and setters for private properties

###### Deck
Public:
  * `Card* c[52]`
  * Constructor: `Deck();`
  * Destructor: `~Deck();` - deletes 52 Card pointers to objects
  * `shuffle();` - This function uses srand(time(0)) to get two random numbers from 0 to 51 and switches the two of them. It also used a for loop to do this 1500 times.

## Main
Main creates a deck object and shuffles it, and creates all the pointers to heads of linked lists (7 columns, waste, and 4 foundations: 12 linked lists total. The columns and foundations are in an array.

###### Functions in main
To deal the game:
* `Card* dealCol(Deck deck, Card* colHead[7]);` - Uses a nested for loop to assign and add cards from the deck to the correct column head. Used the add cards function.
* `Card* dealRemaining(Deck deck, Card* remainingHead);` - Attatches remaining cards in deck to remainingHead using the add cards function.
* `void dealGame(Deck deck, Card* colHead[7], Card* remainingHead, Card* foundationHead());` - Uses a nested for loop to assign and add cards from the deck to the correct column head. Used the add cards function. Uses another for loop to add remaining cards to remaining head using add cards. Uses an index starting at 0 to find how many cards have been added to any list in this function, that way when it knows where to start adding the remaining cards. 

To display the game:
* `void displayWaste(Card* remainingHead);`
* `void displayColumns(Card* colHead[7]);` - Uses a nested for loop nested in another for loop. To display only the last card, the program checks that the next pointer points to nothing, then uses the flip over function on that card.
* `void displayFoundations(Card* foundationHead[4]);` - Similar to the display columns function, but it’s not necessary to flip over any cards.
* `void displayMenu();` - Simply displays the menu of playing options.
* `void displayGame(Card* colHead[7], Card* remainingHead, Card* foundationHead[4]);` - Calls all four previous display functions to display full game

To move cards around:
* `Card* addCards(Card* head, Card* c);` - Add card to a linked list. addCard(list to be added to, card being added) Place the card at the end of the list and set next and prev pointers.
* `void moveCardsCol2Col(Card* headFrom, Card* headTo, int cardNum);` - cardNum is the row that the user selected, and it uses findCard() with headFrom and cardNum to return the card that needs to be moved. Then it uses addCards() with headTo and what card it got from findCard() to move the cards.
* `Card* findCard(Card* head, int cardNum);` - To find a certain card in a linked list
* `int findLength(Card* head);`  - To find the number of nodes in a linked list
* `int findLongestLen(Card* head[]);` - To find how long the longest linked list is in an array of linked lists. This is used to find how many times a for loop should run to display every card in the columns and foundations. 

###### Data Design
This program uses 12 linked lists and an array of card objects:
* `column [7]`
* `remaining [1]`
* `foundation [4]`
* `c [52]` - An array of 52 cards that’s the deck. This is where the cards are actually located.

For example, if an unshuffled deck were used, then cards would be assigned to lists in this order at the beginning of the game:
```
column[0] SBA column 1, card 1
column[1] SB1 column 2, card 1
column[2] SB2 column 3, card 1
column[3] SB3 column 4, card 1
column[4] SB4 column 5, card 1
column[5] SB5 column 6, card 1
column[6] SB6 column 7, card 1
column[1] SB7 column 2, card 2 (notice it skips column 1 this time)
column[2] SB8 column 3, card 2
column[3] SB9 column 4, card 2
column[4] SBT column 5, card 2
column[5] SBJ column 6, card 2
column[6] SBQ column 7, card 2
column[2] SBK column 3, card 3 (skips 1 and 2)
column[3] HRA column 4, card 3
column[4] HR1 column 5, card 3
column[5] HR2 column 6, card 3
column[6] HR3 column 7, card 3
	        .
	        .
	        .
column[5] HRQ column 6, card 6
column[6] HRK column 7, card 6
column[6] CBA column 7, card 7
remaining[] CB2 remaining card 1 (when columns are full, move on to filling the remaining cards list)
remaining[] CB3 remaining card 2
remaining[] CB4 remaining card 3
                .
	        .
	        .
```

From above, play table uncovered:
```
S B A   S B 1   S B 2   S B 3   S B 4   S B 5   S B 6   1
        S B 7   S B 8   S B 9   S B T   S B J   S B Q   2
                S B K   H R A   H R 2   H R 3   H R 4   3
                        H R 5   H R 6   H R 7   H R 8   4
                                H R 9   H R T   H R J   5
                                        H R Q   H R K   6
                                                C B A   7
```

For or while loops using keepgoing were used to traverse the lists with current pointers. 


