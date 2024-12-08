#include "PuzzleGame.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

PuzzleGame::PuzzleGame() {
    srand(time(0));
    games.push_back(new MathChallenge());
    games.push_back(new Anagrams());
    games.push_back(new MissingNumber());
    games.push_back(new GuessTheNumber());
}

void PuzzleGame::signup() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    Player* new_player = new Player(username, password);
    if (new_player->load_data()) {
        cout << "Player data loaded successfully!" << endl;
    }
    else {
        cout << "No data found for this player. New account created." << endl;
    }
    players.push_back(new_player);
    current_player = new_player;
}

void PuzzleGame::login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (auto& player : players) {
        if (player->get_username() == username && player->get_password() == password) {
            cout << "Logged in successfully!" << endl;
            current_player = player;
            return;
        }
    }
    cout << "Invalid username or password." << endl;
}

void PuzzleGame::play_game() {
    if (!current_player) {
        cout << "Please login first to play!" << endl;
        return;
    }

    Game* game = games[rand() % games.size()];
    game->play();
    game->award_badge(current_player);
}

void PuzzleGame::show_badges() {
    if (!current_player) {
        cout << "Please login first to view badges!" << endl;
        return;
    }

    current_player->show_badges();
}

void PuzzleGame::leaderboard() {
    if (players.empty()) {
        cout << "No players have signed up yet." << endl;
        return;
    }

    cout << "Leaderboard:\n";
    for (auto& player : players) {
        cout << player->get_username() << " - " << player->get_badges_count() << " badges\n";
    }
}

void PuzzleGame::menu() {
    while (true) {
        int choice;
        cout << "\n1. Sign Up\n2. Log In\n3. Play Game\n4. View Badges\n5. View Leaderboard\n6. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number (1-6): ";
        }

        switch (choice) {
        case 1: signup(); break;
        case 2: login(); break;
        case 3: play_game(); break;
        case 4: show_badges(); break;
        case 5: leaderboard(); break;
        case 6: cout << "Exiting game...\n"; return;
        default: cout << "Invalid choice! Please select a valid option (1-6).\n"; break;
        }
    }
}