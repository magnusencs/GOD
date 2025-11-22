#include <iostream>
#include <ncurses/curses.h>

using namespace std;
int main() {
    initscr();
    printw("heil hitler");
    refresh();
    getch(); 
    endwin();
    
        // Wait for user input
}