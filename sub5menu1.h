// create on 2021/12/4
#ifndef SUB6MENU1_H
#define SUB6MENU1_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include "main_item.h"

using namespace std;

class Sub5menu {
public:
  void sub5_menu();
  int get_sub5_input();
  void select_sub5_item(int input);
  void print_sub5_menu();
  bool is_integer(std::string num);  
  void go_back_to_sub5_menu(); 
  void sub5_item_1();
  void sub5_item_2();
};

#endif