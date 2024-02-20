#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <vector>
#include "const.hpp"

class Location
{
public:
    Location(vector<string> info);
    string get_name();

private:
    string name;
    float latitude;
    float longitude;
};

#endif