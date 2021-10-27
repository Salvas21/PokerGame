//
// Created by Mickael Salvas on 2021-03-24.
//

#include "StraightFlushHandler.h"
#include "../HandHandlerHelper.h"

Hand StraightFlushHandler::handle(std::vector<Card> cards) {
    if (containsStraightFlush(cards)) {
        std::vector<Card> sequence;
        sequence.push_back(cards.front());
        for (int i = 0; i < cards.size() - 1 && sequence.size() < 5; i++) {
            if (cards[i].isLastOf(cards[i + 1])) {
                sequence.push_back(cards[i + 1]);
            } else if (cards[i] != cards[i + 1]) {
                sequence.clear();
                sequence.push_back(cards[i + 1]);
            }
        }
        return Hand(HandRank::StraightFlush, sequence);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool StraightFlushHandler::containsStraightFlush(std::vector<Card> cards) {
    int count = 1;
    if (HandHandlerHelper::containsFiveOrTen(cards)) {
        for (int i = 0; i < cards.size() - 1 && count < 5; i++) {
            if (cards[i].isLastOf(cards[i + 1])) {
                count++;
            } else if (cards[i] != cards[i + 1]) {
                count = 1;
            }
        }
    }
    return count == 5;
}
