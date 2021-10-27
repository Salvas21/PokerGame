//
// Created by Mickael Salvas on 2021-03-29.
//

#include "Hand.h"
#include <utility>

Hand::Hand(HandRank handRank, std::vector<Card> cards) {
    this->handCards = std::move(cards);
    this->rank = handRank;
    this->handValue = 0;
    calculateHandValue();
}

void Hand::setHandCards(std::vector<Card> cards) {
    this->handCards = std::move(cards);
    calculateHandValue();
}

void Hand::setHandRank(HandRank handRank) {
    this->rank = handRank;
}

std::vector<Card> Hand::getHandCards() {
    return this->handCards;
}

int Hand::getValue() {
    return this->handValue;
}

HandRank Hand::getHandRank() {
    return this->rank;
}

void Hand::calculateHandValue() {
    int value = 0;
    for (auto &card : handCards) {
        value += card.getNumber();
    }
    this->handValue = value;
}

bool Hand::operator==(const Hand &other) const {
    return rank == other.rank && handValue == other.handValue;
}

bool Hand::operator!=(const Hand &other) const {
    return !(other == *this);
}

bool Hand::operator<(const Hand &other) const {
    return rank < other.rank || (rank == other.rank && handValue < other.handValue);

}
