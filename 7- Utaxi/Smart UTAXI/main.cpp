#include "request.hpp"

int main(int argc, char *argv[])
{
    int trips_num = 0;
    vector<Location> locations = save_locations(argv);
    vector<User *> users;
    vector<Trip> trips;
    string request_line;
    while (request_line != "EXIT")
    {
        getline(cin, request_line);
        Request req(request_line);
        try
        {
            req.handle(users, locations, trips, trips_num);
        }
        catch (Error &err)
        {
            err.print();
            continue;
        }
    }
}