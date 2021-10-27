//
// Created by Mickael Salvas on 2021-03-23.
//

#include <map>
#include "HandHandlerHelper.h"

/**
 * Checks the frequency of a card with the same number,
 * returns boolean from the desired amount of cards of the wanted frequency or higher.
 * @param cards
 * @param freq
 * @param amount
 * @return
 */
bool HandHandlerHelper::containsCardNumberFrequencyAmount(std::vector<Card> cards, int freq, int amount) {
    std::map<CardNumber, int> duplicateMap = HandHandlerHelper::getCardNumberMap(cards);
    int count = 0;
    for (auto &cardFreq : duplicateMap) {
        if (cardFreq.second >= freq) {
            count++;
        }
    }
    return count >= amount;
}

/**
 * Checks the frequency of a card with the same type,
 * returns boolean from the desired amount of cards of the wanted frequency or higher.
 * @param cards
 * @param freq
 * @param amount
 * @return
 */
bool HandHandlerHelper::containsCardTypeFrequencyAmount(std::vector<Card> cards, int freq, int amount) {
    std::map<CardType, int> duplicateMap;
    for (auto &card : cards) {
        auto result = duplicateMap.insert(std::pair<CardType, int>(card.getType(), 1));
        if (!result.second) {
            result.first->second++;
        }
    }
    int count = 0;
    for (auto &cardFreq : duplicateMap) {
        if (cardFreq.second >= freq) {
            count++;
        }
    }
    return count >= amount;
}

bool HandHandlerHelper::containsFiveOrTen(std::vector<Card> cards) {
    bool five = false;
    bool ten = false;
    for (Card &card : cards) {
        if (card.getNumber() == CardNumber::Five) {
            five = true;
        } else if (card.getNumber() == CardNumber::Ten) {
            ten = true;
        }
    }
    return five || ten;
}

/**
 * Swap low Ace to high Ace
 * @param cards
 * @return
 */
std::vector<Card> HandHandlerHelper::swapAce(std::vector<Card> cards) {
    cards.push_back(cards.front());
    cards.erase(cards.begin());
    return cards;
}

std::map<CardNumber, int> HandHandlerHelper::getCardNumberMap(std::vector<Card> cards) {
    std::map<CardNumber, int> duplicateMap;
    for (auto &card : cards) {
        auto result = duplicateMap.insert(std::pair<CardNumber, int>(card.getNumber(), 1));
        if (!result.second) {
            result.first->second++;
        }
    }
    return duplicateMap;
}

std::vector<Card> HandHandlerHelper::getHighestCards(std::vector<Card> cards, int nb) {
    std::vector<Card> highCards;
    for (int i = cards.size() - 1, j = 0; j < nb; j++, i--) {
        highCards.push_back(cards[i]);
    }
    return highCards;
}

CardNumber HandHandlerHelper::getFrequencyCardNumber(std::vector<Card> cards, int freq) {
    CardNumber cardNb;
    std::map<CardNumber, int> duplicateMap = HandHandlerHelper::getCardNumberMap(cards);
    for (auto &cardFreq : duplicateMap) {
        if (cardFreq.second >= freq) {
            cardNb = cardFreq.first;
        }
    }
    return cardNb;
}

std::vector<Card> HandHandlerHelper::transferCardsFromNumber(std::vector<Card> *cards, CardNumber nb, int amount) {
    std::vector<Card> newCards;
    for (auto card = cards->begin(); card < cards->end() && newCards.size() < amount;) {
        if (card->getNumber() == nb) {
            newCards.push_back(*card);
            cards->erase(card);
        } else {
            card++;
        }
    }
    return newCards;
}

std::vector<Card> HandHandlerHelper::combineCards(std::vector<Card> first, std::vector<Card> second) {
    std::vector<Card> cards;
    cards.reserve(first.size() + second.size());
    cards.insert(cards.end(), first.begin(), first.end());
    cards.insert(cards.end(), second.begin(), second.end());
    return cards;
}

std::vector<Card> HandHandlerHelper::sortCards(std::vector<Card> cards) {
    std::sort(cards.begin(), cards.end(), [](Card& leftCard, Card& rightCard) {
        return leftCard.getNumber() < rightCard.getNumber();
    });
    return cards;
}

std::vector<Card> HandHandlerHelper::combineAndSortCards(std::vector<Card> first, std::vector<Card> second) {
    return sortCards(combineCards(first, second));
}

CardType HandHandlerHelper::getFrequencyType(std::vector<Card> cards, int freq) {
    std::map<CardType, int> duplicateMap;
    for (auto &card : cards) {
        auto result = duplicateMap.insert(std::pair<CardType, int>(card.getType(), 1));
        if (!result.second) {
            result.first->second++;
        }
    }
    CardType type;
    for (auto &cardFreq : duplicateMap) {
        if (cardFreq.second >= freq) {
            type = cardFreq.first;
        }
    }
    return type;
}





