#define PDC_WIDE

#include "polynomial.h"
#include "errors.h"
#include "curses.h"
#include "runmain.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#define COLOR_ORANGE 256
#define COLOR_GRAY 257

#define MENU_NAME_ITEMS 3
#define MENU_ITEMS 3


int main()
{
    setlocale(LC_ALL, ".utf8"); 
    SetConsoleOutputCP(CP_UTF8);

    initscr();
    clear();
    refresh();

    cbreak();               
    keypad(stdscr, TRUE);
    noecho();

    int rows = LINES;   
    int cols = COLS;    


    //Цвета
    int rgb_coefficient = 1000 / 255;
    if (has_colors()) 
    {
        start_color();
        init_color(256, 1000, 500, 0);        // Оранжевый
        init_color(257, 500, 500, 500);      // Серый   
        init_pair(1, COLOR_GREEN, COLOR_BLACK);   // Название меню
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);    // Подсказки
        init_pair(3, COLOR_WHITE, COLOR_ORANGE);  // Выделенный текст
        init_pair(4, COLOR_WHITE, COLOR_BLACK);   // Обычный текст
    }

    int menu_name_width = cols / 3;
    int guide_width = 2 * cols / 3 + (cols % 3);
    

    WINDOW* menu_name_window = newwin(4, menu_name_width, 0, 0);
    WINDOW* guide_window = newwin(4, guide_width, 0, menu_name_width);
    WINDOW* menu_window = newwin(rows - 6, cols, 4, 0);

    wattron(menu_name_window, COLOR_PAIR(1) | A_BOLD);
    box(menu_name_window, 0, 0);
    mvwaddstr(menu_name_window, 1, 2, "ГЛАВНОЕ МЕНЮ");
    wattroff(menu_name_window, COLOR_PAIR(1));
    wrefresh(menu_name_window);

    wattron(guide_window, COLOR_PAIR(2));
    box(guide_window, 0, 0);
    mvwaddstr(guide_window, 1, 2, "Навигация: стрелки | Выбор: Enter | Выйти: Escape");
    wattroff(guide_window, COLOR_PAIR(2));
    wrefresh(guide_window);

    wattron(menu_window, COLOR_PAIR(4));
    box(menu_window, 0, 0);
    mvwaddstr(menu_window, 1, 2, "Здесь будет список операций");
    wattroff(menu_window, COLOR_PAIR(4));
    wrefresh(menu_window);


    refresh();

    int ch;
    while ((ch = getch()) != 27) //Escape = 27
    {
        switch (ch) 
        {
            case KEY_UP:
                mvwaddstr(menu_window, 3, 2, "Нажата стрелка вверх     ");
                wrefresh(menu_window);
                break;
            case KEY_DOWN:
                mvwaddstr(menu_window, 3, 2, "Нажата стрелка вниз       ");
                wrefresh(menu_window);
                break;
            default:
                mvwprintw(menu_window, 3, 2, "Нажата клавиша: %d         ", ch);
                wrefresh(menu_window);
                break;
        }
    }

    delwin(menu_name_window);
    delwin(guide_window);
    delwin(menu_window);
    endwin();

    return 0;
}