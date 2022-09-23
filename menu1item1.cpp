#include "menu1item1.h"

void menu_item_1(){
  Sub1menu sub1;
  sub1.sub1_menu();
  int input = sub1.get_sub1_input();
  sub1.select_sub1_item(input);
  sub1.print_sub1_menu();
  sub1.go_back_to_sub1_menu();
  void sub_item_2();
}
