#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <vector>
#include "Player.h"
#include "Game.h"
#include "MathChallenge.h"
#include "Anagrams.h"
#include "MissingNumber.h"
#include "GuessTheNumber.h"

class PuzzleGame {
public:
    PuzzleGame();
    void signup();
    void login();
    void play_game();
    void show_badges();
    void leaderboard();
    void menu();

private:
    std::vector<Player*> players;
    std::vector<Game*> games;
    Player* current_player = nullptr;
};

#endif
