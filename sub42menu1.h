// create on 2021/12/6
#ifndef SUB42MENU1_H
#define SUB42MENU1_H

#include <iostream>
#include <regex>
#include <string>
#include "math.h"
#include "main_item.h"

using namespace std;

#define pi 3.1415926

class Sub42menu {
public:
  void sub42_menu();
  int get_sub42_input();
  void select_sub42_item(int input);
  void print_sub42_menu();
  void go_back_to_sub42_menu();
  bool is_integer(std::string num);
  void sub42_item_1();
  void sub42_item_2();
};

#endif