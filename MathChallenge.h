#ifndef MATHCHALLENGE_H
#define MATHCHALLENGE_H

#include "Game.h"

class MathChallenge : public Game {
public:
    MathChallenge();
    void play() override;
    void award_badge(Player* player) override;
};

#endif
