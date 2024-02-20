#include "enemy.hpp"

void Enemy ::move_bullets(Window *win)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].move("down");
    if (bullets[i].get_center_y() > WINDOW_HEIGHT + (ENEMY_BULLET_HEIGHT / 2))
    {
      bullets.erase(bullets.begin() + i);
      add_new_bullet(win);
    }
  }
}
void Enemy ::draw_bullets(Window *win)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].draw(win, "bullet-enemy.png");
  }
}

void Enemy ::add_new_bullet(Window *win)
{
  Bullet bullet;
  bullet.set_attributes(ENEMY_BULLET_WIDTH, ENEMY_BULLET_HEIGHT, center_x, center_y + (height / 2) + ENEMY_BULLET_HEIGHT, ENEMY_BULLET_SPEED);
  bullets.push_back(bullet);
}
