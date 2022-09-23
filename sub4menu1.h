// create on 2021/12/5
#ifndef SUB4MENU1_H
#define SUB4MENU1_H
#include <string>
#include <iostream>
#include <regex>
#include <math.h>
#include <vector>
#include <complex>
#include "main_item.h"
#include "menu41item1.h"
#include "menu42item1.h"

using namespace std;

class Sub4menu {
public:
  void sub4_menu();
  int get_sub4_input();
  void select_sub4_item(int input);
  void print_sub4_menu();
  bool is_integer(std::string num); 
  void go_back_to_sub4_menu(); 
};

#endif