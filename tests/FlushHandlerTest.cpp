//
// Created by Mickael Salvas on 2021-03-24.
//
#include "../src/CoR/FlushHandler/FlushHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, FlushTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Diamond));
    cards.push_back(Card(CardNumber::Four, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Nine, CardType::Diamond));
    cards.push_back(Card(CardNumber::Nine, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Diamond));
    hand.push_back(Card(CardNumber::Three, CardType::Diamond));
    hand.push_back(Card(CardNumber::Four, CardType::Diamond));
    hand.push_back(Card(CardNumber::Five, CardType::Diamond));
    hand.push_back(Card(CardNumber::Nine, CardType::Diamond));

    Hand expected = Hand(HandRank::Flush, hand);
    Hand received = FlushHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, FlushFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::King, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Club));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Club));
    ASSERT_ANY_THROW(FlushHandler().handle(cards));
}