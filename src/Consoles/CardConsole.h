//
// Created by Mickael Salvas on 2021-03-12.
//

#ifndef POKER_CARDCONSOLE_H
#define POKER_CARDCONSOLE_H

#include "../Models/Card/Card.h"
#include <string>

class CardConsole {
public:
    static void printCard(Card card, int indent);
    static void printCommunityCards(std::vector<Card> cards);

private:
    static std::string findCardTypeName(CardType type);
    static std::string findCardTypeIcon(CardType type);
    static std::string findCardNumberAcronym(CardNumber nb);
    static std::string findCardNumberName(CardNumber nb);
};


#endif //POKER_CARDCONSOLE_H
