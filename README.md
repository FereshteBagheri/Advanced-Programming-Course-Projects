# Advanced Programming Course Projects

My C++ assignments for the Advanced Programming course at the University of Tehran (Spring 2022, taught by Dr. Ramtin Khosravi). Each folder has the assignment description (PDF, in Persian) and my code (in `codes/` for assignments 1–6). The assignments build up from basic C++ to object-oriented design and a small web application.

| # | Assignment | Topic |
|---|---|---|
| 1 | [Daily Task Scheduler](1-%20Daily%20Task%20Scheduler/) | Input/output, strings and vectors in C++ |
| 2 | [Recursive Functions](2%20-%20Recursive%20Functions/) | Four problems that must be solved recursively |
| 3 | [Top-Down Design](3%20-%20Top%20Down%20Design/) | Assigning translators to international conferences by language and availability; breaking a problem into smaller parts |
| 4 | [CS:GO Simulation](4-%20CSGO%20Simiulation/) | First object-oriented design: a simulation of the rules of a CS:GO match |
| 5 | [Star Wars](5-%20Star%20Wars/) | Event-driven programming: a 2D shooter game with the SDL graphics library (through the course's RSDL wrapper) |
| 6 | [Library and Shopping System](6-%20Library%20And%20Shopping%20System/) | Inheritance and polymorphism: a library system, plus a shopping cart (bonus part) |
| 7 | [UTaxi](7-%20Utaxi/) | Final project in three phases (below) |

## UTaxi — taxi request system

1. **UTAXI** — command-line app: passengers request trips between areas of the city (read from `locations.csv`), and drivers accept and finish them.
2. **Smart UTAXI** — adds trip prices and shows waiting trips to drivers sorted by price.
3. **Web UTAXI** — turns the app into a website, using the small C++ HTTP server library provided by the course (`server/`) and HTML pages (`html/`).

## Building

Assignments 5–7 have a `makefile`; the others are single `.cpp` files that can be compiled with `g++`. For example:

```bash
cd "7- Utaxi/Smart UTAXI"
make
./utaxi.out
```

Assignment 5 needs SDL2 (with SDL2_image, SDL2_ttf and SDL2_mixer) installed.
