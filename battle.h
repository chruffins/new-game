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

bool battle::is_ended() {
    // TODO: actually fix this
    return enemy_characters.size() == 0; // fix this later!!
}

bool battle::is_players_dead() {
    for (int i = 0; i < player_characters.size(); i++) {
        if (player_characters[i].is_alive()) {
            return false;
        }
    }
    return true;
}

int battle::get_winners() {
    if (enemy_characters.size() == 0) {
        return ALLIES;
    } else if (is_players_dead()) {
        return ENEMIES;
    }
}

character battle::get_player_character(int index) {
    return this->player_characters[index];
}

character battle::get_enemy_character(int index) {
    return this->enemy_characters[index];
}

#endif