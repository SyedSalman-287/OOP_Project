#include "GuessTheNumber.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <limits>

GuessTheNumber::GuessTheNumber() : Game("Guess The Number") {}

void GuessTheNumber::play() {
    int target_number = rand() % 100 + 1;
    int user_guess;

    cout << "Guess a number between 1 and 100: ";
    while (true) {
        cin >> user_guess;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
            continue;
        }

        if (user_guess == target_number) {
            cout << "Correct! You've earned the Guess The Number Badge.\n";
            break;
        }
        else if (user_guess < target_number) {
            cout << "Too low! Try again: ";
        }
        else {
            cout << "Too high! Try again: ";
        }
    }
}

void GuessTheNumber::award_badge(Player* player) {
    player->add_badge("Guess The Number Badge");
}