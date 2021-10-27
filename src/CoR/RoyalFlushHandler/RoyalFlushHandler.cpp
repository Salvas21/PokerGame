//
// Created by Mickael Salvas on 2021-03-26.
//

#include "RoyalFlushHandler.h"
#include "../HandHandlerHelper.h"

Hand RoyalFlushHandler::handle(std::vector<Card> cards) {
    if (royalFlushVerification(cards)) {
        auto type = HandHandlerHelper::getFrequencyType(cards, 5);
        std::vector<Card> winningHand;
        winningHand.push_back(Card(CardNumber::Ten, type));
        winningHand.push_back(Card(CardNumber::Jack, type));
        winningHand.push_back(Card(CardNumber::Queen, type));
        winningHand.push_back(Card(CardNumber::King, type));
        winningHand.push_back(Card(CardNumber::Ace, type));
        return Hand(HandRank::RoyalFlush, winningHand);
    } else if (next != nullptr) {
        return next->handle(cards);
    }
    throw std::exception();
}

bool RoyalFlushHandler::royalFlushVerification(std::vector<Card> cards) {
    if (cards[0].getNumber() == CardNumber::Ace) {
        cards = HandHandlerHelper::swapAce(cards);
        if (containsRoyalFlush(cards)) {
            return true;
        }
    }
    return false;
}

bool RoyalFlushHandler::containsRoyalFlush(std::vector<Card> cards) {
    int count = 1;
    if (HandHandlerHelper::containsFiveOrTen(cards)) {
        for (int i = 0; i < cards.size() - 1 && count < 5; i++) {
            if (cards[i].isLastOf(cards[i + 1])) {
                count++;
                cardsNumbers.push_back(cards[i].getNumber());
            } else if (cards[i].getNumber() == CardNumber::King && cards[i + 1].getNumber() == CardNumber::Ace && cards[i].getType() == cards[i + 1].getType()) {
                count++;
                cardsNumbers.push_back(cards[i].getNumber());
                cardsNumbers.push_back(cards[i + 1].getNumber());
            } else if (cards[i] != cards[i + 1]) {
                count = 1;
                cardsNumbers.clear();
            }
        }
    }
    return count == 5 && validateRoyalFlush();
}

bool RoyalFlushHandler::validateRoyalFlush() {
    if (cardsNumbers[0] == CardNumber::Ten
        && cardsNumbers[1] == CardNumber::Jack
        && cardsNumbers[2] == CardNumber::Queen
        && cardsNumbers[3] == CardNumber::King
        && cardsNumbers[4] == CardNumber::Ace) {
        return true;
    }
    return false;
}


