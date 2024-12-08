#include "Anagrams.h"
#include "Player.h"
#include <iostream>

Anagrams::Anagrams() : Game("Anagrams") {}

void Anagrams::play() {
    string word = "puzzle";
    string scrambled_word = "epluzz";

    string user_guess;
    cout << "Unscramble this word: " << scrambled_word << "\n";
    cout << "Your guess: ";
    cin >> user_guess;

    if (user_guess == word) {
        cout << "Correct! You've earned the Anagram Badge.\n";
    }
    else {
        cout << "Incorrect answer. Try again!\n";
    }
}

void Anagrams::award_badge(Player* player) {
    player->add_badge("Anagram Badge");
}