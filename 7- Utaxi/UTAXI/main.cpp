#include "request.hpp"

int main(int argc, char *argv[])
{
    int trips_num = 0;
    vector<Location> locations = save_locations(argv);
    vector<User *> users;
    vector<Trip> trips;
    string request_line;
    while (true)
    {
        getline(cin, request_line);
        if(request_line=="EXIT")
        break;
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