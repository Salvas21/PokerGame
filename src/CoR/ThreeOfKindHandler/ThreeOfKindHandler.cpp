//
// Created by Mickael Salvas on 2021-03-24.
//

#include "ThreeOfKindHandler.h"
#include "../HandHandlerHelper.h"

Hand ThreeOfKindHandler::handle(std::vector<Card> cards) {
    if (containsThreeOfKind(cards)) {
        auto tripleNb = HandHandlerHelper::getFrequencyCardNumber(cards, 3);
        std::vector<Card> winningHand = HandHandlerHelper::transferCardsFromNumber(&cards, tripleNb, 3);
        std::vector<Card> highestCards = HandHandlerHelper::getHighestCards(cards, 2);
        winningHand = HandHandlerHelper::combineAndSortCards(winningHand, highestCards);
        return Hand(HandRank::ThreeOfKind, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool ThreeOfKindHandler::containsThreeOfKind(std::vector<Card> cards) {
    return HandHandlerHelper::containsCardNumberFrequencyAmount(cards, 3, 1);
}