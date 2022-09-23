#include "menu6item1.h"

void sub_item_5(){
  Sub6menu sub6;
  sub6.sub6_menu();
  int input = sub6.get_sub6_input();
  sub6.select_sub6_item(input);
  sub6.print_sub6_menu();
  sub6.sub6_item_1();
  sub6.sub6_item_2();
  sub6.sub6_item_3();
  sub6.sub6_item_4();
}
