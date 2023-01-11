#ifndef BMOVE_LIST_H
#define BMOVE_LIST_H

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

#include "bmove.h"
#include "utility.h"

extern std::unordered_map<std::string, bmove_description> bmoves_list;
std::unordered_map<std::string, bmove_description> import_moves();

#endif