
#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP
#include "enemy.hpp"
#include "object.hpp"

using namespace std;

class Spaceship : public Object
{
public:
  void add_new_bullet(Window *win);
  vector<Bullet> get_bullets() { return bullets; }
  void move_bullets(Window *win);
  void draw_bullets(Window *win);
  void check_being_shot(vector<Enemy>& static_enemies,bool& is_running,Window* win);
  bool are_collided(Bullet bullet);
  void shoot_enemies(vector<Enemy>& enemies,bool& is_running,Window* win);

protected:
  vector<Bullet> bullets;
};
#endif