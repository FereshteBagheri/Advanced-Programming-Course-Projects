#include "location.hpp"
#include <math.h>

Location::Location(vector<string> info)
{
    name = info[0];
    latitude = stod(info[1]);
    longitude = stod(info[2]);
    traffic=stoi(info[3]);
}

string Location::get_name()
{
    return name;
}

double Location ::calculate_dist(Location &destination)
{
    double dist = DEGREE_LENGTH * sqrt(pow((destination.latitude - latitude), 2) + pow((destination.longitude - longitude), 2));
    return dist;
}

double Location ::calculate_price(Location &destination, string &in_hurry)
{
    double regular_price = calculate_dist(destination) * (destination.traffic + traffic) * CONST_AMOUNT;
    if (in_hurry == "yes")
    {
        return regular_price * IN_HURRY_COEFFICIENT;
    }
    else if (in_hurry == "no")
    {
        return regular_price;
    }
    else
    {
        throw Error(BAD_REQUEST);
    }
}