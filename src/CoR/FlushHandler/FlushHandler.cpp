//
// Created by Mickael Salvas on 2021-03-24.
//

#include "FlushHandler.h"
#include "../HandHandlerHelper.h"

Hand FlushHandler::handle(std::vector<Card> cards) {
    if (containsFlush(cards)) {
        auto type = HandHandlerHelper::getFrequencyType(cards, 5);
        std::vector<Card> winningHand;
        for (int i = 0; i < cards.size() && winningHand.size() < 5; i++) {
            if (cards[i].getType() == type) {
                winningHand.push_back(cards[i]);
            }
        }
        return Hand(HandRank::Flush, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool FlushHandler::containsFlush(std::vector<Card> cards) {
    return HandHandlerHelper::containsCardTypeFrequencyAmount(cards, 5, 1);
}