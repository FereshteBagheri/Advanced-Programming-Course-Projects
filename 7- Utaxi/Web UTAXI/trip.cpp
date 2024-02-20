#include "trip.hpp"
#include <iomanip>

Trip::Trip(int _passenger_index, int _origin_index, int _destination_index, string _passenger_name, int &trips_num, double _price)
{
    passenger_index = _passenger_index;
    origin_index = _origin_index;
    destination_index = _destination_index;
    passenger_name = _passenger_name;
    id = trips_num;
    status = WAITING_STATUS;
    price = _price;
}

string Trip::print_trip_details(vector<Location> &locations)
{
    string details;
    details += to_string(id);
    details+=" ";
    details += passenger_name;
    details+=" ";
    details += locations[origin_index].get_name();
    details+=" ";
    details += locations[destination_index].get_name();
    details+=" ";
    details+=status;
    details+=" ";
    details += to_string(price);

    return details;
}

int Trip::get_id()
{
    return id;
}

string Trip::get_passenger()
{
    return passenger_name;
}

string Trip::get_status()
{
    return status;
}

void Trip::set_status(string _status)
{
    status = _status;
}

void Trip::set_driver(int _driver_index)
{
    driver_index = _driver_index;
}

int Trip::get_driver()
{
    return driver_index;
}

double Trip::get_price()
{
    return price;
}