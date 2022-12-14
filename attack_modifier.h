#ifndef ATTACK_MODIFIER_H
#define ATTACK_MODIFIER_H

// This file describes attack modifiers, which multiply damage and/or healing.

#include<unordered_map>
#include<string>

typedef double (*attack_modifier)(double);

namespace something
{
    extern std::unordered_map<std::string, attack_modifier> modifiers = {
        {"flammable", is_flammable},
    };

    double is_flammable(double flammable) {
        return flammable ? 2 : 1;
    }
} // namespace name


#endif