//
// Created by Mickael Salvas on 2021-03-12.
//

#include "CardConsole.h"
#include <iostream>
#include <vector>

using std::cout, std::endl;

void CardConsole::printCard(Card card, int indent) {
    int baseIndent = 4;
    std::string space = " ";
    std::string spaces;
    for (int i = 0; i < indent * baseIndent; i++) {
        spaces += space;
    }
    cout << spaces << findCardNumberAcronym(card.getNumber()) << " " << findCardTypeIcon(card.getType()) <<
         " (" << findCardNumberName(card.getNumber()) << " of " << findCardTypeName(card.getType()) << ")" << endl;

}

std::string CardConsole::findCardTypeIcon(CardType type) {
    std::string typeIcon;
    if (type == CardType::Club) {
        typeIcon = "♣️";
    } else if (type == CardType::Spade) {
        typeIcon = "♠️";
    } else if (type == CardType::Heart) {
        typeIcon = "♥️";
    } else if (type == CardType::Diamond) {
        typeIcon = "♦️";
    }
    return typeIcon;
}

std::string CardConsole::findCardTypeName(CardType type) {
    std::string typeName;
    if (type == CardType::Club) {
        typeName = "Clubs";
    } else if (type == CardType::Spade) {
        typeName = "Spades️";
    } else if (type == CardType::Heart) {
        typeName = "Hearts️";
    } else if (type == CardType::Diamond) {
        typeName = "Diamonds️";
    }
    return typeName;
}

std::string CardConsole::findCardNumberAcronym(CardNumber nb) {
    std::string numberName;
    if (nb == CardNumber::Ace) {
        numberName = "A";
    } else if (nb == CardNumber::Two) {
        numberName = "2";
    } else if (nb == CardNumber::Three) {
        numberName = "3";
    } else if (nb == CardNumber::Four) {
        numberName = "4";
    } else if (nb == CardNumber::Five) {
        numberName = "5";
    } else if (nb == CardNumber::Six) {
        numberName = "6";
    } else if (nb == CardNumber::Seven) {
        numberName = "7";
    } else if (nb == CardNumber::Eight) {
        numberName = "8";
    } else if (nb == CardNumber::Nine) {
        numberName = "9";
    } else if (nb == CardNumber::Ten) {
        numberName = "10";
    } else if (nb == CardNumber::Jack) {
        numberName = "J";
    } else if (nb == CardNumber::Queen) {
        numberName = "Q";
    } else if (nb == CardNumber::King) {
        numberName = "K";
    }
    return numberName;
}

std::string CardConsole::findCardNumberName(CardNumber nb) {
    std::string numberName;
    if (nb == CardNumber::Ace) {
        numberName = "Ace";
    } else if (nb == CardNumber::Two) {
        numberName = "Two";
    } else if (nb == CardNumber::Three) {
        numberName = "Three";
    } else if (nb == CardNumber::Four) {
        numberName = "Four";
    } else if (nb == CardNumber::Five) {
        numberName = "Five";
    } else if (nb == CardNumber::Six) {
        numberName = "Six";
    } else if (nb == CardNumber::Seven) {
        numberName = "Seven";
    } else if (nb == CardNumber::Eight) {
        numberName = "Eight";
    } else if (nb == CardNumber::Nine) {
        numberName = "Nine";
    } else if (nb == CardNumber::Ten) {
        numberName = "Ten";
    } else if (nb == CardNumber::Jack) {
        numberName = "Jack";
    } else if (nb == CardNumber::Queen) {
        numberName = "Queen";
    } else if (nb == CardNumber::King) {
        numberName = "King";
    }
    return numberName;
}

void CardConsole::printCommunityCards(std::vector<Card> cards) {
    cout << "Community cards : " << endl;
    for (auto &card : cards) {
        CardConsole::printCard(card, 1);
    }
    cout << endl;
}
