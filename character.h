#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include<unordered_map>

class character {
private:
    std::string name;
    int money;
    std::unordered_map<std::string, double> modifiers;
public:
    character();
    character(std::string, int);

    double get_modifier(std::string);
    void set_modifier(std::string, double);

    void change_money(int);
};

#endif