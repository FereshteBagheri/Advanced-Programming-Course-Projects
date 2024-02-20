#ifndef USER_HPP
#define USER_HPP

#include "error.hpp"
#include "trip.hpp"

class User
{
public:
    User(string _username);
    string get_username();
    virtual void request_trip(int origin_index, int destination_indexint, int user_index, vector<Trip> &trips, int &trips_num);
    virtual void check_trips_accessability();
    virtual void delete_trip(vector<Trip> &trips, int trip_index);
    virtual void accept_trip(vector<Trip> &trips, int trip_index);
    void start_travelling();
    void finish_travelling();

protected:
    string username;
    bool is_travelling = false;
};

class Passenger : public User
{
public:
    Passenger(string _username) : User(_username){};
    virtual void request_trip(int origin_index, int destination_index, int user_index, vector<Trip> &trips, int &trips_num);
    virtual void delete_trip(vector<Trip> &trips, int trip_index);
};

class Driver : public User
{
public:
    Driver(string _username) : User(_username){};
    virtual void check_trips_accessability() {}
    virtual void accept_trip(vector<Trip> &trips, int trip_index);
};

#endif