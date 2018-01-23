// demo.c
#include <ncurses.h>
#include <unistd.h>

# include "game.h"

#define DELAY 80000 // susped execution for microsecond intervals

int main(int argc, char *argv[]) {
  int max_y, max_x = 0;
  int next_x = 0;

  int maus_pos = 1;

  initscr(); // intitalize the window
  noecho(); // don't echo keypresses
  curs_set(FALSE); // don't display a cursor
  getmaxyx(stdscr, max_y, max_x);
  // global var "stdscr" is created by the call to "intitscr()"

  struct sprite {
    int x;
    int y;
  } rope;

  struct character {
      pos = 1; // 1 for right -1 for left
  } mouse;

void init() {
  rope.x = (max_x / 2);
  rope. y = 0;

  mouse.pos = 1;
}


 while(1) {

   // clear(); // clear the screen of all prev. printed characters
   mvprintw(rope.y, rope.x, "#"); // Print our "ball" at the current xy position
   refresh();
   usleep(DELAY); // Shorter delay between movements.

   init();

   rope.y += 1;

   endwin(); // Restore normal terminal behavior

   return 0;
}
