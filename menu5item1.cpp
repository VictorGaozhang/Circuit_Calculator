#include "menu5item1.h"

void sub_item_4(){
  Sub5menu sub5;
  sub5.sub5_menu();
  int input = sub5.get_sub5_input();
  sub5.select_sub5_item(input);
  sub5.print_sub5_menu();
  sub5.sub5_item_1();
  sub5.sub5_item_2();
}