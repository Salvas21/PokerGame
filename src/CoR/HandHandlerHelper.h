//
// Created by Mickael Salvas on 2021-03-23.
//

#ifndef POKER_HANDHANDLERHELPER_H
#define POKER_HANDHANDLERHELPER_H

#include "../Models/Card/Card.h"
#include <vector>
#include <map>

class HandHandlerHelper {
public:
    static bool containsCardNumberFrequencyAmount(std::vector<Card> cards, int freq, int amount);
    static bool containsCardTypeFrequencyAmount(std::vector<Card> cards, int freq, int amount);
    static bool containsFiveOrTen(std::vector<Card> cards);
    static std::vector<Card> swapAce(std::vector<Card> cards);
    static std::map<CardNumber, int> getCardNumberMap(std::vector<Card> cards);
    static std::vector<Card> getHighestCards(std::vector<Card> cards, int nb);
    static CardNumber getFrequencyCardNumber(std::vector<Card> cards, int freq);
    static std::vector<Card> transferCardsFromNumber(std::vector<Card> *cards, CardNumber nb, int amount);
    static std::vector<Card> combineCards(std::vector<Card> first, std::vector<Card> second);
    static std::vector<Card> sortCards(std::vector<Card> cards);
    static std::vector<Card> combineAndSortCards(std::vector<Card> first, std::vector<Card> second);
    static CardType getFrequencyType(std::vector<Card> cards, int freq);
};

#endif //POKER_HANDHANDLERHELPER_H
