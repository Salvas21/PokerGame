//
// Created by Mickael Salvas on 2021-03-23.
//

#include "../src/CoR/TwoPairHandler/TwoPairHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, TwoPairsTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Club));
    hand.push_back(Card(CardNumber::Ace, CardType::Diamond));
    hand.push_back(Card(CardNumber::Four, CardType::Heart));
    hand.push_back(Card(CardNumber::Ten, CardType::Spade));
    hand.push_back(Card(CardNumber::Ten, CardType::Heart));

    Hand expected = Hand(HandRank::TwoPair, hand);
    Hand received = TwoPairHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, TwoPairsFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));

    ASSERT_ANY_THROW(TwoPairHandler().handle(cards));
}