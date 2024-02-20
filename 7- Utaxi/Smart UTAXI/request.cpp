#include "request.hpp"

Request::Request(string request_line)
{
    request_elements = split_string(request_line, ' ');
}

void Request::handle(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num)
{
    if (request_elements[0] == "POST")
    {
        Command *new_command = new Post(request_elements);
        new_command->execute(users, locations, trips, trips_num);
        delete (new_command);
    }
    else if (request_elements[0] == "GET")
    {
        Command *new_command = new Get(request_elements);
        new_command->execute(users, locations, trips, trips_num);
        delete (new_command);
    }
    else if (request_elements[0] == "DELETE")
    {
        Command *new_command = new Delete(request_elements);
        new_command->execute(users, locations, trips, trips_num);
        delete (new_command);
    }
    else
    {
        throw Error(BAD_REQUEST);
    }
}