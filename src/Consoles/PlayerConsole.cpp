//
// Created by Mickael Salvas on 2021-03-12.
//

#include "PlayerConsole.h"
#include "CardConsole.h"
#include <iostream>

using std::cout, std::endl;

void PlayerConsole::printInfo(std::vector<Player> players) {
    for (auto player : players) {
        PlayerConsole::printCards(player.getName(), player.getCards());
        PlayerConsole::printHandRank(player.getHandRank());
        PlayerConsole::printHandCards(player.getHandCards());
        cout << endl;
    }
}

void PlayerConsole::printCards(std::string name, std::vector<Card> cards) {
    std::cout << name << " cards :" << std::endl;
    for (auto &card : cards) {
        CardConsole::printCard(card, 1);
    }
}

void PlayerConsole::printHandRank(HandRank rank) {
    cout << "    " << "Hand rank : ";
    if (rank == HandRank::HighCard) {
        cout << "HIGH CARD" << endl;
    } else if (rank == HandRank::Pair) {
        cout << "PAIR" << endl;
    } else if (rank == HandRank::TwoPair) {
        cout << "TWO PAIR" << endl;
    } else if (rank == HandRank::ThreeOfKind) {
        cout << "THREE OF KIND" << endl;
    } else if (rank == HandRank::Straight) {
        cout << "STRAIGHT" << endl;
    } else if (rank == HandRank::Flush) {
        cout << "FLUSH" << endl;
    } else if (rank == HandRank::FullHouse) {
        cout << "FULL HOUSE" << endl;
    } else if (rank == HandRank::FourOfKind) {
        cout << "FOUR OF KIND" << endl;
    } else if (rank == HandRank::StraightFlush) {
        cout << "STRAIGHT FLUSH" << endl;
    } else if (rank == HandRank::RoyalFlush) {
        cout << "ROYAL FLUSH" << endl;
    }
}

void PlayerConsole::printHandCards(std::vector<Card> cards) {
    std::cout << "    " << "Hand cards : " << std::endl;
    for (auto &card : cards) {
        CardConsole::printCard(card, 2);
    }
}

void PlayerConsole::printResult(std::vector<Player> winners) {
    if (winners.size() > 1) {
        PlayerConsole::printWinner(winners);
    } else {
        PlayerConsole::printWinner(winners[0].getName());
    }
}

void PlayerConsole::printWinner(std::string playerName) {
    cout << "The winner is : " << playerName << " !" << endl;
}

void PlayerConsole::printWinner(std::vector<Player> winners) {
    cout << "There is a draw between : " << endl;
    for (auto &winner : winners) {
        cout << "    " << winner.getName() << endl;
    }
}


