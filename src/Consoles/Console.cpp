//
// Created by Mickael Salvas on 2021-03-13.
//

#include "Console.h"
#include "PlayerConsole.h"
#include "CardConsole.h"
#include <iostream>
#include <utility>

using std::cout, std::endl;

void Console::printEndGameInfo(std::vector<Card> communityCards, std::vector<Player> players, std::vector<Player> winners) {
    CardConsole::printCommunityCards(std::move(communityCards));
    PlayerConsole::printInfo(std::move(players));
    PlayerConsole::printResult(std::move(winners));
}
