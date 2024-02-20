#include "game.hpp"
using namespace std;

int main()
{
  Window win(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  Window *win_ptr = &win;
  Game game(win_ptr);
  game.run();
}