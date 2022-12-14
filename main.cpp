#include<iostream>

#include <allegro5/allegro.h>

#include "error_codes.h"

void print_copyright_notice() {
    std::cout << "Chris's New Game  Copyright (C) 2022  Chris Lee" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; whatever that means." << std::endl;
}

void must_init(bool test, const char *test_name) {
    if (test) return;

    std::cout << "Failed to initialize " << test_name << "!" << std::endl;
    exit(ERROR_INIT);
}

int main() {
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    print_copyright_notice();
    //std::cout << "size of long = " << sizeof(long) << std::endl;
}