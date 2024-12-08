#ifndef GUESSTHENUMBER_H
#define GUESSTHENUMBER_H

#include "Game.h"

class GuessTheNumber : public Game {
public:
    GuessTheNumber();
    void play() override;
    void award_badge(Player* player) override;
};

#endif
