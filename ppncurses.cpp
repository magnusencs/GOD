#include <ncurses/curses.h>
#include <windows.h>
#include <string>
using namespace std;
int main () {
    initscr();
    
    for(int i = 0; i< 3; ++i){
        mvprintw(6, 50, "Loading...");
        mvprintw(7, 50, "--------------------");
        mvprintw(8, 50, "|                  |");
        mvprintw(9, 50, "--------------------");

         for (int f = 1; f< 18; ++f) {
            mvprintw(8, 50+f, ">");
            refresh();
            Sleep(200);
         }
    }
    endwin();
    return 0;
}
