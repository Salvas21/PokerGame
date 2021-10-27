//
// Created by Mickael Salvas on 2021-03-13.
//

#ifndef POKER_CONSOLE_H
#define POKER_CONSOLE_H

#include "../Models/Player/Player.h"
#include <vector>

class Console {
public:
    static void printEndGameInfo(std::vector<Card> communityCards, std::vector<Player> players, std::vector<Player> winners);
};

#endif //POKER_CONSOLE_H
