// create on 2021/11/24
#ifndef SUB3MENU1_H
#define SUB3MENU1_H
#include <string>
#include <iostream>
#include <regex>
#include <math.h>
#include <vector>
#include <complex>
#include "main_item.h"
#define pi 3.1415926

using namespace std;

class Sub3menu {
public:
  void sub3_menu();
  int get_sub3_input();
  void select_sub3_item(int input);
  void print_sub3_menu();
  void go_back_to_sub3_menu();
  bool is_integer(std::string num);
  void sub3_item_1();
  void sub3_item_2();
  void sub3_item_3();
};

#endif