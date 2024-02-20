#ifndef TRIP_HPP
#define TRIP_HPP

#include "functions.hpp"

class Trip
{
public:
    Trip(int _passenger_index, int _origin_index, int _destination_index, string _passenger_name, int &trips_num,double _price);
    int get_id();
    string get_passenger();
    string get_status();
    void set_status(string _status);
    void set_driver(int _driver_index);
    int get_driver();
    double get_price();
    void print_trip_details(vector<Location> &locations);

private:

    string passenger_name;
    int passenger_index;
    int driver_index;
    int origin_index;
    int destination_index;
    int id;
    string status;
    double price;
};

#endif