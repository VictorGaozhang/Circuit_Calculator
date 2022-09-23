#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <regex>
#include <string>
#include "menu1item2.h"
//#include "menu1item1.h"
#include "Thevenin_calculator.h"

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);

#endif