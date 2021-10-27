//
// Created by Mickael Salvas on 2021-03-01.
//

#include "PokerStyle.h"

PokerStyle::~PokerStyle() = default;

void PokerStyle::setPlayerAmount(int min, int max) {
    minPlayers = min;
    maxPlayers = max;
}

int PokerStyle::getMinPlayers() const {
    return PokerStyle::minPlayers;
}

int PokerStyle::getMaxPlayers() const {
    return PokerStyle::maxPlayers;
}
