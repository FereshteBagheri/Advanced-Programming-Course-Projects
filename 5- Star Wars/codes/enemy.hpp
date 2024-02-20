
#include "object.hpp"
#include "bullet.hpp"

class Enemy : public Object
{
public:
  void add_new_bullet(Window *win);
  vector<Bullet> get_bullets() { return bullets; }
  void draw_bullets(Window *win);
  void move_bullets(Window *win);

private:
  vector<Bullet> bullets;
};