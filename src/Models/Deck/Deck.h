//
// Created by Mickael Salvas on 2021-10-27.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H


class Deck {
public:
    Deck() = default;
    virtual void generate() = 0;
};


#endif //POKER_DECK_H
