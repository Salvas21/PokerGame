//
// Created by Mickael Salvas on 2021-03-26.
//

#include "../src/CoR/RoyalFlushHandler/RoyalFlushHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, RoyalFlushHighAceSwapTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Diamond));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Spade));
    cards.push_back(Card(CardNumber::Jack, CardType::Spade));
    cards.push_back(Card(CardNumber::Queen, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ten, CardType::Spade));
    hand.push_back(Card(CardNumber::Jack, CardType::Spade));
    hand.push_back(Card(CardNumber::Queen, CardType::Spade));
    hand.push_back(Card(CardNumber::King, CardType::Spade));
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));

    Hand expected = Hand(HandRank::RoyalFlush, hand);
    Hand received = RoyalFlushHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, RoyalFlushFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));
    cards.push_back(Card(CardNumber::Queen, CardType::Diamond));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));
    ASSERT_ANY_THROW(RoyalFlushHandler().handle(cards));
}

TEST(HandHandlers, RoyalFlushTypeFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Ten, CardType::Diamond));
    cards.push_back(Card(CardNumber::Jack, CardType::Diamond));
    cards.push_back(Card(CardNumber::Queen, CardType::Diamond));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));
    ASSERT_ANY_THROW(RoyalFlushHandler().handle(cards));
}