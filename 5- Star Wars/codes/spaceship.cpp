#include "spaceship.hpp"

using namespace std;

void Spaceship ::add_new_bullet(Window *win)
{
  Bullet bullet;
  bullet.set_attributes(PLAYER_BULLET_WIDTH, PLAYER_BULLET_HEIGHT, center_x, center_y - (height / 2) - (PLAYER_BULLET_HEIGHT / 2), PLAYER_BULLET_SPEED);
  bullets.push_back(bullet);
}

void Spaceship ::move_bullets(Window *win)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].move("up");
    if (bullets[i].get_center_y() < (-PLAYER_BULLET_HEIGHT / 2))
    {
      bullets.erase(bullets.begin() + i);
    }
  }
}

void Spaceship ::draw_bullets(Window *win)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].draw(win, "bullet.png");
  }
}

bool Spaceship :: are_collided(Bullet bullet){
  int distance_x=abs(center_x-bullet.get_center_x());
  int distance_y=abs(center_y-bullet.get_center_y());
  if(distance_x<(width/2)+(bullet.get_width()/2) && distance_y<(height/2)+(bullet.get_height()/2)){
    return true;
  }
  return false;
}

void Spaceship :: check_being_shot(vector< Enemy> & static_enemies,bool& is_running,Window* win){
  for(int i=0;i<static_enemies.size();i++){
    for (int j=0;j<static_enemies[i].get_bullets().size();j++){
      if(are_collided(static_enemies[i].get_bullets()[j])){
        win->clear();
        win->draw_img("gameover.jpg");
        win->update_screen();
        delay(2000);
        is_running=false;
      }
    }
  }
}

void Spaceship:: shoot_enemies(vector<Enemy>& enemies,bool& is_running,Window* win){
  int distance_x;
  int distance_y;
  for(int i=0;i<bullets.size();i++){
    for(int j=0;j<enemies.size();j++){
       distance_x=abs(enemies[j].get_center_x()-bullets[i].get_center_x());
       distance_y=abs(enemies[j].get_center_y()-bullets[i].get_center_y());
       if(distance_x<(PLAYER_BULLET_WIDTH/2)+ (ENEMY_WIDTH/2) && distance_y<(PLAYER_BULLET_HEIGHT/2)+ (ENEMY_HEIGHT/2)){
         enemies.erase(enemies.begin()+j);
         bullets.erase(bullets.begin()+i);
       }
    }
    
  }
  if(enemies.size()==0){
            win->clear();
        win->draw_img("win.jpeg");
        win->update_screen();
        delay(2000);
        is_running=false;
  }

}
