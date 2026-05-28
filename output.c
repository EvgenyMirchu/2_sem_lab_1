#include "output.h"
#include "type_info.h"


void set_colors()
{
    if (has_colors()) 
    {
        start_color();
        init_color(256, 999, 500, 0);        // Оранжевый
        init_color(257, 999, 700, 0);      // Светло-оранжевый  
        init_color(258, 999, 430, 313);      // Коралловый
        init_pair(1, COLOR_GREEN, COLOR_BLACK);   // Название меню
        init_pair(2, COLOR_CORAL, COLOR_BLACK);    // Подсказки
        init_pair(3, COLOR_WHITE, COLOR_ORANGE);  // Выделенный текст
        init_pair(4, COLOR_WHITE, COLOR_BLACK);   // Обычный текст***
        init_pair(5, COLOR_WHITE, COLOR_ORANGE_LIGHT); // Выбранный пункт
    }
}

void guide_menu_set(const WINDOW* guide_window)
{
    wattron(guide_window, COLOR_PAIR(2) | A_BOLD);
    box(guide_window, 0, 0);
    mvwaddstr(guide_window, 1, 2, "     Навигация: стрелки | Выбор: Enter | Выйти: Escape | Пролистать: колесико мышки");
    wattroff(guide_window, COLOR_PAIR(2));
    wrefresh(guide_window);
}

void set_menu_name(const WINDOW* menu_name_window, const short name_index)
{
    if (0 <= name_index <= MENU_NAME_ITEMS-1)
    {
        wclear(menu_name_window);
        wattron(menu_name_window, COLOR_PAIR(1) | A_BOLD);
        box(menu_name_window, 0, 0);
        mvwaddstr(menu_name_window, 1, 2, menu_name_items[name_index]);
        wattroff(menu_name_window, COLOR_PAIR(1) | A_BOLD);
        wrefresh(menu_name_window);
    }
}

void set_menu_main(const WINDOW* menu_window, const short choice)
{
    if (0 <= choice <= MENU_MAIN_ITEMS-1)
    {
        int menu_row_func = menu_row + 1;
        wclear(menu_window);
        box(menu_window, 0, 0);

        int i = 0;
        for (i; i < choice; i++)
        {
            mvwaddstr(menu_window, menu_row_func, menu_col, menu_main_items[i]);
            menu_row_func += 2*i;
        }

        menu_row_func++;
        wattron(menu_window, COLOR_PAIR(3));
        mvwaddchstr(menu_window, menu_row_func, menu_col, menu_main_items[i]);
        wattroff(menu_window, COLOR_PAIR(3));
        menu_row_func++;

        for (i; i < MENU_MAIN_ITEMS; i++)
        {
            mvwaddstr(menu_window, menu_row_func, menu_col, menu_main_items[i]);
            menu_row_func += 2*i;
        }        
        
        wrefresh(menu_window);
    }
}


void set_menu_polynomial_1(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice)
{
    if (0 <= choice < MENU_POLYNOMIAL_ITEMS-3)
    {
        int menu_row_func = menu_row + 1;
        wclear(menu_window);
        box(menu_window, 0, 0);

        type_info_t* type = polynomial_get_type(polynomial);

        if (*type == INT)
        {
            if (choice == 0)
            {
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 1)
            {
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);

                menu_row_func++;
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 2)
            {
                
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);

                
                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);
                

                wattron(menu_window, COLOR_PAIR(3));
                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
                wattroff(menu_window, COLOR_PAIR(3));
            }
        }

        else
        {
            if (choice == 0)
            {
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 1)
            {
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);

                menu_row_func++;
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 2)
            {
                
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);

                
                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[2]);
                

                wattron(menu_window, COLOR_PAIR(3));
                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
                wattroff(menu_window, COLOR_PAIR(3));
            }
        }
        wrefresh(menu_window);
    }
}

void set_menu_polynomial_2(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice)
{
    if (0 <= choice < MENU_POLYNOMIAL_ITEMS-3)
    {
        int menu_row_func = menu_row + 1;
        wclear(menu_window);
        box(menu_window, 0, 0);

        type_info_t* type = polynomial_get_type(polynomial);

        if (*type == INT)
        {
            if (choice == 0)
            {
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 1)
            {
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);

                menu_row_func++;
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 2)
            {
                
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[0]);

                
                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);
                

                wattron(menu_window, COLOR_PAIR(3));
                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
                wattroff(menu_window, COLOR_PAIR(3));
            }
        }

        else
        {
            if (choice == 0)
            {
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 1)
            {
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);

                menu_row_func++;
                wattron(menu_window, COLOR_PAIR(3));
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);
                wattroff(menu_window, COLOR_PAIR(3));

                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
            }

            if (choice == 2)
            {
                
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[1]);

                
                menu_row_func++;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[3]);
                

                wattron(menu_window, COLOR_PAIR(3));
                menu_row_func += 2;
                mvwaddchstr(menu_window, menu_row_func, menu_col, menu_polynomial_items[4]);
                wattroff(menu_window, COLOR_PAIR(3));
            }
        }
        wrefresh(menu_window);
    }
}

