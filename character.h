#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include<unordered_map>

class character {
private:
    std::string name;
    int money;

    int speed;

    int phys;
    int agil;
    int mage;

    std::unordered_map<std::string, double> modifiers;
public:
    character();
    character(std::string, int);
    character(std::string, int, int, int, int, int);
    character(std::string, int, int, int, int, int, std::unordered_map<std::string, double>);

    double get_modifier(std::string);
    void set_modifier(std::string, double);
    void reset_modifiers();

    bool change_money(int);
};

character::character() {
    this->name = "Chris";
    this->money = 0;

    this->modifiers = std::unordered_map<std::string, double>();
}

character::character(std::string name, int money) {
    this->name = name;
    this->money = money;

    this->modifiers = std::unordered_map<std::string, double>();
}

character::character(std::string name, int money, int speed, int phys, int agil, int mage) {
    this->name = name;
    this->money = money;

    this->speed = speed;

    this->phys = phys;
    this->agil = agil;
    this->mage = mage;

    this->modifiers = std::unordered_map<std::string, double>();
}

character::character(std::string name, int money, int speed, int phys, int agil, int mage, std::unordered_map<std::string, double> modifiers) {
    this->name = name;
    this->money = money;

    this->speed = speed;

    this->phys = phys;
    this->agil = agil;
    this->mage = mage;

    this->modifiers = modifiers;
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

#endif