// demo.c
#include <ncurses.h>
#include <unistd.h>

# include "game.h"

#define DELAY 80000 // susped execution for microsecond intervals

int max_y, max_x = 0;



struct sprite {
  int x;
  int y;
} rope;

// struct character {
//     int pos; // 1 for right -1 for left
// } mouse;

void init() {
  initscr(); // intitalize the window
  noecho(); // don't echo keypresses
  curs_set(FALSE); // don't display a cursor
  getmaxyx(stdscr, max_y, max_x);
  // global var "stdscr" is created by the call to "intitscr()"
}

void init_sprites() {
  rope.x = (max_x / 2);
  rope.y = 0;
  // mouse.pos = 1;
}

void print_mouse(int y, int x, int orientation) {
  char mouse[5] = {'@','#','#','~','\0'};
  int i = 0;

  mvprintw(y, x, "@##~");
}

int main(int argc, char *argv[]) {

  init();
  init_sprites();

  int i,j = 0;

  // DRAW THE FLOOR
  while(i < max_x) {
    mvprintw(max_y-1, i, "=");
    i += 1;
  }

  // DROPPING THE ROPE
  while(j < max_y-1) {
    // clear(); // clear the screen of all prev. printed characters
    mvprintw(rope.y, rope.x, "#"); // Print the rope
    refresh();
    usleep(DELAY); // Shorter delay between movements.

    rope.y += 1;
    j++;
  }

  i = 0;

  //print_mouse(max_y-4, max_x-2, 0);
  mvprintw(0, 0, "@##~");

  getchar();  // Press any button to exit

  endwin(); // Restore normal terminal behavior

  return 0;

}
