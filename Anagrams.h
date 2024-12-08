#ifndef ANAGRAMS_H
#define ANAGRAMS_H

#include "Game.h"

class Anagrams : public Game {
public:
    Anagrams();
    void play() override;
    void award_badge(Player* player) override;
};

#endif
