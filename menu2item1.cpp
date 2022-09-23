#include "menu2item1.h"


void sub_item_1(){
  Sub2menu sub2;
  sub2.sub2_menu();
  int input = sub2.get_sub2_input();
  sub2.select_sub2_item(input);
  sub2.print_sub2_menu();
  sub2.go_back_to_sub2_menu();  
  void sub2_item_2();
}
