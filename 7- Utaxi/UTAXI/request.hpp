#include "command.hpp"

class Request
{
public:
    Request(string request_line);
    void handle(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num);

private:
    vector<string> request_elements;
};