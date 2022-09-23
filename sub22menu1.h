// create on 2021/11/27
#ifndef SUB22MENU1_H
#define SUB22MENU1_H

#include <iostream>
#include <regex>
#include <string>
#include "math.h"
#include "main_item.h"

using namespace std;

class Sub22menu {
public:
  void sub22_menu();
  int get_sub22_input();
  void select_sub22_item(int input);
  void print_sub22_menu();
  void go_back_to_sub22_menu();
  bool is_integer(std::string num);
  void sub22_item_1();
  void sub22_item_2();
  void sub22_item_3();
  void sub22_item_4();
};

#endif