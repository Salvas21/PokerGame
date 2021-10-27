//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_STRAIGHTHANDLER_H
#define POKER_STRAIGHTHANDLER_H

#include "../HandHandler.h"

class StraightHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool straightVerification(std::vector<Card> cards);
    bool containsStraight(std::vector<Card> cards);
    std::vector<Card> getSequence(std::vector<Card> cards);
};

#endif //POKER_STRAIGHTHANDLER_H
