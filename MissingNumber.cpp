#include "MissingNumber.h"
#include "Player.h"
#include <iostream>

MissingNumber::MissingNumber() : Game("Missing Number") {}

void MissingNumber::play() {
    int sequence[] = { 1, 2, 3, 5, 6 };
    int correct_answer = 4;

    int user_answer;
    cout << "What number is missing in this sequence: 1, 2, 3, __, 5, 6?\n";
    cout << "Your guess: ";
    cin >> user_answer;

    if (user_answer == correct_answer) {
        cout << "Correct! You've earned the Missing Number Badge.\n";
    }
    else {
        cout << "Incorrect answer. Try again!\n";
    }
}

void MissingNumber::award_badge(Player* player) {
    player->add_badge("Missing Number Badge");
}