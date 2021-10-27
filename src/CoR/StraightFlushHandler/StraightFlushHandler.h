//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_STRAIGHTFLUSHHANDLER_H
#define POKER_STRAIGHTFLUSHHANDLER_H

#include "../HandHandler.h"

class StraightFlushHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsStraightFlush(std::vector<Card> cards);
};


#endif //POKER_STRAIGHTFLUSHHANDLER_H
