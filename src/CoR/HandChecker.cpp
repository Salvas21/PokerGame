//
// Created by Mickael Salvas on 2021-03-26.
//

#include "HandChecker.h"

#include <utility>
#include "StraightFlushHandler/StraightFlushHandler.h"
#include "RoyalFlushHandler/RoyalFlushHandler.h"
#include "FourOfKindHandler/FourOfKindHandler.h"
#include "FullHouseHandler/FullHouseHandler.h"
#include "FlushHandler/FlushHandler.h"
#include "StraightHandler/StraightHandler.h"
#include "ThreeOfKindHandler/ThreeOfKindHandler.h"
#include "TwoPairHandler/TwoPairHandler.h"
#include "PairHandler/PairHandler.h"
#include "HighCardHandler/HighCardHandler.h"

Hand HandChecker::checkHand(std::vector<Card> cards) {
    initHandlers();
    chainHandlers();
    auto hand = handle(std::move(cards));
    deleteHandlers();
    return hand;
}

void HandChecker::initHandlers() {
    royalFlush = new RoyalFlushHandler;
    straightFlush = new StraightFlushHandler;
    fourOfKind = new FourOfKindHandler;
    fullHouse = new FullHouseHandler;
    flush = new FlushHandler;
    straight = new StraightHandler;
    threeOfKind = new ThreeOfKindHandler;
    twoPair = new TwoPairHandler;
    pair = new PairHandler;
    highCard = new HighCardHandler;
}

void HandChecker::chainHandlers() {
    royalFlush->setNext(straightFlush)
    ->setNext(fourOfKind)
    ->setNext(fullHouse)
    ->setNext(flush)
    ->setNext(straight)
    ->setNext(threeOfKind)
    ->setNext(twoPair)
    ->setNext(pair)
    ->setNext(highCard);
}

Hand HandChecker::handle(std::vector<Card> cards) {
    return royalFlush->handle(cards);
}

void HandChecker::deleteHandlers() {
    delete pair;
    delete twoPair;
    delete threeOfKind;
    delete straight;
    delete flush;
    delete fullHouse;
    delete fourOfKind;
    delete straightFlush;
    delete royalFlush;
}


