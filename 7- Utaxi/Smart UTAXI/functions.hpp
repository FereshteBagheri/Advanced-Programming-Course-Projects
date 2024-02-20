#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <fstream>
#include <sstream>
#include "location.hpp"

vector<string> read_lines_from_file(char *argv[]);
vector<string> split_string(string &input, char delimiter);
vector<Location> save_locations(char *argv[]);

#endif