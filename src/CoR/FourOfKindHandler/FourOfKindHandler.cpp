//
// Created by Mickael Salvas on 2021-03-24.
//

#include "FourOfKindHandler.h"
#include "../HandHandlerHelper.h"

Hand FourOfKindHandler::handle(std::vector<Card> cards) {
    if (containsFourOfKind(cards)) {
        auto pairNb = HandHandlerHelper::getFrequencyCardNumber(cards, 4);
        std::vector<Card> winningHand = HandHandlerHelper::transferCardsFromNumber(&cards, pairNb, 4);
        std::vector<Card> highestCards = HandHandlerHelper::getHighestCards(cards, 1);
        winningHand = HandHandlerHelper::combineAndSortCards(winningHand, highestCards);
        return Hand(HandRank::FourOfKind, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool FourOfKindHandler::containsFourOfKind(std::vector<Card> cards) {
    return HandHandlerHelper::containsCardNumberFrequencyAmount(cards, 4, 1);
}
