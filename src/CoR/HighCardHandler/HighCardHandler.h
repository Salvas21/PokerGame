//
// Created by Mickael Salvas on 2021-03-30.
//

#ifndef POKER_HIGHCARDHANDLER_H
#define POKER_HIGHCARDHANDLER_H

#include "../HandHandler.h"

class HighCardHandler : public HandHandler{
    Hand handle(std::vector<Card> cards) override;
};


#endif //POKER_HIGHCARDHANDLER_H
