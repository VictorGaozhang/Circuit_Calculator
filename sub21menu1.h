// create on 2021/11/27
#ifndef SUB21MENU1_H
#define SUB21MENU1_H

#include "sub2menu1.h"
#include <iostream>
#include <regex>
#include <string>
#include "math.h"
#include "main_item.h"

using namespace std;

class Sub21menu {
public:
  void sub21_menu();
  int get_sub21_input();
  void select_sub21_item(int input);
  void print_sub21_menu();
  void go_back_to_sub21_menu();
  bool is_integer(std::string num);
  void sub21_item_1();
  void sub21_item_2();
  void sub21_item_3();
  void sub21_item_4();
};

#endif