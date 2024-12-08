#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

using namespace std;

class Player {
public:
    Player(string user, string pass);

    string get_username();
    string get_password();
    void add_badge(string badge);
    void show_badges();
    bool load_data();
    void save_data();
    int get_badges_count();

private:
    string username;
    string password;
    vector<string> badges;
};

#endif
