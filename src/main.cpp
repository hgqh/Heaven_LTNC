#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>

#include "object.h"
#include "game.h"
#include "menu.h"

SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font *font;
Game game;
int main(int argc, char *args[])
{
     game.restart = 1;
     while (game.restart)
     {
          game.variable();
          game.serve();
          game.runMenu();
          if (game.run != 1)
               game.rungame();
          game.runback();
          game.start = 0;
     }
}