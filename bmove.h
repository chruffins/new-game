#ifndef BMOVE_H
#define BMOVE_H

#include<iostream>
#include<string>
#include<vector>

typedef double (*attack_modifier)();
typedef void (*move_function)();

class bmove {
private:

std::string name;
std::string description;

int power;
float weight;

attack_modifier bonus;
move_function effect;

public:
    bmove();
    bmove(std::string, std::string, int, float, attack_modifier, move_function);
};

#endif