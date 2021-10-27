//
// Created by Mickael Salvas on 2021-03-29.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H

#include <vector>
#include "../Card/Card.h"

enum HandRank {
    HighCard,
    Pair,
    TwoPair,
    ThreeOfKind,
    Straight,
    Flush,
    FullHouse,
    FourOfKind,
    StraightFlush,
    RoyalFlush
};

class Hand {
public:
    Hand(HandRank handRank, std::vector<Card> cards);
    void setHandCards(std::vector<Card> cards);
    void setHandRank(HandRank handRank);
    std::vector<Card> getHandCards();
    int getValue();
    HandRank getHandRank();
    bool operator==(const Hand &other) const;
    bool operator!=(const Hand &other) const;
    bool operator<(const Hand &other) const;

private:
    void calculateHandValue();
    std::vector<Card> handCards;
    int handValue;
    HandRank rank;
};


#endif //POKER_HAND_H
