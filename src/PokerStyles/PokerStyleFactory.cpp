//
// Created by Mickael Salvas on 2021-03-27.
//

#include "PokerStyleFactory.h"
#include "Texas/TexasPoker.h"

PokerStyle *PokerStyleFactory::createPokerStyle(int choice) {
    if (choice == 1) {
        return new TexasPoker;
    } else {
        return nullptr;
    }
}
