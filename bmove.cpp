#include "bmove.h"

// bmove_description definitions

bmove_description::bmove_description() {
    name = "Punch";
    description = "The user throws a punch at a target.";

    power = 20;
    weight = 0.1;

    bonus = NULL;
    effect = NULL;
}

bmove_description::bmove_description(bmove_description& other) {
    this->name = other.name;
    this->description = other.description;
    
    this->power = other.power;
    this->weight = other.weight;

    this->bonus = other.bonus;
    this->effect = other.effect;

    this->effect_chance = other.effect_chance;
}

bmove_description::bmove_description(std::string name, std::string description, int power, float weight, attack_modifier bonus, move_function effect) {
    this->name = name;
    this->description = description;
    
    this->power = power;
    this->weight = weight;

    this->bonus = bonus;
    this->effect = effect;
}

bmove_description::bmove_description(std::string csv, char delimiter = '\t') {
    // TODO: finish this
}

bool bmove_description::has_bonus() {
    return this->bonus != NULL;
}

bool bmove_description::has_effect() {
    return this->effect != NULL;
}

void bmove_description::print() {
    std::cout << this->name << std::endl;
    std::cout << this->description << std::endl;
}

// bmove definitions

bmove::bmove(bmove_description move_desc, character *user) : bmove_description(move_desc) {
    this->user = user;
}

int bmove::get_speed() {
    return user->get_speed();
}

void bmove::print() {
    std::cout << this->user->get_name() << " used " << this->name << "! (" << this->get_speed() << ")" << std::endl;
}