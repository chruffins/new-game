#include "battle.h"

battle::battle() {
    character a = character("Chris", 9001, 38, 4, 5, 6, 50);
    character b = character("Hannah", 5, 44, 4, 6, 5, 40);
    character c = character("Vince", 420, 41, 6, 5, 4, 55);

    player_characters.push_back(a);
    player_characters.push_back(b);
    player_characters.push_back(c);

    character x = character("Stupid Bitch", -1, 10, 3, 3, 0, 10);
    character y = character("Fat Man", 50, 1, 9, 1, 3, 100);
    character z = character("Rich Guy", 1000000, 30, 5, 5, 5, 50);

    enemy_characters.push_back(x);
    enemy_characters.push_back(y);
    enemy_characters.push_back(z);
}

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
    return NONE;
}

character battle::get_player_character(int index) {
    return this->player_characters[index];
}

character battle::get_enemy_character(int index) {
    return this->enemy_characters[index];
}