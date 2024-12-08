#include "Player.h"
#include <fstream>
#include <iostream>

Player::Player(string user, string pass) : username(user), password(pass) {}

string Player::get_username() {
    return username;
}

string Player::get_password() {
    return password;
}

void Player::add_badge(string badge) {
    badges.push_back(badge);
    save_data();
}

void Player::show_badges() {
    cout << "Badges earned: ";
    for (const auto& badge : badges) {
        cout << badge << " ";
    }
    cout << endl;
}

bool Player::load_data() {
    ifstream infile(username + ".txt");
    if (infile) {
        string badge;
        while (getline(infile, badge)) {
            badges.push_back(badge);
        }
        return true;
    }
    return false;
}

void Player::save_data() {
    ofstream outfile(username + ".txt");
    for (const auto& badge : badges) {
        outfile << badge << endl;
    }
}

int Player::get_badges_count() {
    return badges.size();
}