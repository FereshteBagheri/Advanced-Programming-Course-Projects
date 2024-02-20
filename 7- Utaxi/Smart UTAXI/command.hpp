#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "user.hpp"

class Command
{
public:
    Command(vector<string> parts);
    bool user_does_exist(vector<User *> &users, string username);
    string find(string info);
    virtual void signup(vector<User *> &users) {}
    virtual void execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num) = 0;
    int find_location(vector<Location> &locations, string name);
    int find_user(vector<User *> &users, string username);
    virtual void request_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num) {}
    int find_trip(vector<Location> &locations, vector<Trip> &trips, int trip_id);
    virtual void accept_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips) {}
    void finish_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips) {}
    vector<int> sort_trips_index(vector<Trip> &trips);

protected:
    vector<string> command_parts;
};

class Post : public Command
{
public:
    Post(vector<string> parts) : Command(parts) {}
    void signup(vector<User *> &users);
    void execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num);
    void request_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num);
    void accept_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips);
    void finish_trip(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips);
};

class Get : public Command
{
public:
    Get(vector<string> parts) : Command(parts) {}

    void execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num);
};

class Delete : public Command
{
public:
    Delete(vector<string> parts) : Command(parts) {}
    void execute(vector<User *> &users, vector<Location> &locations, vector<Trip> &trips, int &trips_num);
};

#endif