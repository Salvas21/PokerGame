//
// Created by Mickael Salvas on 2021-03-27.
//

#ifndef POKER_POKERSTYLEFACTORY_H
#define POKER_POKERSTYLEFACTORY_H

#include "PokerStyle.h"

class PokerStyleFactory {
public:
    PokerStyleFactory() = default;
    PokerStyle* createPokerStyle(int choice);
};


#endif //POKER_POKERSTYLEFACTORY_H
