#include "menu4item1.h"

void sub_item_3(){
  Sub4menu sub4;
  sub4.sub4_menu();
  int input = sub4.get_sub4_input();
  sub4.select_sub4_item(input);
  sub4.print_sub4_menu();
  sub4.go_back_to_sub4_menu();
}