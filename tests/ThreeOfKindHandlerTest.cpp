//
// Created by Mickael Salvas on 2021-03-24.
//

#include "../src/CoR/ThreeOfKindHandler/ThreeOfKindHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, ThreeOfKindTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Diamond));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Three, CardType::Spade));
    hand.push_back(Card(CardNumber::Three, CardType::Diamond));
    hand.push_back(Card(CardNumber::Three, CardType::Heart));
    hand.push_back(Card(CardNumber::Ten, CardType::Spade));

    Hand expected = Hand(HandRank::ThreeOfKind, hand);
    Hand received = ThreeOfKindHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, ThreeOfKindFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));

    ASSERT_ANY_THROW(ThreeOfKindHandler().handle(cards));
}

