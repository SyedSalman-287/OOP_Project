#ifndef MISSINGNUMBER_H
#define MISSINGNUMBER_H

#include "Game.h"

class MissingNumber : public Game {
public:
    MissingNumber();
    void play() override;
    void award_badge(Player* player) override;
};

#endif
