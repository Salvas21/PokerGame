//
// Created by Mickael Salvas on 2021-03-23.
//

#include "TwoPairHandler.h"
#include "../HandHandlerHelper.h"

Hand TwoPairHandler::handle(std::vector<Card> cards) {
    if (containsPairs(cards)) {
        auto firstPairNb = HandHandlerHelper::getFrequencyCardNumber(cards, 2);
        std::vector<Card> firstPair = HandHandlerHelper::transferCardsFromNumber(&cards, firstPairNb, 2);

        auto secondPairNb = HandHandlerHelper::getFrequencyCardNumber(cards, 2);
        std::vector<Card> secondPair = HandHandlerHelper::transferCardsFromNumber(&cards, secondPairNb, 2);

        std::vector<Card> highestCards = HandHandlerHelper::getHighestCards(cards, 1);

        std::vector<Card> winningHand = HandHandlerHelper::combineAndSortCards(firstPair, secondPair);
        winningHand = HandHandlerHelper::combineAndSortCards(winningHand, highestCards);

        return Hand(HandRank::TwoPair, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool TwoPairHandler::containsPairs(std::vector<Card> cards) {
    return HandHandlerHelper::containsCardNumberFrequencyAmount(cards, 2, 2);
}