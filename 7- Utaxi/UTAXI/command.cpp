#include "command.hpp"

Command ::Command(vector<string> parts)
{
    type = parts[1];
    command_parts = parts;
}

bool Command::user_does_exist(vector<User *> &users, string username)
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

string Command::find(string info)
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

int Command::find_location(vector<Location> &locations, string name)
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

int Command::find_user(vector<User *> &users, string username)
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

int Command ::find_trip(vector<Location> &locations, vector<Trip> &trips, int trip_id)
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

void Post::signup(vector<User *> &users)
{
    string username = find("username");
    string role = find("role");
    if (user_does_exist(users, username))
    {
        throw Error(BAD_REQUEST);
    }
    if (role == "passenger")
    {
        User *new_user = new Passenger(username);
        users.push_back(new_user);
        cout << OK << endl;
    }
    else if (role == "driver")
    {
        User *new_user = new Driver(username);
        users.push_back(new_user);
        cout << OK << endl;
    }
    else
    {
        throw Error(BAD_REQUEST);
    }
}

void Post::request_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num)
{
    string origin = find("origin");
    string destination = find("destination");
    string passenger_name = find("username");
    if (origin.empty() || destination.empty() || passenger_name.empty())
    {
        throw Error(BAD_REQUEST);
    }
    int origin_index = find_location(locations, origin);
    int destination_index = find_location(locations, destination);
    int user_index = find_user(users, passenger_name);
    users[user_index]->request_trip(origin_index, destination_index, user_index, trips, trips_num);
}

void Post ::accept_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips)
{
    string driver_name = find("username");
    int driver_index = find_user(users, driver_name);
    int trip_id = stoi(find("id"));
    int trip_index = find_trip(locations, trips, trip_id);
    int passenger_index = find_user(users, trips[trip_index].get_passenger());
    users[driver_index]->accept_trip(trips, trip_index);
    trips[trip_index].set_driver(driver_index);
    users[passenger_index]->start_travelling();
    cout << OK << endl;
}

void Post ::finish_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips)
{
    string driver_name = find("username");
    int trip_id = stoi(find("id"));
    int driver_index = find_user(users, driver_name);
    int trip_index = find_trip(locations, trips, trip_id);
    if (trips[trip_index].get_driver() != driver_index)
    {
        throw Error(PERMISSION_DENIED);
    }
    trips[trip_index].set_status("finished");
    users[driver_index]->finish_travelling();
    int passenger_index = find_user(users, trips[trip_index].get_passenger());
    users[passenger_index]->finish_travelling();
    cout << OK << endl;
}

void Post::execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num)
{
    if (command_parts[1] == "signup")
    {
        signup(users);
    }
    else if (command_parts[1] == "trips")
    {
        request_trip(users, locations, trips, trips_num);
    }
    else if (command_parts[1] == "accept")
    {
        accept_trip(users, locations, trips);
    }
    else if (command_parts[1] == "finish")
    {
        finish_trip(users, locations, trips);
    }
    else
    {
        throw Error(NOT_FOUND);
    }
}

void Get::execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num)
{
    string username = find("username");
    int user_index = find_user(users, username);
    users[user_index]->check_trips_accessability();
    if (command_parts[1] == "trips" && command_parts.size() == 5)
    {
        if (trips.size() == 0)
        {
            throw Error(EMPTY);
        }
        for (int i = 0; i < trips.size(); i++)
        {
            trips[i].print_trip_details(locations);
        }
    }
    else if (command_parts[1] == "trips" && command_parts.size() == 7)
    {
        int trip_id = stoi(find("id"));
        int trip_index = find_trip(locations, trips, trip_id);
        trips[trip_index].print_trip_details(locations);
    }
    else
    {
        throw Error(NOT_FOUND);
    }
}

void Delete ::execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num)
{
    if (command_parts[1] == "trips")
    {
        string username = find("username");
        int user_index = find_user(users, username);
        int trip_id = stoi(find("id"));
        int trip_index = find_trip(locations, trips, trip_id);
        users[user_index]->delete_trip(trips, trip_index);
        cout << "Ok" << endl;
    }
    else
    {
        throw Error(NOT_FOUND);
    }
}

