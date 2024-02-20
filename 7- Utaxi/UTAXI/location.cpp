#include "location.hpp"

Location::Location(vector<string> info)
{
    name = info[0];
    latitude = stof(info[1]);
    longitude = stof(info[2]);
}

string Location::get_name()
{
    return name;
}