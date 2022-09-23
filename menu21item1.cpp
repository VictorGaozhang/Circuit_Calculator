#include <iostream>
#include <regex>
#include <string>
#include "menu21item1.h"


void sub2_item_1(){
  Sub21menu sub21;
  sub21.sub21_menu();
  int input = sub21.get_sub21_input();
  sub21.select_sub21_item(input);
  sub21.print_sub21_menu();
  sub21.go_back_to_sub21_menu();
  void sub21_item_1();
  void sub21_item_2();
  void sub21_item_3();
  void sub21_item_4();
}
