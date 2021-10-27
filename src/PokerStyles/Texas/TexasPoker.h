//
// Created by Mickael Salvas on 2021-03-02.
//

#ifndef POKER_TEXASPOKER_H
#define POKER_TEXASPOKER_H

#include "../PokerStyle.h"
#include "../../Models/Card/Card.h"
#include "../../Models/Player/Player.h"
#include <vector>

class TexasPoker : public PokerStyle {
public:
    TexasPoker();
    void play(int playersNb) override;

private:
    std::vector<Card> deck;
    std::vector<Player> players;
    std::vector<Card> communityCards;

    void generateDeck();
    void shuffleDeck();
    void createPlayers(int nb);
    std::string createPlayerName(int i);
    std::vector<Card> generatePlayerHand();
    void generateCommunityCards();
    void flop();
    void turn();
    void river();
    Card pickCardFromDeck();
    void burnCard();
    void calculateHands();
    std::vector<Player> sortPlayers();
    std::vector<Player> getReallyLuckyPlayers(std::vector<Player> sortedPlayers);
};

#endif //POKER_TEXASPOKER_H
