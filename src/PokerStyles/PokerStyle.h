//
// Created by Mickael Salvas on 2021-03-01.
//

#ifndef POKER_POKERSTYLE_H
#define POKER_POKERSTYLE_H

class PokerStyle {
public:
    virtual ~PokerStyle();
    virtual void play(int playersNb) = 0;
    void setPlayerAmount(int min, int max);
    int getMinPlayers() const;
    int getMaxPlayers() const;

private:
    int minPlayers;
    int maxPlayers;

};


#endif //POKER_POKERSTYLE_H
