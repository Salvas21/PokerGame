//
// Created by Mickael Salvas on 2021-03-02.
//

#include "TexasPoker.h"
#include "../../Consoles/Console.h"
#include "../../CoR/HandHandler.h"
#include "../../CoR/HandChecker.h"
#include "../../CoR/HandHandlerHelper.h"
#include <random>
#include <algorithm>

TexasPoker::TexasPoker() {
    setPlayerAmount(2, 9);
}

void TexasPoker::play(int playersNb) {
    generateDeck();
    shuffleDeck();
    createPlayers(playersNb);
    generateCommunityCards();
    flop();
    turn();
    river();
    calculateHands();
    std::vector<Player> winners = getReallyLuckyPlayers(sortPlayers());
    Console::printEndGameInfo(communityCards, players, winners);
}

void TexasPoker::generateDeck() {
    for (int type = CardType::Club; type <= CardType::Diamond; type++) {
        for (int number = CardNumber::Ace; number <= CardNumber::King; number++) {
            auto cardNb = static_cast<CardNumber>(number);
            auto cardType = static_cast<CardType>(type);
            deck.push_back(Card(cardNb, cardType));
        }
    }
}

void TexasPoker::shuffleDeck() {
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::shuffle(deck.begin(), deck.end(), randomEngine);
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
    cards.push_back(pickCardFromDeck());
    cards.push_back(pickCardFromDeck());
    return cards;
}

void TexasPoker::generateCommunityCards() {
    communityCards.push_back(pickCardFromDeck());
    communityCards.push_back(pickCardFromDeck());
}

void TexasPoker::flop() {
    burnCard();
    communityCards.push_back(pickCardFromDeck());
}

void TexasPoker::turn() {
    burnCard();
    communityCards.push_back(pickCardFromDeck());
}

void TexasPoker::river() {
    burnCard();
    communityCards.push_back(pickCardFromDeck());
}

Card TexasPoker::pickCardFromDeck() {
    Card card = deck.front();
    deck.erase(deck.begin());
    return card;
}

void TexasPoker::burnCard() {
    deck.erase(deck.begin());
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




