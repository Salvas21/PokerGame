//
// Created by Mickael Salvas on 2021-03-24.
//

#include "../src/CoR/FullHouseHandler/FullHouseHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, FullHouseTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Heart));
    cards.push_back(Card(CardNumber::Five, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Club));
    hand.push_back(Card(CardNumber::Ace, CardType::Spade));
    hand.push_back(Card(CardNumber::Five, CardType::Heart));
    hand.push_back(Card(CardNumber::Five, CardType::Club));
    hand.push_back(Card(CardNumber::Five, CardType::Diamond));

    Hand expected = Hand(HandRank::FullHouse, hand);
    Hand received = FullHouseHandler().handle(cards);
    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, FullHouseFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Spade));
    cards.push_back(Card(CardNumber::Two, CardType::Diamond));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Five, CardType::Spade));
    ASSERT_ANY_THROW(FullHouseHandler().handle(cards));
}

TEST(HandHandlers, FullHouseFalseWhatWasThatBugWaitIWasDumb) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Four, CardType::Spade));
    cards.push_back(Card(CardNumber::Four, CardType::Diamond));
    cards.push_back(Card(CardNumber::Four, CardType::Club));
    cards.push_back(Card(CardNumber::Seven, CardType::Heart));
    cards.push_back(Card(CardNumber::Eight, CardType::Spade));
    cards.push_back(Card(CardNumber::Nine, CardType::Diamond));
    cards.push_back(Card(CardNumber::Jack, CardType::Club));
    ASSERT_ANY_THROW(FullHouseHandler().handle(cards));
}
