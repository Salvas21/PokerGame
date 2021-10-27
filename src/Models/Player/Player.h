//
// Created by Mickael Salvas on 2021-03-11.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include "../Card/Card.h"
#include "../Hand/Hand.h"
#include <vector>
#include <string>

class Player {
public:
    Player(std::vector<Card> cards, std::string name);
    std::vector<Card> getCards();
    void setHand(Hand hand);
    HandRank getHandRank();
    std::vector<Card> getHandCards();
    std::string getName();
    bool operator <(const Player &other);
    bool operator ==(const Player &other);

private:
    std::vector<Card> cards;
    std::string name;
    Hand hand = Hand(HandRank::HighCard, std::vector<Card>());
};


#endif //POKER_PLAYER_H
