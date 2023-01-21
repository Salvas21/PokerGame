//
// Created by Mickael Salvas on 2021-10-27.
//

#ifndef POKER_NORMALDECK_H
#define POKER_NORMALDECK_H

#include <vector>
#include "../Deck.h"
#include "../../Card/Card.h"

class NormalDeck : public Deck {
public:
    void generate() override;
    Card pick();
    void burn();

private:
    std::vector<Card> cards;

    void shuffle();
};


#endif //POKER_NORMALDECK_H
