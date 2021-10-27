//
// Created by Mickael Salvas on 2021-03-12.
//

#ifndef POKER_PLAYERCONSOLE_H
#define POKER_PLAYERCONSOLE_H

#include "../Models/Card/Card.h"
#include "../Models/Player/Player.h"
#include <vector>
#include <string>

class PlayerConsole {
public:
    static void printInfo(std::vector<Player> players);
    static void printResult(std::vector<Player> winners);

private:
    static void printCards(std::string name, std::vector<Card> cards);
    static void printHandRank(HandRank rank);
    static void printHandCards(std::vector<Card> cards);
    static void printWinner(std::string playerName);
    static void printWinner(std::vector<Player> winners);
};


#endif //POKER_PLAYERCONSOLE_H
