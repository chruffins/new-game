#ifndef SIDE_EFFECT_H
#define SIDE_EFFECT_H

#include<string>

class side_effect {
private:
    std::string name;
    int chance;
public:
    side_effect();
    side_effect(std::string, int);
    void apply();
};

side_effect::side_effect() {
    name = "oil";
    chance = 100;
}

side_effect::side_effect(std::string name, int chance) {
    this->name = name;
    this->chance = chance;
}

void side_effect::apply() {
    return;
}

#endif