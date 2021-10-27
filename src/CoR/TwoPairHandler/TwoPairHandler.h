//
// Created by Mickael Salvas on 2021-03-23.
//

#ifndef POKER_TWOPAIRHANDLER_H
#define POKER_TWOPAIRHANDLER_H

#include "../HandHandler.h"

class TwoPairHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsPairs(std::vector<Card> cards);
};


#endif //POKER_TWOPAIRHANDLER_H
