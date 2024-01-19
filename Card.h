#ifndef CARD_H
#define CARD_H

#include <string>

class Card {

public:
  Card(int, int);
  // Comment 1: We don't want to forget to add const keyword if a function
  // doesn't change anything.
  std::string toString() const;

private:
  int face;
  int suit;

  static const int NUM_OF_FACE = 13;
  static const int NUM_OF_SUIT = 4;
  static const std::string faceVal[NUM_OF_FACE];
  static const std::string suitVal[NUM_OF_SUIT];
};

#endif