void set_menu_different_type_success(const WINDOW* menu_window, const polynomial_t* polynomial, polynomial_errors_t* operation_result)
{
    wclear(menu_window);
    type_info_t* type = polynomial_get_type(polynomial);
    polynomial = polynomial_set_different_type(polynomial, operation_result);
    int menu_row_func = menu_row + 5;
    
    if (operation_result == operation_ok)
    {   
        
        if (*type == INT)
        {
            mvwaddchstr(menu_window, menu_row_func, menu_col, menu_change_type_items[0]);
        }
        
        else 
        {
            mvwaddchstr(menu_window, menu_row_func, menu_col, menu_change_type_items[1]);
        }
        mvwaddchstr(menu_window, menu_row_func+2, menu_col, menu_change_type_items[2]);

        wrefresh(menu_window);
    }
    
    else
    {
        mvwaddchstr(menu_window, menu_row_func, menu_col, menu_errors_items[0]);
    }
    wrefresh(menu_window);
    napms(3000);
}


void set_menu_сhange_coefficients(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice)
{
    type_info_t* type = polynomial_get_type(polynomial);
    int menu_row_func = menu_row + 1;
    int menu_col_func = menu_col + 4;
    int i = 16;
    short choice = 0;
    wclear(menu_window);
    mvwaddstr(menu_window, menu_row_func, menu_col, menu_сhange_coefficients_items[0]);

    polynomial_print(menu_window, polynomial);

    if (0 < choice < 17)
    {
        for (i; i > choice; i--)
        {
            mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[i]);
            menu_row_func++;
        }
        
        wattron(menu_window, COLOR_PAIR(3));
        mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[choice]);
        wattroff(menu_window, COLOR_PAIR(3));
        menu_row_func++;
        
        for (i; i > 0; i--)
        {
            mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[i]);
            menu_row_func++;
        }
        menu_row_func += 4;
        mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[17]);
    }

    if (choice == 17)
    {
        for (i; i > 0; i--)
        {
            mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[i]);
            menu_row_func++;
        }

        menu_row_func += 4;
        wattron(menu_window, COLOR_PAIR(3));
        mvwaddstr(menu_window, menu_row_func, menu_col_func, menu_сhange_coefficients_items[choice]);
        wattroff(menu_window, COLOR_PAIR(3));
    }
}

void set_menu_сhange_coefficients_input(const WINDOW* menu_window, const polynomial_t* polynomial, const polynomial_errors_t* operation_result, const short chosen_coefficient)
{
    type_info_t* type = polynomial_get_type(polynomial);
    int menu_row_func = menu_row + 1;
    int menu_col_func = menu_col;
    char buffer[32];
    
    wclear(menu_window);

    mvwaddstr(menu_window, menu_row_func, menu_col, menu_сhange_coefficients_items[0]);
    mvwprintw(menu_window, menu_row_func, menu_col + strlen(menu_сhange_coefficients_items[0]), "%d", chosen_coefficient);
    menu_row_func += 2;
    menu_row_func += 4;
    mvwaddstr(menu_window, menu_row_func, menu_col, menu_сhange_coefficients_items[1]);

    mvwgetnstr(menu_window, menu_row_func, menu_col_func, buffer, sizeof(buffer)-1);

    if (*type == INT)
    {
        
    }

    else
    {

    }
    
}

void set_menu_сhange_coefficients_success(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice)
{
    
}

void polynomial_print(const WINDOW* menu_window, const polynomial_t* polynomial)
{
    type_info_t* type = polynomial_get_type(polynomial);
    size_t elements = polynomial_get_number_of_elements(polynomial);

    if (*type == INT)
    {
        int* start = (int*) polynomial_get_start(polynomial);
        for (int i; i < elements; i++)
        {
            mvwprintw(menu_window, menu_row + 2 + i, menu_col, "%d * x ^ %d    ", start[i], i);
        }
    }

    else
    {
        complex_t* start = (complex_t*) polynomial_get_start(polynomial);
        for (int i; i < elements; i++)
        {
            mvwprintw(menu_window, menu_row + 4 + i, menu_col, "(%d, %d) * x ^ %d    ", \
                        start[i].Re, start[i].Im, i);
        }
    }
    wrefresh(menu_window);
}


void set_menu_polynomial_operations(const WINDOW* menu_window, const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
void set_menu_polynomial_operations_success(const WINDOW* menu_window, const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);

int safe_transform_to_int(const char* string, number_errors_t* operation_result)    // https://metanit.com/c/tutorial/10.6.php
{
    char* endptr;
    errno = 0; 

    long val = strtol(string, &endptr, 10);     // strtol(строка, указатель на указатель на первый непрочитанный символ, система счисления)

    if (*endptr != '\0')
    {
        operation_result = number_is_incorrect;
        return 0; 
    }

    if (string == endptr) 
    {
        *operation_result = number_is_empty;
        return 0; 
    }

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN) 
    {
        *operation_result = number_is_out_of_range;
        return 0;
    }

    return (int)val;
}

complex_t safe_transform_to_complex(const char* string, number_errors_t* operation_result)
{
    char* digits = "1234567890";
    char Re_string[sizeof(string)];
    char Im_string[sizeof(string)];
    char flag_next_number = '0';
    complex_t result;
    
    for (int i = 1; i < sizeof(string)-2; i++)      //В расчет берутся все символы, кроме крайних (предположительных скобок)
    {   
        if (flag_next_number == '0')
        {
            if ((string[i] == ',' || string[i] == '.')) flag_next_number = '1';
            else Re_string[i] = string[i];
        }
        
        if ( && flag_next_number == '0') flag_next_number = '1';
        else if ((string[i] == ',' || string[i] == '.') && flag_next_number == '1')
        {
            *operation_result = number_has_extra_chars;
            result.Re = 0;
            result.Im = 0;
            return result;
        }
    }
}

char char_in_string(const char* string, char ch)
{
    for (int i = 0; i < sizeof(string); i++)
    {
        if (string[i] == ch) return '1';
    }
    return '0';
}