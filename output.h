#pragma once

#include "curses.h"
#include "polynomial.h"
#include <string.h>
#include <errors.h>

#define START initscr(); \
    clear(); \
    refresh();  \
    cbreak(); \
    keypad(stdscr, TRUE); \
    noecho();

#define END delwin(menu_name_window); \
    delwin(guide_window); \
    delwin(menu_window); \
    endwin(); \
    return 0;

#define KEY_ESCAPE                                  27

#define COLOR_ORANGE                                256
#define COLOR_ORANGE_LIGHT                          257
#define COLOR_CORAL                                 258


#define SIZE(array)                                 (sizeof(array) / sizeof((array)[0]))
#define MENU_NAME_ITEMS                             SIZE(menu_name_items)
#define MENU_MAIN_ITEMS                             SIZE(menu_main_items)
#define MENU_POLYNOMIAL_ITEMS                       SIZE(menu_polynomial_items)
#define MENU_CHANGE_TYPE_ITEMS                      SIZE(menu_change_type_items)
#define MENU_CHANGE_COEFFICIENTS_ITEMS              SIZE(menu_сhange_coefficients_items)
#define MENU_POLYNOMIAL_OPERATIONS_ITEMS            SIZE(menu_polynomial_operations_items)
#define MENU_POLYNOMIAL_OPERATIONS_SUCCESS_ITEMS    SIZE(menu_polynomial_operations_success_items)
#define MENU_ERRORS_ITEMS                           SIZE(menu_errors_items)


const int menu_row;
const int menu_col;


const char *menu_name_items[] = 
{
    "   ГЛАВНОЕ МЕНЮ",                  
    "   ПОЛИНОМ 1", 
    "   ПОЛИНОМ 2",
    "   ОПЕРАЦИИ НАД ПОЛИНОМАМИ"
};

/* Основное для меню */

const char *menu_main_items[] = 
{
    "   Полином 1",
    "   Полином 2", 
    "   Операции над полиномами",
    "   Уйти подальше отсюда..."
};

const char *menu_polynomial_items[] = 
{
    "   Поменять тип данных         {целые -> комплексные}",
    "   Поменять тип данных         {комплексные -> целые}",
    "   Изменить коэффициенты полинома 1", 
    "   Изменить коэффициенты полинома 2",
    "   Назад (в главное меню)"
};

const char *menu_change_type_items[] =
{
    "   Успешно изменен тип данных   {комплексные -> целые}.",
    "   Успешно изменен тип данных   {целые -> комплексные}.",
    "   Возврат в меню полинома через 3 секунды."
};

const char *menu_сhange_coefficients_items[] = 
{
    "   Выберите коэффициенты, которые хотите изменить:",                                                
    "   (1)",   "   (2)",   "   (3)",   "   (4)",
    "   (5)",   "   (6)",   "   (7)",   "   (8)",   
    "   (9)",   "   (10)",  "   (11)",  "   (12)",
    "   (13)",  "   (14)",  "   (15)",  "   (16)",
    "   Выйти в меню полинома",                                                                        
};

const char *set_menu_сhange_coefficients_input_items[] = 
{
    "   Выбран коэффициент: ",                                                                           
    "   Введите число: ",
    "   *Целое число нужно вводить в пределах интервала ",                                                                                                                                                                  
    "   *Комплекное число нужно вводить в формате (Re, Im) или Re, Im. Каждая координата должна лежать в пределах целого числа." 
};

const char *set_menu_сhange_coefficients_success_items[] = 
{
    "   Введено целое (комплексное) число: ",                                                                         
    "   Ошибка: некорректный ввод. Используйте только цифры и знак минус (для комплексных круглые скобки и запятую).",                                                                                                                                                                  
    "   Ошибка: некорректный ввод. Выход за допустимые значения числа.",
    "   Возврат в меню полинома через 3 секунды."    
};

const char *menu_polynomial_operations_items[] = 
{
    "   Тип данных полинома 1:",
    "   Тип данных полинома 2:",
    "   Полином 1 -> умножить на число",   
    "   Полином 1 -> вычислить значение",   
    "   Полином 2 -> умножить на число",   
    "   Полином 2 -> умножить на число",
    "   Сложить полиномы друг с другом*",   
    "   Умножить полиномы друг на друга",   
    "   Назад (в главное меню)",   
    "   *Операции одновременно с двумя полиномами возможны при одинаковых типах данных!"   
};

const char *menu_polynomial_operations_success_items[] = 
{
    "   Операция",
    "   Полином 1 -> умножить на число",   
    "   Полином 1 -> вычислить значение",   
    "   Полином 2 -> умножить на число",   
    "   Полином 2 -> умножить на число",
    "   Сложить полиномы друг с другом*",   
    "   Умножить полиномы друг на друга", 
    "   прошла успешно"
    "   прошла неуспешно",   
    "   Хотите посмотреть на полиномы?",   
    "   Да",   
    "   Нет (возврат в меню операций)"   
};

const char *menu_errors_items[] = 
{
    "   Ошибка при изменении типа данных. Программа закроется через 3 секунды"
};


void set_colors();
void polynomial_print(const WINDOW* menu_window, const polynomial_t* polynomial);
void guide_menu_set(const WINDOW* guide_window);

void set_menu_name(const WINDOW* menu_name_window, const short name_index);
void set_menu_main(const WINDOW* menu_window, const short choice);

void set_menu_polynomial_1(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice);
void set_menu_polynomial_2(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice);

void set_menu_different_type_success(const WINDOW* menu_window, const polynomial_t* polynomial, polynomial_errors_t* operation_result);

void set_menu_сhange_coefficients(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice);
void set_menu_сhange_coefficients_input(const WINDOW* menu_window, const polynomial_t* polynomial, const polynomial_errors_t* operation_result, const short choice);
void set_menu_сhange_coefficients_success(const WINDOW* menu_window, const polynomial_t* polynomial, const short choice);

void set_menu_polynomial_operations(const WINDOW* menu_window, const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
void set_menu_polynomial_operations_success(const WINDOW* menu_window, const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);

int safe_transform_to_int(const char* string, number_errors_t* operation_result);
complex_t safe_transform_to_complex(const char* string, number_errors_t* operation_result);