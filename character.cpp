#include "character.h"

character::character() {
    this->name = "Chris";
    this->money = 0;

    this->modifiers = std::unordered_map<std::string, double>();

    this->health = 20;
    this->max_health = 20;

}

character::character(std::string name, int money) {
    this->name = name;
    this->money = money;

    this->modifiers = std::unordered_map<std::string, double>();

    this->health = 20;
    this->max_health = 20;
}

character::character(std::string name, int money, int speed, int phys, int agil, int mage, int health) {
    this->name = name;
    this->money = money;

    this->speed = speed;

    this->phys = phys;
    this->agil = agil;
    this->mage = mage;

    this->modifiers = std::unordered_map<std::string, double>();

    this->health = health;
    this->max_health = health;
}

character::character(std::string name, int money, int speed, int phys, int agil, int mage, int health, std::unordered_map<std::string, double> modifiers) {
    this->name = name;
    this->money = money;

    this->speed = speed;

    this->phys = phys;
    this->agil = agil;
    this->mage = mage;

    this->modifiers = modifiers;

    this->health = health;
    this->max_health = health;
}

double character::get_modifier(std::string mod_name) {
    return this->modifiers[mod_name];
}

void character::set_modifier(std::string name, double value) {
    this->modifiers[name] = value;
}

void character::reset_modifiers() {
    this->modifiers = std::unordered_map<std::string, double>();
}

// return true if successful, false if not
bool character::change_money(int change) {
    if (this->money - change >= 0) {
        this->money -= change;
        return true;
    } else {
        return false;
    }
}

bool character::is_alive() {
    return health > 0;
}

int character::get_speed() {
    return speed;
}

std::string character::get_name() {
    return this->name;
}