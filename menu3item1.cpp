#include "menu3item1.h"

void sub_item_2(){
  Sub3menu sub3;
  sub3.sub3_menu();
  int input = sub3.get_sub3_input();
  sub3.select_sub3_item(input);
  sub3.print_sub3_menu();
  sub3.go_back_to_sub3_menu();
}
