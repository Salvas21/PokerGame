//
// Created by Mickael Salvas on 2021-03-11.
//

#include "Player.h"
#include <utility>

Player::Player(std::vector<Card> cards, std::string name) {
    this->cards = std::move(cards);
    this->name = std::move(name);
    this->hand = Hand(HandRank::Straight, std::vector<Card>());
}

std::vector<Card> Player::getCards() {
    return cards;
}

void Player::setHand(Hand newHand) {
    Player::hand.setHandRank(newHand.getHandRank());
    Player::hand.setHandCards(newHand.getHandCards());
}

HandRank Player::getHandRank() {
    return hand.getHandRank();
}

std::string Player::getName() {
    return name;
}

std::vector<Card> Player::getHandCards() {
    return this->hand.getHandCards();
}

bool Player::operator<(const Player &other) {
    return this->hand < other.hand;
}

bool Player::operator==(const Player &other) {
    return this->hand == other.hand;
}

