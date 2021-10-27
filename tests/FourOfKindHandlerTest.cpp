//
// Created by Mickael Salvas on 2021-03-24.
//

#include "../src/CoR/FourOfKindHandler/FourOfKindHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, FourOfKindTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Ace, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Heart));
    cards.push_back(Card(CardNumber::Five, CardType::Club));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Club));
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Ace, CardType::Diamond));
    hand.push_back(Card(CardNumber::Ace, CardType::Heart));
    hand.push_back(Card(CardNumber::Five, CardType::Club));

    Hand expected = Hand(HandRank::FourOfKind, hand);
    Hand received = FourOfKindHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, FourOfKindFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Seven, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Diamond));
    cards.push_back(Card(CardNumber::Seven, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Club));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Queen, CardType::Club));

    ASSERT_ANY_THROW(FourOfKindHandler().handle(cards));
}