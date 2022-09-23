#include "sub2menu1.h"

void Sub2menu::sub2_menu() {
  print_sub2_menu();
  int input = get_sub2_input();
  select_sub2_item(input);
}

int Sub2menu::get_sub2_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an int, print an error message
    if (valid_input == false) {
      std::cout << "Enter an Integer!\n";
    } else {
      // if it is an int, check whether in range
      input = std::stoi(input_string);
      // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  }
    while (valid_input == false);
    return input;
}

void Sub2menu::select_sub2_item(int input) {
  switch (input) {
    case 1:
      sub2_item_1();
      break;
    case 2:
      sub2_item_2();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub2menu::print_sub2_menu() {
  std::cout << "\n----------------- Basic Filters -----------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. Passive Filters         \t\t|\n";
  std::cout << "|\t\t\t 2. Active Filters          \t\t|\n";  
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
}

void Sub2menu::go_back_to_sub2_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub2_menu();
}

bool Sub2menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}
