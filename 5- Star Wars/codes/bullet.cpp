#include "bullet.hpp"

using namespace std;

void Bullet ::move(string direction)
{
  if (direction == "up")
  {
    center_y -= speed;
  }
  else if (direction == "down")
  {
    center_y += speed;
  }
}
