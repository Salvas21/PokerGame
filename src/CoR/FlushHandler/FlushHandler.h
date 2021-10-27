//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_FLUSHHANDLER_H
#define POKER_FLUSHHANDLER_H

#include "../HandHandler.h"

class FlushHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsFlush(std::vector<Card> cards);
};


#endif //POKER_FLUSHHANDLER_H
