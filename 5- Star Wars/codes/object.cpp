#include "object.hpp"


void Object ::set_attributes(int _width, int _height, int _center_x, int _center_y, int _speed)
{
  width = _width;
  height = _height;
  center_x = _center_x;
  center_y = _center_y;
  speed = _speed;
}

void Object ::draw(Window *win, string file_name)
{
  int top_left_x = center_x - (width / 2);
  int top_left_y = center_y - (height / 2);
  win->draw_img(file_name, Rectangle(top_left_x, top_left_y, width, height));
}

void Object ::move(string direction)
{
  if (direction == "up")
  {
    if (center_y >= (height / 2))
      center_y -= speed;
  }
  else if (direction == "down")
  {
    if (center_y <= WINDOW_HEIGHT - (height / 2))
      center_y += speed;
  }
  else if (direction == "right")
  {
    if (center_x < WINDOW_WIDTH - (width / 2))
      center_x += speed;
  }
  else if (direction == "left")
  {
    if (center_x > (width / 2))
      center_x -= speed;
  }
}