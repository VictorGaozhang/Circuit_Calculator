// create on 2021/12/4
#ifndef SUB6MENU1_H
#define SUB6MENU1_H

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "main_item.h"

using namespace std;

class Sub6menu {
public:
  void sub6_menu();
  int get_sub6_input();
  void select_sub6_item(int input);
  void print_sub6_menu();
  bool is_integer(std::string num);  
  void go_back_to_sub6_menu();
  void sub6_item_1();
  void sub6_item_2();
  void sub6_item_3();
  void sub6_item_4();
};

#endif