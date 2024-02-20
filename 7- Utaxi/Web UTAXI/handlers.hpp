#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include <iostream>
#include <string>

#include "server/server.hpp"
#include "utaxi.hpp"

class SignUpHandler : public RequestHandler
{
public:
    SignUpHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~SignUpHandler(){};

private:
    Utaxi *utaxi;
};

class CalculatePriceHandler : public RequestHandler
{
public:
    CalculatePriceHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~CalculatePriceHandler(){};

private:
    Utaxi *utaxi;
};


class RequestTripHandler : public RequestHandler
{
public:
    RequestTripHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~RequestTripHandler(){};

private:
    Utaxi *utaxi;
};


class TripDetailsHandler : public RequestHandler
{
public:
    TripDetailsHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~TripDetailsHandler(){};

private:
    Utaxi *utaxi;
};


class TripsListHandler : public RequestHandler
{
public:
    TripsListHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~TripsListHandler(){};

private:
    Utaxi *utaxi;
};



class AcceptTripHandler : public RequestHandler
{
public:
    AcceptTripHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~AcceptTripHandler(){};

private:
    Utaxi *utaxi;
};



class CancelTripHandler : public RequestHandler
{
public:
    CancelTripHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~CancelTripHandler(){};

private:
    Utaxi *utaxi;
};


class FinishTripHandler : public RequestHandler
{
public:
    FinishTripHandler(Utaxi *_utaxi);
    Response *callback(Request *req);
    ~FinishTripHandler(){};

private:
    Utaxi *utaxi;
};


#endif