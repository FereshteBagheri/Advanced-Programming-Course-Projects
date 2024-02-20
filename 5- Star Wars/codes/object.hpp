
#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "define.hpp"
#include "rsdl.hpp"

#include <vector>
#include <string>

using namespace std;

class Object
{
public:
  void set_attributes(int _width, int _height, int _center_x, int _center_y, int _speed);
  void draw(Window *win, string file_name);
  virtual void move(string direction);
  int get_center_x() { return center_x; }
  int get_center_y() { return center_y; }
  int get_width(){return width;}
  int get_height(){return height;}

protected:
  int center_x;
  int center_y;
  int width;
  int height;
  int speed;
};


#endif
