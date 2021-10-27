//
// Created by Mickael Salvas on 2021-02-28.
//

#ifndef POKER_POKERGAME_H
#define POKER_POKERGAME_H

class PokerGame {
public:
    static const int MIN_CHOICE = 0;
    static const int MAX_CHOICE = 4;
    void start();

private:
    void printMenu();
    void printPokerChoice();
    int getPokerChoice();
    int getPlayersNb(int min, int max);
    bool choiceIsInvalid(int choice);
    bool playersNbIsInvalid(int min, int max, int nb);
    void invalidChoiceMessage();
    void invalidPlayersNbMessage(int min, int max);
    void unImplementedMsg();
    int getPlayingChoice();
};


#endif //POKER_POKERGAME_H
