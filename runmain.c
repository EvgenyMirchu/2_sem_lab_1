#define PDC_WIDE

#include "polynomial.h"
#include "errors.h"
#include "curses.h"
#include "runmain.h"
#include "output.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, ".utf8"); 
    SetConsoleOutputCP(CP_UTF8);

    START
    
    int rows = LINES;   // Строки  
    int cols = COLS;    // Столбцы 

    //Цвета
    set_colors();

    const int menu_name_width = cols / 3;
    const int guide_width = 2 * cols / 3 + (cols % 3);
    const int menu_row = 7;
    const int menu_col= 0;

    WINDOW* menu_name_window = newwin(4, menu_name_width, 2, 0);
    WINDOW* guide_window = newwin(4, guide_width, 2, menu_name_width);
    WINDOW* menu_window = newwin(25, cols, menu_row, menu_col);
    scrollok(menu_window, TRUE);

    polynomial_errors_t* errors_1 = 0;
    polynomial_errors_t* errors_2 = 0;
    type_info_t* type_1 = 0;
    type_info_t* type_2 = 0;
    polynomial_t* polynomial_1 = polynomial_create(type_1, 16*sizeof(int), errors_1);
    polynomial_t* polynomial_2 = polynomial_create(type_2, 16*sizeof(int), errors_2);

    if (menu_name_window == NULL | guide_window == NULL | menu_window == NULL)
    {
        addstr("Ошибка при выделеии памяти для создания окон");
        END
    }

    set_menu_name(menu_name_window, 0);
    guide_menu_print(guide_window);
    set_menu_main(menu_window, 0);

    refresh();

    short choice_main = 0;
    short choice_polynomial_1 = 0;
    short choice_polynomial_2 = 0;


    int ch_main;
    int ch_polynomial_1;
    int ch_polynomial_2;
    
    while (1)                                                  // ГЛАВНОЕ МЕНЮ
    {
        ch_main = getch();
        set_menu_main(menu_window, 0);
        switch (ch_main) 
        {
            case KEY_UP:
                if (choice_main > 0)
                {
                    choice_main--;
                    set_menu_main(menu_window, choice_main);
                } 
                break;

            case KEY_DOWN:
                if (choice_main < MENU_MAIN_ITEMS-1)
                {
                    choice_main++;
                    set_menu_main(menu_window, choice_main);
                }   
                break;

            case KEY_ENTER:

                switch (choice_main)
                {
                case 0:                                     //  ПОЛИНОМ 1
                    choice_polynomial_1 = 0;
                    set_menu_polynomial_1(menu_window, polynomial_1, choice_polynomial_1);

                    while (1)
                    {
                        ch_polynomial_1 = getch();
                        switch (ch_polynomial_1)
                        {

                            case KEY_UP:
                                if (choice_polynomial_1 > 0)
                                {
                                    choice_polynomial_1--;
                                    set_menu_polynomial_1(menu_window, polynomial_1, choice_polynomial_1);
                                }
                                break;
                            
                            case KEY_DOWN:
                                if (choice_polynomial_1 < MENU_POLYNOMIAL_ITEMS-3)
                                {
                                    choice_polynomial_1++;
                                    set_menu_polynomial_1(menu_window, polynomial_1, choice_polynomial_1);
                                }
                                break;

                            case KEY_ENTER:

                                switch (choice_polynomial_1)
                                {

                                case 0:                 //ПОМЕНЯТЬ ТИП ДАННЫХ   (ПОЛИНОМ 1)
                                    polynomial_set_different_type(polynomial_1, errors_1);
                                    set_menu_different_type_success(menu_window, polynomial_1);
                                    choice_polynomial_1 = 0;
                                    set_menu_polynomial_1(menu_window, polynomial_1, choice_polynomial_1);
                                    break;
                                
                                case 1:                 //ИЗМЕНИТЬ КОЭФФИЦИЕНТЫ (ПОЛИНОМ 1)
                                    break;

                                case 2:                                         //НАЗАД В ГЛАВНОЕ МЕНЮ -|
                                    goto exit_main_menu_from_polynomial_1_menu; //                      |
                                    break;                                      //                      |
                                                                                //                      |
                                default:                                        //                      |
                                    break;                                      //                      |
                                }                                               //                      |
                                break;                                          //                      |
                                                                                //                      |
                            case KEY_ESCAPE:                                    //                      |
                                END                                             //                      |
                                break;                                          //                      |
                                                                                //                      |
                            default:                                            //                      |
                                break;                                          //                      |
                        }                                                       //                      |
                    }                                                           //                      |
                    exit_main_menu_from_polynomial_1_menu:    //ВЫХОД ИЗ МЕНЮ ПОЛИНОМА 1 В ГЛАВНОЕ МЕНЮ <-|
                    choice_polynomial_1 = 0;
                    choice_main = 0;
                    break;
                    
                case 1:                                 //  ПОЛИНОМ 2
                    choice_polynomial_2 = 0;
                    set_menu_polynomial_2(menu_window, polynomial_2, choice_polynomial_2);

                    while (1)
                    {
                        ch_polynomial_2 = getch();
                        switch (ch_polynomial_2)
                        {

                            case KEY_UP:
                                if (choice_polynomial_2 > 0)
                                {
                                    choice_polynomial_2--;
                                    set_menu_polynomial_2(menu_window, polynomial_2, choice_polynomial_2);
                                }
                                break;
                            
                            case KEY_DOWN:
                                if (choice_polynomial_2 < MENU_POLYNOMIAL_ITEMS-3)
                                {
                                    choice_polynomial_2++;
                                    set_menu_polynomial_2(menu_window, polynomial_2, choice_polynomial_2);
                                }
                                break;

                            case KEY_ENTER:

                                switch (choice_polynomial_2)
                                {

                                case 0:                 //ПОМЕНЯТЬ ТИП ДАННЫХ   (ПОЛИНОМ 2)
                                    polynomial_set_different_type(polynomial_2, errors_1);
                                    set_menu_different_type_success(menu_window, polynomial_2);
                                    choice_polynomial_2 = 0;
                                    set_menu_polynomial_2(menu_window, polynomial_2, choice_polynomial_2);
                                    break;
                                
                                case 1:                 //ИЗМЕНИТЬ КОЭФФИЦИЕНТЫ (ПОЛИНОМ 2)
                                    break;

                                case 2:                                         //НАЗАД В ГЛАВНОЕ МЕНЮ -|
                                    goto exit_main_menu_from_polynomial_2_menu; //                      |
                                    break;                                      //                      |
                                                                                //                      |
                                default:                                        //                      |
                                    break;                                      //                      |
                                }                                               //                      |
                                break;                                          //                      |
                                                                                //                      |
                            case KEY_ESCAPE:                                    //                      |
                                END                                             //                      |
                                break;                                          //                      |
                                                                                //                      |
                            default:                                            //                      |
                                break;                                          //                      |
                        }                                                       //                      |
                    }                                                           //                      |
                    exit_main_menu_from_polynomial_2_menu:    //ВЫХОД ИЗ МЕНЮ ПОЛИНОМА 1 В ГЛАВНОЕ МЕНЮ <-|
                    choice_polynomial_2 = 0;
                    choice_main = 0;
                    break;

                case 2:                                 //  ОПЕРАЦИИ НАД ПОЛИНОМАМИ
                    //set_menu_polynomial_operations();
                    break;

                case 3:                                 //  УЙТИ ПОДАЛЬШЕ ОТСЮДА...
                    END

                default:
                    break;
                }

                break;

            case KEY_ESCAPE:
                END

            default:
                break;
        }
    }

    END
}