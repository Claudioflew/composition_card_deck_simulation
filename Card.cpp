#include "Card.h"
#include <string>

using namespace std;

const std::string Card::faceVal[NUM_OF_FACE] = {
    "Ace",   "Deuce", "Three", "Four", "Five",  "Six", "Seven",
    "Eight", "Nine",  "Ten",   "Jack", "Queen", "King"};

const std::string Card::suitVal[NUM_OF_SUIT] = {
    "Spades", "Hearts", "Clubs", "Diamonds"};

// Comment 2: Member initializer list is useful if we don't need any input
// validation.
Card::Card(int f, int s) : face(f), suit(s) {}

string Card::toString() const {
  // Comment 3: We don't need this pointer here, but to make it easy to examine,
  // I added it.
  return faceVal[this->face] + " of " + suitVal[this->suit];
}