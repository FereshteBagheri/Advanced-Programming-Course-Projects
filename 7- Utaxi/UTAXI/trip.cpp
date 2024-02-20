#include "trip.hpp"

Trip::Trip(int _passenger_index, int _origin_index, int _destination_index, string _passenger_name, int &trips_num)
{
    passenger_index = _passenger_index;
    origin_index = _origin_index;
    destination_index = _destination_index;
    passenger_name = _passenger_name;
    id = trips_num;
    status = WAITING_STATUS;
    cout << id << endl;
}

void Trip::print_trip_details(vector<Location> &locations)
{
    cout << id << " " << passenger_name << " ";
    cout << locations[origin_index].get_name() << " ";
    cout << locations[destination_index].get_name() << " " << status << endl;
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