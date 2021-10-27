//
// Created by Mickael Salvas on 2021-03-22.
//

#include "PairHandler.h"
#include "../HandHandlerHelper.h"

Hand PairHandler::handle(std::vector<Card> cards) {
    if (containsPair(cards)) {
        auto pairNb = HandHandlerHelper::getFrequencyCardNumber(cards, 2);
        std::vector<Card> winningHand = HandHandlerHelper::transferCardsFromNumber(&cards, pairNb, 2);
        std::vector<Card> highestCards = HandHandlerHelper::getHighestCards(cards, 3);
        winningHand = HandHandlerHelper::combineAndSortCards(winningHand, highestCards);
        return Hand(HandRank::Pair, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool PairHandler::containsPair(std::vector<Card> cards) {
    return HandHandlerHelper::containsCardNumberFrequencyAmount(cards, 2, 1);
}
