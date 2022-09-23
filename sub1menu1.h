// create on 2021/11/24
#ifndef SUBMENU1_H
#define SUBMENU1_H

#include "menu2item1.h"
#include "menu3item1.h"
#include "menu4item1.h"
#include "menu5item1.h"
#include "menu6item1.h"

#include <iostream>
#include <regex>
#include <string>

class Sub1menu {
public:
  void sub1_menu();
  int get_sub1_input();
  void select_sub1_item(int input);
  void print_sub1_menu();
  void go_back_to_sub1_menu();
  bool is_integer(std::string num);
};

#endif