#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Player; // Forward declaration of Player class

class Game {
public:
    Game(string t);
    virtual void play() = 0;  // Pure virtual function
    virtual void award_badge(Player* player) = 0;
protected:
    string title;
};

#endif
