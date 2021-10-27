//
// Created by Mickael Salvas on 2021-03-24.
//

#ifndef POKER_THREEOFKINDHANDLER_H
#define POKER_THREEOFKINDHANDLER_H

#include "../HandHandler.h"

class ThreeOfKindHandler : public HandHandler {
public:
    Hand handle(std::vector<Card> cards) override;

private:
    bool containsThreeOfKind(std::vector<Card> cards);
};


#endif //POKER_THREEOFKINDHANDLER_H
