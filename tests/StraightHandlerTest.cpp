//
// Created by Mickael Salvas on 2021-03-24.
//

#include "../src/CoR/StraightHandler/StraightHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, StraighTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Two, CardType::Diamond));
    cards.push_back(Card(CardNumber::Three, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Queen, CardType::Heart));
    cards.push_back(Card(CardNumber::King, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Club));
    hand.push_back(Card(CardNumber::Two, CardType::Diamond));
    hand.push_back(Card(CardNumber::Three, CardType::Spade));
    hand.push_back(Card(CardNumber::Four, CardType::Spade));
    hand.push_back(Card(CardNumber::Five, CardType::Diamond));

    Hand expected = Hand(HandRank::Straight, hand);
    Hand received = StraightHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightTrueDuplicate) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Club));
    cards.push_back(Card(CardNumber::Two, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Club));
    cards.push_back(Card(CardNumber::Four, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Club));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Two, CardType::Heart));
    hand.push_back(Card(CardNumber::Three, CardType::Club));
    hand.push_back(Card(CardNumber::Four, CardType::Diamond));
    hand.push_back(Card(CardNumber::Five, CardType::Club));

    Hand expected = Hand(HandRank::Straight, hand);
    Hand received = StraightHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightTrueNewCount) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Six, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Diamond));
    cards.push_back(Card(CardNumber::Nine, CardType::Club));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));
    cards.push_back(Card(CardNumber::Jack, CardType::Club));
    cards.push_back(Card(CardNumber::Queen, CardType::Heart));
    cards.push_back(Card(CardNumber::King, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Nine, CardType::Club));
    hand.push_back(Card(CardNumber::Ten, CardType::Heart));
    hand.push_back(Card(CardNumber::Jack, CardType::Club));
    hand.push_back(Card(CardNumber::Queen, CardType::Heart));
    hand.push_back(Card(CardNumber::King, CardType::Spade));

    Hand expected = Hand(HandRank::Straight, hand);
    Hand received = StraightHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightTrueHighAce) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Club));
    cards.push_back(Card(CardNumber::Three, CardType::Club));
    cards.push_back(Card(CardNumber::Ten, CardType::Diamond));
    cards.push_back(Card(CardNumber::Jack, CardType::Club));
    cards.push_back(Card(CardNumber::Queen, CardType::Heart));
    cards.push_back(Card(CardNumber::King, CardType::Diamond));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Ten, CardType::Diamond));
    hand.push_back(Card(CardNumber::Jack, CardType::Club));
    hand.push_back(Card(CardNumber::Queen, CardType::Heart));
    hand.push_back(Card(CardNumber::King, CardType::Diamond));

    Hand expected = Hand(HandRank::Straight, hand);
    Hand received = StraightHandler().handle(cards);

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, StraightFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Three, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Heart));
    cards.push_back(Card(CardNumber::Nine, CardType::Club));
    cards.push_back(Card(CardNumber::Jack, CardType::Heart));
    cards.push_back(Card(CardNumber::King, CardType::Spade));
    ASSERT_ANY_THROW(StraightHandler().handle(cards));
}

TEST(HandHandlers, StraightFalseNewCount) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Five, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Diamond));
    cards.push_back(Card(CardNumber::Eight, CardType::Club));
    cards.push_back(Card(CardNumber::Nine, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Club));
    cards.push_back(Card(CardNumber::Queen, CardType::Heart));
    cards.push_back(Card(CardNumber::King, CardType::Spade));
    ASSERT_ANY_THROW(StraightHandler().handle(cards));
}
