// create on 2021/11/24
#ifndef SUB2MENU1_H
#define SUB2MENU1_H

#include "menu21item1.h"
#include "menu22item1.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Sub2menu {
public:
  void sub2_menu();
  int get_sub2_input();
  void select_sub2_item(int input);
  void print_sub2_menu();
  void go_back_to_sub2_menu();
  bool is_integer(std::string num);    
};

#endif