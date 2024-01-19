cmake_minimum_required(VERSION 3.27)
project(Assignment6_CardDeckSimulationComposition)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment6_CardDeckSimulationComposition
        Card.cpp
        Card.h
        DeckOfCards.cpp
        DeckOfCards.h
        main.cpp)
