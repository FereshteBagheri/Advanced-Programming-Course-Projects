#include "game.hpp"

using namespace std;

void Game ::manage_events(Spaceship &player)
{
  while (win->has_pending_event())
  {
    Event event = win->poll_for_event();
    if (event.get_type() == Event::KEY_PRESS)
      pressed_key = event.get_pressed_key();
    if (event.get_type() == Event::KEY_RELEASE)
      pressed_key = EMPTY;
    if (event.get_type() == Event::QUIT)
      exit(0);
  }
  switch (pressed_key)
  {
  case 'a':
    player.move("left");
    break;
  case 's':
    player.move("down");
    break;
  case 'd':
    player.move("right");
    break;
  case 'w':
    player.move("up");
    break;
  case 'o':
    is_running = false;
    break;
  case ' ':
    player.add_new_bullet(win);
    pressed_key = EMPTY;
    break;
  }
}

Game ::Game(Window *_win)
{
  win = _win;
}

void Game ::draw_objects(Spaceship &player, vector<Enemy> &static_enemies)
{
  win->clear();
  win->draw_img("back.jpg");
  player.draw(win, "spaceship.png");
  player.move_bullets(win);
  player.draw_bullets(win);
  for (int i = 0; i < static_enemies.size(); i++)
  {
    static_enemies[i].draw(win, "enemy.png");
  }
  for (int i = 0; i < static_enemies.size(); i++)
  {
    static_enemies[i].draw_bullets(win);
    static_enemies[i].move_bullets(win);
  }
  win->update_screen();
}

void Game ::run()
{
  Spaceship player;
  player.set_attributes(PLAYER_WIDTH, PLAYER_HEIGHT, 50, 890, PLAYER_SPEED);

  vector<Enemy> static_enemies;

  Enemy e;
  e.set_attributes(ENEMY_WIDTH, ENEMY_HEIGHT, 50, 150, 0);
  e.add_new_bullet(win);

  Enemy e1;
  e1.set_attributes(ENEMY_WIDTH, ENEMY_HEIGHT, 170, 150, 0);
  e1.add_new_bullet(win);

  Enemy e2;
  e2.set_attributes(ENEMY_WIDTH, ENEMY_HEIGHT, 800, 100, 0);
  e2.add_new_bullet(win);

   Enemy e3;
  e3.set_attributes(ENEMY_WIDTH, ENEMY_HEIGHT, 1200, 130, 0);
  e3.add_new_bullet(win);

  static_enemies.push_back(e);
  static_enemies.push_back(e1);
  static_enemies.push_back(e2);
  static_enemies.push_back(e3);

  while (is_running)
  {
    win->clear();
    manage_events(player);
    draw_objects(player, static_enemies);
    player.check_being_shot(static_enemies, is_running, win);
    player.shoot_enemies(static_enemies,is_running,win);
    delay(RUNNIG_DELAY);
  }
}