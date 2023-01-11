#include "utility.h"

std::vector<std::string> util::split_into_vector(std::string line, char delimiter)
{
    std::vector<std::string> string_list = std::vector<std::string>();
    std::stringstream ss = std::stringstream(line);
    std::string element;

    while (!ss.eof()) {
        std::getline(ss, element, delimiter);
        string_list.push_back(element);
    }
    return string_list;
}