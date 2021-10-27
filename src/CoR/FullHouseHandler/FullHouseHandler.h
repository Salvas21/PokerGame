//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_FULLHOUSEHANDLER_H
#define POKER_FULLHOUSEHANDLER_H

#include "../HandHandler.h"

class FullHouseHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsFullHouse(std::vector<Card> cards);
    bool containsUniqueSequence(std::vector<Card> *cards, int freq, int amount);
    bool containsPair(std::vector<Card> *cards);
    bool containsThreeOfKind(std::vector<Card> *cards);
};


#endif //POKER_FULLHOUSEHANDLER_H
