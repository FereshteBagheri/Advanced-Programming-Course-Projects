#include "user.hpp"

User::User(string _username)
{
    username = _username;
}

string User::get_username()
{
    return username;
}

void User::request_trip(int origin_index, int destination_indexint, int user_index, vector<Trip> &trips, int &trips_num)
{
    throw Error(PERMISSION_DENIED);
}

void User::check_trips_accessability()
{
    throw Error(PERMISSION_DENIED);
}

void User::delete_trip(vector<Trip> &trips, int trip_index)
{
    throw Error(PERMISSION_DENIED);
}

void User::accept_trip(vector<Trip> &trips, int trip_index)
{
    throw Error(PERMISSION_DENIED);
}

void User::start_travelling()
{
    is_travelling = true;
}

void User::finish_travelling()
{
    is_travelling = false;
}

void Passenger::request_trip(int origin_index, int destination_index, int user_index, vector<Trip> &trips, int &trips_num)
{
    if (is_travelling)
    {
        throw Error(BAD_REQUEST);
    }
    else
    {
        trips_num++;
        Trip new_trip(user_index, origin_index, destination_index, username, trips_num);
        trips.push_back(new_trip);
    }
}

void Passenger::delete_trip(vector<Trip> &trips, int trip_index)
{
    if (username != trips[trip_index].get_passenger())
    {
        throw Error(PERMISSION_DENIED);
    }
    if (trips[trip_index].get_status() != WAITING_STATUS)
    {
        throw Error(BAD_REQUEST);
    }
    trips.erase(trips.begin() + trip_index);
}

void Driver::accept_trip(vector<Trip> &trips, int trip_index)
{
    if (is_travelling)
    {
        throw Error(BAD_REQUEST);
    }
    trips[trip_index].set_status(TRAVELLING_STATUS);
    start_travelling();
}