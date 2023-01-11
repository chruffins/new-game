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
    bmove_description(std::string, char);

    bool has_bonus();
    bool has_effect();
    void print();
};

class bmove : bmove_description {
private:
    character *user;
public:
    //bmove(); is this really necessary?
    bmove(bmove_description, character*);

    int get_speed();
    void print();
};

#endif