#include "utaxi.hpp"
#include <iomanip>

vector<Trip> Utaxi::get_trips()
{
    return trips;
}
bool Utaxi::user_does_exist(string username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (username == users[i]->get_username())
        {
            return true;
        }
    }
    return false;
}

string Utaxi::find(string info)
{
    for (int i = 3; i < command_parts.size() - 1; i += 2)
    {
        if (command_parts[i] == info)
        {
            return command_parts[i + 1];
        }
    }
    return "";
}

void Utaxi::signup(string &username, string &role)
{

    if (user_does_exist(username))
    {
        throw Error(BAD_REQUEST);
    }
    if (role == "passenger")
    {
        User *new_user = new Passenger(username);
        users.push_back(new_user);
    }
    else if (role == "driver")
    {
        User *new_user = new Driver(username);
        users.push_back(new_user);
    }
    else
    {
        throw Error(BAD_REQUEST);
    }
}

void Utaxi ::add_locations(char *argv[])
{
    locations = save_locations(argv);
}

int Utaxi::find_location(string name)
{
    for (int i = 0; i < locations.size(); i++)
    {
        if (locations[i].get_name() == name)
        {
            return i;
        }
    }
    throw Error(NOT_FOUND);
}

int Utaxi::find_user(string username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_username() == username)
        {
            return i;
        }
    }
    throw Error(NOT_FOUND);
}
double Utaxi ::calculate_price(string &username, string &origin, string &destination, string &in_hurry)
{
    int user_index = find_user(username);
    users[user_index]->check_costs_accessability();
    int origin_index = find_location(origin);
    int destination_index = find_location(destination);
    double price = locations[origin_index].calculate_price(locations[destination_index], in_hurry);
    return price;
}

void Utaxi::request_trip(string &passenger_name, string &origin, string &destination, string &in_hurry)
{
    if (origin.empty() || destination.empty() || passenger_name.empty())
    {
        throw Error(BAD_REQUEST);
    }
    int origin_index = find_location(origin);
    int destination_index = find_location(destination);
    int user_index = find_user(passenger_name);
    double price = locations[origin_index].calculate_price(locations[destination_index], in_hurry);
    users[user_index]->request_trip(origin_index, destination_index, user_index, trips, trips_num, price);
}

string Utaxi::trip_details(string &username, int &trip_id)
{
    int user_index = find_user(username);
    users[user_index]->check_trips_accessability();

    int trip_index = find_trip(trip_id);
    return trips[trip_index].print_trip_details(locations);
}

int Utaxi ::find_trip(int &trip_id)
{
    for (int i = 0; i < trips.size(); i++)
    {
        if (trip_id == trips[i].get_id())
        {
            return i;
        }
    }
    throw Error(NOT_FOUND);
}

void Utaxi::trips_list(string &username, string &sort_status,string& body)
{
    int user_index = find_user(username);
    if (sort_status == "no")
    {
        users[user_index]->check_trips_accessability();

        if (trips.size() == 0)
        {
            throw Error(EMPTY);
        }
        for (int i = 0; i < trips.size(); i++)
        {
            body+= trips[i].print_trip_details(locations);
            body+="<br><br>";
        }
    }
    else if (sort_status == "yes")
    {
        vector<int> sorted_trip_index = sort_trips_index(trips);
        for (int i = 0; i < trips.size(); i++)
        {
            body += trips[sorted_trip_index[i]].print_trip_details(locations);
            body += "<br><br>";
        }
    }
}

vector<int> Utaxi ::sort_trips_index(vector<Trip> &trips)
{
    vector<int> sorted_trip_index;
    for (int i = 0; i < trips.size(); i++)
    {
        sorted_trip_index.push_back(i);
    }
    for (int i = 0; i < trips.size() - 1; i++)
    {
        for (int j = i + 1; j < trips.size(); j++)
        {
            if (trips[sorted_trip_index[i]].get_price() < trips[sorted_trip_index[j]].get_price())
            {
                swap(sorted_trip_index[i], sorted_trip_index[j]);
            }
        }
    }
    return sorted_trip_index;
}

void Utaxi ::accept_trip(string& driver_name, int& trip_id)
{
    int driver_index = find_user(driver_name);
    int trip_index = find_trip(trip_id);
    int passenger_index = find_user(trips[trip_index].get_passenger());
    users[driver_index]->accept_trip(trips, trip_index);
    trips[trip_index].set_driver(driver_index);
    users[passenger_index]->start_travelling();
}

void Utaxi :: cancel_trip(string& username,int& trip_id){

        int user_index = find_user(username);
        int trip_index = find_trip(trip_id);
        users[user_index]->delete_trip(trips, trip_index);
}

void Utaxi :: finish_trip(string& driver_name,int& trip_id){

    int driver_index = find_user(driver_name);
    int trip_index = find_trip(trip_id);
    if (trips[trip_index].get_driver() != driver_index)
    {
        throw Error(PERMISSION_DENIED);
    }
    trips[trip_index].set_status("finished");
    users[driver_index]->finish_travelling();
    int passenger_index = find_user(trips[trip_index].get_passenger());
    users[passenger_index]->finish_travelling();
}