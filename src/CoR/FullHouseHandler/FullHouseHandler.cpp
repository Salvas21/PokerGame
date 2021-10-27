//
// Created by Mickael Salvas on 2021-03-24.
//

#include <map>
#include "FullHouseHandler.h"
#include "../HandHandlerHelper.h"

Hand FullHouseHandler::handle(std::vector<Card> cards) {
    if (containsFullHouse(cards)) {
        auto tripleNb = HandHandlerHelper::getFrequencyCardNumber(cards, 3);
        std::vector<Card> threeOfKind = HandHandlerHelper::transferCardsFromNumber(&cards, tripleNb, 3);

        auto pairNb = HandHandlerHelper::getFrequencyCardNumber(cards, 2);
        std::vector<Card> pair = HandHandlerHelper::transferCardsFromNumber(&cards, pairNb, 2);

        std::vector<Card> winningHand = HandHandlerHelper::combineAndSortCards(threeOfKind, pair);
        return Hand(HandRank::FullHouse, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool FullHouseHandler::containsFullHouse(std::vector<Card> cards) {
    auto newCards = cards;
    return containsPair(&newCards) && containsThreeOfKind(&newCards);
}

bool FullHouseHandler::containsPair(std::vector<Card> *cards) {
    return containsUniqueSequence(cards, 2, 1);
}

bool FullHouseHandler::containsThreeOfKind(std::vector<Card> *cards) {
    return containsUniqueSequence(cards, 3, 1);
}

bool FullHouseHandler::containsUniqueSequence(std::vector<Card> *cards, int freq, int amount) {
    std::map<CardNumber, int> duplicateMap = HandHandlerHelper::getCardNumberMap(*cards);
    int count = 0;
    for (auto &cardFreq : duplicateMap) {
        if (cardFreq.second >= freq) {
            count++;
            int nbCardsDeleted = 0;
            for (auto card = cards->begin(); card < cards->end() && nbCardsDeleted < freq;) {
                if (card->getNumber() == cardFreq.first) {
                    cards->erase(card);
                    nbCardsDeleted++;
                } else {
                    card++;
                }
            }
            break; // sorry
        }
    }
    return count >= amount;
}
