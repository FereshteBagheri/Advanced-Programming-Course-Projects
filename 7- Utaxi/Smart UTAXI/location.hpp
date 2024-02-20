#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <vector>
#include "const.hpp"
#include"error.hpp"

class Location
{
public:
    Location(vector<string> info);
    string get_name();
    double calculate_dist(Location& destination);
    double calculate_price(Location& destination,string& in_hurry);

private:
    string name;
    double latitude;
    double longitude;
    int traffic;
};

#endif