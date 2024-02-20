
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "spaceship.hpp"

using namespace std;

const char EMPTY = '.';

class Game
{
public:
  Game(Window *_win);
  void manage_events(Spaceship &player);
  void run();
  void draw_objects(Spaceship &player,vector<Enemy> &static_enemies);
  bool is_running = true;
  char pressed_key;
private:
  Window *win;
 
};
#endif