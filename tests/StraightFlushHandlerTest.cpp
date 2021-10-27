//
// Created by Mickael Salvas on 2021-03-25.
//

#include "../src/CoR/StraightFlushHandler/StraightFlushHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, StraightFlushTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));
    cards.push_back(Card(CardNumber::Queen, CardType::Diamond));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Two, CardType::Spade));
    hand.push_back(Card(CardNumber::Three, CardType::Spade));
    hand.push_back(Card(CardNumber::Four, CardType::Spade));
    hand.push_back(Card(CardNumber::Five, CardType::Spade));

    Hand expected = Hand(HandRank::StraightFlush, hand);
    Hand received = StraightFlushHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightFlushTrueDuplicate) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Two, CardType::Spade));
    hand.push_back(Card(CardNumber::Three, CardType::Spade));
    hand.push_back(Card(CardNumber::Four, CardType::Spade));
    hand.push_back(Card(CardNumber::Five, CardType::Spade));

    Hand expected = Hand(HandRank::StraightFlush, hand);
    Hand received = StraightFlushHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightFlushFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Queen, CardType::Diamond));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));
    ASSERT_ANY_THROW(StraightFlushHandler().handle(cards));
}

TEST(HandHandlers, StraightFlushRoyalFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Diamond));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Spade));
    cards.push_back(Card(CardNumber::Jack, CardType::Spade));
    cards.push_back(Card(CardNumber::Queen, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Spade));
    ASSERT_ANY_THROW(StraightFlushHandler().handle(cards));
}

TEST(HandHandlers, StraightFlushFalseType) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));
    cards.push_back(Card(CardNumber::Queen, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Spade));
    ASSERT_ANY_THROW(StraightFlushHandler().handle(cards));
}
