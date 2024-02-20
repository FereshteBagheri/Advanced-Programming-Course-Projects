
#include "server/server.hpp"
#include "handlers.hpp"

int main(int argc, char *argv[])
{
    Utaxi command;
    command.add_locations(argv);
    Server server(5000);
    server.get("/", new ShowPage("html/home.html"));
    server.get("/style.css", new ShowPage("html/style.css"));
    server.get("/home.webp", new ShowImage("html/home.webp"));
    server.get("/SignUp", new ShowPage("html/signup.html"));
    server.post("/sign-up", new SignUpHandler(&command));
    server.get("/ok", new ShowPage("html/ok.html"));
    server.get("/home", new ShowPage("html/home.html"));
    server.get("/CalculatePrice", new ShowPage("html/calculate-price.html"));
    server.get("/RequestTrip", new ShowPage("html/request-trip.html"));
    server.post("/calculate-price", new CalculatePriceHandler(&command));
    server.post("/request-trip", new RequestTripHandler(&command));
    server.get("/TripDetails", new ShowPage("html/trip-details.html"));
    server.post("/trip-details", new TripDetailsHandler(&command));
    server.get("/TripsList", new ShowPage("html/trips-list.html"));
    server.post("/trips-list", new TripsListHandler(&command));
    server.get("/AcceptTrip", new ShowPage("html/accept-trip.html"));
    server.post("/accept-trip", new AcceptTripHandler(&command));
    server.get("/CancelTrip", new ShowPage("html/cancel-trip.html"));
    //server.post("/cancel-trip", new CancelTripHandler(&command));
    server.get("/FinishTrip", new ShowPage("html/finish-trip.html"));
    server.post("/finish-trip", new FinishTripHandler(&command));
    server.run();
}
