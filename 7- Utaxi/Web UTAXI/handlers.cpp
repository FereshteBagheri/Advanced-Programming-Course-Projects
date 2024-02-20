#include "handlers.hpp"


SignUpHandler ::SignUpHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *SignUpHandler ::callback(Request *req)
{

    try
    {
        string username = req->getBodyParam("username");
        string role = req->getBodyParam("role");
        utaxi->signup(username, role);
        return Response::redirect("/ok");
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

CalculatePriceHandler ::CalculatePriceHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *CalculatePriceHandler ::callback(Request *req)
{

    try
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string username = req->getBodyParam("username");
        string origin = req->getBodyParam("origin");
        string destination = req->getBodyParam("destination");
        string in_hurry = req->getBodyParam("in-hurry");
        string price = to_string(utaxi->calculate_price(username, origin, destination, in_hurry));
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << price << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());

        return res;
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

RequestTripHandler ::RequestTripHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *RequestTripHandler ::callback(Request *req)
{
    try
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string username = req->getBodyParam("username");
        string origin = req->getBodyParam("origin");
        string destination = req->getBodyParam("destination");
        string in_hurry = req->getBodyParam("in-hurry");
        utaxi->request_trip(username, origin, destination, in_hurry);
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << utaxi->trips_num << "</p> <form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

TripDetailsHandler ::TripDetailsHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *TripDetailsHandler ::callback(Request *req)
{
    try
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string username = req->getBodyParam("username");
        string _id = req->getBodyParam("trip-id");
        int id = stoi(_id);
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << utaxi->trip_details(username, id) << "</p><br> <br><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;
        res->setBody(body.str());
        return res;
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

TripsListHandler ::TripsListHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *TripsListHandler ::callback(Request *req)
{
    try
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string username = req->getBodyParam("username");
        string sort_status = req->getBodyParam("sort-by-cost");

        string body;
        body += "<!DOCTYPE html>";
        body += "<html>";
        body += "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>";
        body += "<body><p>";
        utaxi->trips_list(username, sort_status, body);
        body += "</p><br> <br><form action='/home' method='get'><button>Home</button></form></body>";
        body += "</html>";
        res->setBody(body);
        return res;
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

AcceptTripHandler ::AcceptTripHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *AcceptTripHandler ::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam("username");
        string _id = req->getBodyParam("trip-id");
        int id = stoi(_id);
        utaxi->accept_trip(username, id);
        return Response::redirect("/ok");
    }
    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}

FinishTripHandler ::FinishTripHandler(Utaxi *_utaxi)
{
    utaxi = _utaxi;
}

Response *FinishTripHandler::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam("username");
        string _id = req->getBodyParam("trip-id");
        int id = stoi(_id);
        utaxi->finish_trip(username, id);
        return Response::redirect("/ok");
    }

    catch (Error &err)
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        ostringstream body;
        body
            << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "<head><title>Utaxi</title><link rel='stylesheet' href='style.css'></head>" << endl
            << "<body><p>" << err.get_des() << "</p><form action='/home' method='get'><button>Home</button></form></body>" << endl
            << "</html>" << endl;

        res->setBody(body.str());
        return res;
    }
}





