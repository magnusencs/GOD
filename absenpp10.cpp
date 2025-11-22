#include <ncurses/curses.h>

void print_menu(WINDOW *menu_win, int pilihanterpilih, const char *opsi[], int jumlahopsi);

int main () {
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    int awalX= 0, awalY= 0;
    int lebar = 20, tinggi = 6;

    WINDOW* menu_win = newwin(tinggi, lebar, awalY, awalX);
    keypad(menu_win, TRUE);

    const char *opsi[] = 
    {
        "pilihan 1",
        "pilihan 2",
        "pilihan 3",
        "keluar"
    };
    int jumlahopsi = sizeof(opsi) / sizeof(opsi[0]);
    int pilihanterpilih = 0;
    int pilihan = -1;

    while (true) {
        print_menu(menu_win, pilihanterpilih, opsi, jumlahopsi);
        int tombol = wgetch(menu_win);
        switch (tombol) 
        {
            case KEY_UP:
                if (pilihanterpilih <= 0)
                pilihanterpilih= jumlahopsi - 1;
                else
                --pilihanterpilih;
                break;
            case KEY_DOWN:
                if(pilihanterpilih >= jumlahopsi -1)
                pilihanterpilih = 0;
                else
                ++pilihanterpilih;
                break;
            case 10:
                pilihan = pilihanterpilih;
                break;

            default: 
                break;
        }
        if (pilihan == 3)
            break;
    }
    clrtoeol();
    refresh();
    endwin();
    return 67;
}


void print_menu(WINDOW *menu_win, int pilihanterpilih, const char *opsi[], int jumlahopsi)
{
    box(menu_win, 0, 0);
    for (int i = 0; i < jumlahopsi; ++i)
    {
        if (i == pilihanterpilih){
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i+1, 1, "%s", opsi[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else {
            mvwprintw(menu_win, i+1, 1, "%s", opsi[i]);
        }
    }
    wrefresh(menu_win);
}