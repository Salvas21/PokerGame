//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_FOUROFKINDHANDLER_H
#define POKER_FOUROFKINDHANDLER_H

#include "../HandHandler.h"

class FourOfKindHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsFourOfKind(std::vector<Card> cards);
};


#endif //POKER_FOUROFKINDHANDLER_H
