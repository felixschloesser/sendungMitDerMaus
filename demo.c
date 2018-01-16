// demo.c
#include <ncurses.h>
#include <unistd.h>

#define DELAY 20000 // susped execution for microsecond intervals

int main(int argc, char *argv[]) {
  int x = 0, y = 0;
  int max_y, max_x = 0;
  int next_x = 0;
  int direction = 1;

 initscr(); // intitalize the window
 noecho(); // don't echo keypresses
 curs_set(FALSE); // don't display a cursor



 while(1) {
   // global var "stdscr" is created by the call to "intitscr()"
   getmaxyx(stdscr, max_y, max_x);
   clear(); // clear the screen of all prev. printed characters
   mvprintw(y, x, "o"); // Print our "ball" at the current xy position
   refresh();

   usleep(DELAY); // Shorter delay between movements.

   next_x = x + direction; // advance ball in dircetion

   if (next_x >= max_x ||  next_x < 0) {
     direction *= -1;
   } else {
     x += direction;
   }
 }

 endwin(); // Restore normal terminal behavior
}
