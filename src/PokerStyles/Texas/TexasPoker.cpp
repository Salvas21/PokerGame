//
// Created by Mickael Salvas on 2021-03-02.
//

#include "TexasPoker.h"
#include "../../Consoles/Console.h"
#include "../../CoR/HandHandler.h"
#include "../../CoR/HandChecker.h"
#include "../../CoR/HandHandlerHelper.h"
#include <algorithm>

TexasPoker::TexasPoker() {
    setPlayerAmount(2, 9);
}

void TexasPoker::play(int playersNb) {
    deck.generate();
    createPlayers(playersNb);
    generateCommunityCards();
    flop();
    turn();
    river();
    calculateHands();
    std::vector<Player> winners = getReallyLuckyPlayers(sortPlayers());
    Console::printEndGameInfo(communityCards, players, winners);
}

void TexasPoker::createPlayers(int nb) {
    for (int i = 0; i < nb; i++) {
        players.push_back(Player(generatePlayerHand(), createPlayerName(i)));
    }
}

std::string TexasPoker::createPlayerName(int i) {
    std::string name;
    if (i == 0) {
        name = "Human";
    } else {
        name = "Computer ";
        name.append(std::to_string(i));
    }
    return name;
}

std::vector<Card> TexasPoker::generatePlayerHand() {
    std::vector<Card> cards;
    cards.push_back(deck.pick());
    cards.push_back(deck.pick());
    return cards;
}

void TexasPoker::generateCommunityCards() {
    communityCards.push_back(deck.pick());
    communityCards.push_back(deck.pick());
}

void TexasPoker::flop() {
    deck.burn();
    communityCards.push_back(deck.pick());
}

void TexasPoker::turn() {
    deck.burn();
    communityCards.push_back(deck.pick());
}

void TexasPoker::river() {
    deck.burn();
    communityCards.push_back(deck.pick());
}

void TexasPoker::calculateHands() {
    for (auto &player : players) {
        std::vector<Card> cards = HandHandlerHelper::combineAndSortCards(player.getCards(), communityCards);
        player.setHand(HandChecker().checkHand(cards));
    }
}

std::vector<Player> TexasPoker::sortPlayers() {
    std::vector<Player> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player &left, Player &right) {
        return left < right;
    });
    return sortedPlayers;
}

std::vector<Player> TexasPoker::getReallyLuckyPlayers(std::vector<Player> sortedPlayers) {
    std::vector<Player> winners;
    bool foundWinners = false;
    winners.push_back(sortedPlayers.back());
    for (int i = sortedPlayers.size() - 1; i > 0 && !foundWinners; i--) {
        if (sortedPlayers[i] == sortedPlayers[i - 1]) {
            winners.push_back(sortedPlayers[i - 1]);
        } else {
            foundWinners = true;
        }
    }
    return winners;
}




