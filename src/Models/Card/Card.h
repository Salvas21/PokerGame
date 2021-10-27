//
// Created by Mickael Salvas on 2021-03-03.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H
enum CardType {
    Club, // Trefle
    Spade, // Pique
    Heart, // Coeur
    Diamond // Carreau
};

enum CardNumber {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Card {
public:
    Card(CardNumber number, CardType type);
    CardNumber getNumber();
    CardType getType();
    bool isLastOf(Card other);
    bool operator!=(const Card other);
private:
    CardNumber number;
    CardType type;
};


#endif //POKER_CARD_H
