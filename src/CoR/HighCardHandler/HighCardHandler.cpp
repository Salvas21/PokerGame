//
// Created by Mickael Salvas on 2021-03-30.
//

#include "HighCardHandler.h"
#include "../HandHandlerHelper.h"

Hand HighCardHandler::handle(std::vector<Card> cards) {
    return Hand(HandRank::HighCard, HandHandlerHelper::sortCards(HandHandlerHelper::getHighestCards(cards, 5)));
}
