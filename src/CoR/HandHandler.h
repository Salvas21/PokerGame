//
// Created by Mickael Salvas on 2021-03-22.
//

#ifndef POKER_HANDHANDLER_H
#define POKER_HANDHANDLER_H

#include "../Models/Card/Card.h"
#include "../Models/Player/Player.h"
#include <vector>

class HandHandler {
public:
    HandHandler() = default;
    virtual ~HandHandler() = default;
    HandHandler *setNext(HandHandler *handler);
    virtual Hand handle(std::vector<Card> cards) = 0;

protected:
    HandHandler *next = nullptr;
};


#endif //POKER_HANDHANDLER_H
