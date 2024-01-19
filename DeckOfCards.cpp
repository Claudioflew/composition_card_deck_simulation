#include "DeckOfCards.h"
#include "Card.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

DeckOfCards::DeckOfCards() { initializeDeck(); }

// Comment 5: Initialization of the deck should be implemented, so constructor
// calls this function.
void DeckOfCards::initializeDeck() {
  if (!deck.empty()) {
    deck.clear();
    setCurrentCard(0);
  }
  for (int s = 0; s < NUM_OF_SUIT; s++) {
    for (int f = 0; f < NUM_OF_FACE; f++) {
      // Comment 9: Here, we are creating 4x13 Card objects and append these to
      // deck data member. I assume value 4 and 13 should be const static
      // variable.
      Card tempCard = Card(f, s);
      deck.push_back(tempCard);
    }
  }
}

void DeckOfCards::setCurrentCard(int num) { currentCard = num; }

// Comment 6: The algorithm here is that we iterate a card in the deck and
// choose the other card appearing later the iterating card. Swap them by using
// temp. This iteration must be done just 51 times, not 52.
void DeckOfCards::shuffle() {
  int numOfCards = getCurrentCard();
  for (int i = 0; i < numOfCards; i++) {
    Card tempCard = deck[i];
    int randInt = rand() % numOfCards;
    while (randInt == i) { randInt = rand() % numOfCards; }
    deck[i] = deck[randInt];
    deck[randInt] = tempCard;
  }
}

bool DeckOfCards::moreCards() const {
  if (currentCard <= 51) {
    return true;
  }
  return false;
}

Card DeckOfCards::dealCard() {
  // Comment 7: This helper function (predicate function) works like an input
  // validation here.
  if (moreCards()) {
    Card cardToReturn = deck[currentCard];
    currentCard++;
    return cardToReturn;
  } else {
    cout << "No more cards in the deck.." << endl;
  }
}

int DeckOfCards::getCurrentCard() const {
  return (52 - currentCard);
}

// Comment 8: We don't need this for this assignment, but I added it too.
void DeckOfCards::displayNice() const {
  for (int i = 0; i < 52; i++) {
    cout << left << setw(20) << deck[i].toString();
    if (i % 4 == 3) {
      cout << endl;
    }
  }
}
