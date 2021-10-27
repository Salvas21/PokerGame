//
// Created by Mickael Salvas on 2021-03-26.
//

#ifndef POKER_HANDCHECKER_H
#define POKER_HANDCHECKER_H


#include "HandHandler.h"
#include "../Models/Hand/Hand.h"

class HandChecker {
public:
    HandChecker() = default;
    Hand checkHand(std::vector<Card> cards);

private:
    void initHandlers();
    void chainHandlers();
    Hand handle(std::vector<Card> cards);
    void deleteHandlers();

    HandHandler *royalFlush;
    HandHandler *straightFlush;
    HandHandler *fourOfKind;
    HandHandler *fullHouse;
    HandHandler *flush;
    HandHandler *straight;
    HandHandler *threeOfKind;
    HandHandler *twoPair;
    HandHandler *pair;
    HandHandler *highCard;
};


#endif //POKER_HANDCHECKER_H
