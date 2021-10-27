//
// Created by Mickael Salvas on 2021-03-24.
//

#include "StraightHandler.h"
#include "../HandHandlerHelper.h"

Hand StraightHandler::handle(std::vector<Card> cards) {
    if (straightVerification(cards)) {
        std::vector<Card> sequence = getSequence(cards);
        if (sequence.size() != 5) {
            sequence = getSequence(HandHandlerHelper::swapAce(cards));
        }
        return Hand(HandRank::Straight, sequence);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool StraightHandler::straightVerification(std::vector<Card> cards) {
    bool hasStraight = false;
    if (containsStraight(cards)) {
        hasStraight = true;
    } else {
        if (cards[0].getNumber() == CardNumber::Ace) {
            cards = HandHandlerHelper::swapAce(cards);
            if (containsStraight(cards)) {
                hasStraight = true;
            }
        }
    }
    return hasStraight;
}

bool StraightHandler::containsStraight(std::vector<Card> cards) {
    int count = 1;
    if (HandHandlerHelper::containsFiveOrTen(cards)) {
        for (int i = 0; i < cards.size() - 1 && count < 5; i++) {
            if (cards[i].getNumber() + 1 == cards[i + 1].getNumber()) {
                count++;
            } else if (cards[i].getNumber() == CardNumber::King && cards[i + 1].getNumber() == CardNumber::Ace) {
                count++;
            } else if (cards[i].getNumber() != cards[i + 1].getNumber()) {
                count = 1;
            }
        }
    }
    return count == 5;
}

std::vector<Card> StraightHandler::getSequence(std::vector<Card> cards) {
    std::vector<Card> sequence;
    sequence.push_back(cards.front());
    for (int i = 0; i < cards.size() - 1 && sequence.size() < 5; i++) {
        if (cards[i].getNumber() + 1 == cards[i + 1].getNumber()) {
            sequence.push_back(cards[i + 1]);
        } else if (cards[i].getNumber() == CardNumber::King && cards[i + 1].getNumber() == CardNumber::Ace) {
            sequence.push_back(cards[i + 1]);
        } else if (cards[i].getNumber() != cards[i + 1].getNumber()) {
            sequence.clear();
            sequence.push_back(cards[i + 1]);
        }
    }
    return sequence;
}
