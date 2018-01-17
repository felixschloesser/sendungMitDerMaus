// demo.c
#include <ncurses.h>
#include <unistd.h>

#define DELAY 80000 // susped execution for microsecond intervals

int main(int argc, char *argv[]) {
  int x = 0, y = 0;
  int max_y, max_x = 0;
  int next_x = 0;

  int maus_pos = 1;

  initscr(); // intitalize the window
  noecho(); // don't echo keypresses
  curs_set(FALSE); // don't display a cursor
  getmaxyx(stdscr, max_y, max_x);
  // global var "stdscr" is created by the call to "intitscr()"

  x = (max_x / 2);
  y = 0;

 while(1) {

   // clear(); // clear the screen of all prev. printed characters
   mvprintw(y, x, "#"); // Print our "ball" at the current xy position
   refresh();

   usleep(DELAY); // Shorter delay between movements.

   y += 1;
 }

 endwin(); // Restore normal terminal behavior
}
