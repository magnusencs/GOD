
#include <ncurses/curses.h>


int main() {
    initscr();              // Start curses mode
    start_color();          // Enable color functionality
    curs_set(0);            // Hide cursor

    // Define some color pairs (foreground, background)
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    // Clear and print some colored text
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(2, 5, "This is RED text");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(4, 5, "This is GREEN text");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(6, 5, "This is YELLOW text");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));
    mvprintw(8, 5, "This is CYAN text");
    attroff(COLOR_PAIR(4));

    mvprintw(10, 5, "Press any key to exit...");
    refresh();
    getch();

    endwin();               // End curses mode
    return 0;
}
