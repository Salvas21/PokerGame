//
// Created by Mickael Salvas on 2021-03-23.
//

#include "../src/CoR/PairHandler/PairHandler.h"
#include "gtest/gtest.h"

TEST(HandHandlers, PairTrue) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Ace, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));

    std::vector<Card> hand;
    hand.push_back(Card(CardNumber::Ace, CardType::Club));
    hand.push_back(Card(CardNumber::Ace, CardType::Diamond));
    hand.push_back(Card(CardNumber::Three, CardType::Heart));
    hand.push_back(Card(CardNumber::Four, CardType::Heart));
    hand.push_back(Card(CardNumber::Ten, CardType::Heart));

    Hand expected = Hand(HandRank::Pair, hand);
    Hand received = PairHandler().handle(cards);

//    for (auto card : received.getHandCards()) {
//        std::cout << card.getNumber() << std::endl;
//    }

    ASSERT_TRUE(expected == received);
}

TEST(HandHandlers, PairFalse) {
    std::vector<Card> cards;
    cards.push_back(Card(CardNumber::Ace, CardType::Club));
    cards.push_back(Card(CardNumber::Five, CardType::Diamond));
    cards.push_back(Card(CardNumber::Two, CardType::Spade));
    cards.push_back(Card(CardNumber::King, CardType::Heart));
    cards.push_back(Card(CardNumber::Four, CardType::Heart));
    cards.push_back(Card(CardNumber::Three, CardType::Heart));
    cards.push_back(Card(CardNumber::Ten, CardType::Heart));

    ASSERT_ANY_THROW(PairHandler().handle(cards));
}