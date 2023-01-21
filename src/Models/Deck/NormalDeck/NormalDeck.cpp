//
// Created by Mickael Salvas on 2021-10-27.
//

#include <random>
#include "NormalDeck.h"

void NormalDeck::generate() {
    for (int type = CardType::Club; type <= CardType::Diamond; type++) {
        for (int number = CardNumber::Ace; number <= CardNumber::King; number++) {
            auto cardNb = static_cast<CardNumber>(number);
            auto cardType = static_cast<CardType>(type);
            cards.push_back(Card(cardNb, cardType));
        }
    }
    shuffle();
}

Card NormalDeck::pick() {
    Card card = cards.front();
    cards.erase(cards.begin());
    return card;
}

void NormalDeck::burn() {
    cards.erase(cards.begin());
}

void NormalDeck::shuffle() {
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::shuffle(cards.begin(), cards.end(), randomEngine);
}


