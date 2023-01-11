#ifndef BATTLE_H
#define BATTLE_H

#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
#include<iostream>

#include "character.h"
#include "bmove.h"

enum BATTLE_SIDE {
    ALLIES = 0,
    ENEMIES = 1,
    NONE = 2,
};

class battle {
private:
    std::vector<character> player_characters;
    std::vector<character> enemy_characters;
    std::priority_queue<bmove_description> moves;

    bool is_players_dead();
public:
    battle();
    
    bool is_ended();
    int get_winners();

    std::vector<character> get_players();
    std::vector<character> get_enemies();
    character get_player_character(int);
    character get_enemy_character(int);
};

#endif