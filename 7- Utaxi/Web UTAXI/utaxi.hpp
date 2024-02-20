#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "user.hpp"
#include "functions.hpp"

class Utaxi
{
public:
    int trips_num = 0;
    bool user_does_exist(string username);
    string find(string info);
    void signup(string &username, string &role);
    void add_locations(char *argv[]);
    int find_user(string username);
    double calculate_price(string &username, string &origin, string &destination, string &in_hurry);
    int find_location(string name);
    void request_trip(string& passenger_name,string& origin,string& destination,string& in_hurry);
    string trip_details(string& username,int& trip_id);
    int find_trip(int& trip_id);
    void trips_list(string& username, string& sort_status,string& body);
    vector<int> sort_trips_index(vector<Trip> &trips);
    vector<Trip> get_trips();
    void accept_trip(string& driver_name,int& trip_id);
    void cancel_trip(string& username,int& trip_id);
    void finish_trip(string& driver_name,int& trip_id);

protected:
    vector<string> command_parts;
    vector<Location> locations;
    vector<User *> users;
    vector<Trip> trips;
};

#endif