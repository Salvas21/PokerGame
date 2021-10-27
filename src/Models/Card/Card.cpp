//
// Created by Mickael Salvas on 2021-03-03.
//

#include "Card.h"

Card::Card(CardNumber number, CardType type) {
    Card::number = number;
    Card::type = type;
}

CardNumber Card::getNumber() {
    return number;
}

CardType Card::getType() {
    return type;
}

bool Card::isLastOf(Card other) {
    return this->number + 1 == other.number && this->type == other.type;
}

bool Card::operator!=(const Card other) {
    return !(this->number == other.number && this->type == other.type);
}
