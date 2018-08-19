#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

using std::string;
using std::vector;

enum GeomFig{
    CIRCUNF,
    SQUARE,
    TRIANG
};

enum PlayerColor {
    WHITE,
    BLACK,
    RED,
    BLUE,
    YELLOW,
    GREEN
};

struct Province {
    int id;
    int soldiers_count;
    int owner_id;

};

struct Objective {
    int id;
    string descript;
};

struct Cards {
    int id;
    int province_id;
    GeomFig figure;
    bool wildcard;

};

struct Player {
    int id;
    string name;
    Objective objective;
    vector<Cards> cards;
    PlayerColor color;
    string ip;
    int exchanges; 
};

struct Game {
    vector<Player> players;
    vector<Province> provinces;
    int current_player;
};

#endif
