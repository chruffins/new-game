#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include<unordered_map>

class character {
private:
    std::string name;
    int money;

    int health;
    int max_health;

    int speed;

    int phys;
    int agil;
    int mage;

    //std::vector<bmove_description> moves;
    std::unordered_map<std::string, double> modifiers;
public:
    character();
    character(std::string, int);
    character(std::string, int, int, int, int, int, int);
    character(std::string, int, int, int, int, int, int, std::unordered_map<std::string, double>);

    double get_modifier(std::string);
    void set_modifier(std::string, double);
    void reset_modifiers();

    bool change_money(int);
    bool is_alive();

    int get_speed();

    std::string get_name();
};

#endif