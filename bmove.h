#ifndef BMOVE_H
#define BMOVE_H

#include<iostream>
#include<string>
#include<vector>

#include "character.h"

typedef double (*attack_modifier)();
typedef void (*move_function)();

enum bmove_targets {
    SELF,
    ONE,
    MANY,
    ALL,
};

class bmove;
class bmove_description;

class bmove_description {
protected:

std::string name;
std::string description;

int power;
float weight;

attack_modifier bonus;
attack_modifier override_damage;
move_function effect;

int effect_chance;

public:
    bmove_description();
    bmove_description(bmove_description&);
    bmove_description(std::string, std::string, int, float, attack_modifier, move_function);

    bool has_bonus();
    bool has_effect();
    void print();
};

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

class bmove : bmove_description {
private:
    character *user;
public:
    //bmove(); is this really necessary?
    bmove(bmove_description, character*);

    int get_speed();
    // void print();
};

bmove::bmove(bmove_description move_desc, character *user) {
    //bmove_description(move_desc);

    this->user = user;
}

int bmove::get_speed() {
    return user->get_speed();
}

#endif