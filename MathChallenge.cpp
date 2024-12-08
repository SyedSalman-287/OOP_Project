#include "MathChallenge.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <limits>

MathChallenge::MathChallenge() : Game("Math Challenge") {}

void MathChallenge::play() {
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int correct_answer = num1 + num2;

    int user_answer;
    cout << "What is " << num1 << " + " << num2 << "? ";

    while (true) {
        cin >> user_answer;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else {
            break;
        }
    }

    if (user_answer == correct_answer) {
        cout << "Correct! You've earned the Math Badge.\n";
    }
    else {
        cout << "Incorrect answer. Try again!\n";
    }
}

void MathChallenge::award_badge(Player* player) {
    player->add_badge("Math Badge");
}