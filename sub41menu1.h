// create on 2021/12/6
#ifndef SUB41MENU1_H
#define SUB41MENU1_H

#include <string>
#include <iostream>
#include <regex>
#include "math.h"
#include "main_item.h"

#define pi 3.1415926

using namespace std;

class Sub41menu {
public:
  void sub41_menu();
  int get_sub41_input();
  void select_sub41_item(int input);
  void print_sub41_menu();
  void go_back_to_sub41_menu();
  bool is_integer(std::string num);
  void sub41_item_1();
  void sub41_item_2();
};

#endif