#include "DeckOfCards.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int chooseMenu();
// Comment 10: We need to pass DeckOfCards object by reference, otherwise no
// change is made to it.
void dealAndDisplay(DeckOfCards &, int);

int main() {
  DeckOfCards myDeck = DeckOfCards();
  srand(time(NULL));

  int choice = chooseMenu();
  while (choice != 4) {
    if (choice == 1) {
      myDeck.shuffle();
      cout << "\nThe deck was shuffled!" << endl;
    } else if (choice == 2) {
      if (myDeck.getCurrentCard() == 0) {
        cout << "\nThe deck is empty! Please initialize the deck." << endl;
      } else {
        int numToDeal;
        cout << "\nHow many cards do you want to deal? Remaining cards: "
             << myDeck.getCurrentCard();
        cout << "\nEnter an integer here: ";
        cin >> numToDeal;
        cout << endl;
        while (numToDeal < 1 || numToDeal > myDeck.getCurrentCard()) {
          cout << "Invalid entry.. Please enter an integer between 1 and "
               << myDeck.getCurrentCard() << ": ";
          cin >> numToDeal;
        }
        dealAndDisplay(myDeck, numToDeal);
      }
    } else {
      myDeck.initializeDeck();
      cout << "\nThe deck was initialized!" << endl;
    }
    choice = chooseMenu();
  }
  cout << "\nGood bye! Thank you for using this program." << endl;
}

int chooseMenu() {
  int choice;
  cout << "\n\n\t***Card Deck Operation Menu***" << endl;
  cout << "\t1) Shuffle the deck\n\t2) Deal cards and display" << endl;
  cout << "\t3) Initialize the deck\n\t4) Quit" << endl;
  cout << "\nPlease enter your choice here: ";
  cin >> choice;
  while (choice < 1 || choice > 4) {
    cout << "Invalid entry.. Please enter an integer between 1 to 4: ";
    cin >> choice;
  }
  return choice;
}

void dealAndDisplay(DeckOfCards &deck, int num) {
  for (int i = 0; i < num; i++) {
    cout << left << setw(20) << deck.dealCard().toString();
    if (i % 4 == 3) {
      cout << endl;
    }
  }
}