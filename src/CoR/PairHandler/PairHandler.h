//
// Created by Mickael Salvas on 2021-03-22.
//

#ifndef POKER_PAIRHANDLER_H
#define POKER_PAIRHANDLER_H

#include "../HandHandler.h"

class PairHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsPair(std::vector<Card> cards);
};


#endif //POKER_PAIRHANDLER_H
