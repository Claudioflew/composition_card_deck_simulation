#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>

class DeckOfCards {
public:
  DeckOfCards();
  void initializeDeck();
  void setCurrentCard(int);
  void shuffle();
  Card dealCard();
  int getCurrentCard() const;
  void displayNice() const;

private:
  // Comment 4: moreCards() function is needed to test if the player can deal a card from the deck, so this should be a helper function, which should be private.
  bool moreCards() const;

  std::vector<Card> deck;
  int currentCard = 0;
  const int NUM_OF_FACE = 13;
  const int NUM_OF_SUIT = 4;
};

#endif