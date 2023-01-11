#include "bmove_list.h"

std::unordered_map<std::string, bmove_description> bmoves_list;

std::unordered_map<std::string, bmove_description> import_moves() {
    std::ifstream fp = std::ifstream("res\\bmove_data.txt", std::ifstream::in);
    std::vector<std::string> arg_list = std::vector<std::string>();
    std::string line;

    while (!fp.eof()) {
        std::getline(fp, line);
        if (line[0] == '\\') continue;
        //std::cout << line << std::endl;

        arg_list = util::split_into_vector(line, '\t');
        for (int i = 0; i < arg_list.size(); i++) {
            std::cout << arg_list[i] << std::endl;
        }
    }

    return std::unordered_map<std::string, bmove_description>();
}