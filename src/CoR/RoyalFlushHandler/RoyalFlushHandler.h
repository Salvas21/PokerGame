//
// Created by Mickael Salvas on 2021-03-26.
//

#ifndef POKER_ROYALFLUSHHANDLER_H
#define POKER_ROYALFLUSHHANDLER_H

#include "../HandHandler.h"

class RoyalFlushHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool royalFlushVerification(std::vector<Card> cards);
    bool containsRoyalFlush(std::vector<Card> cards);
    bool validateRoyalFlush();
    std::vector<CardNumber> cardsNumbers;
};


#endif //POKER_ROYALFLUSHHANDLER_H
