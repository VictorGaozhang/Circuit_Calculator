#include "sub4menu1.h"

void Sub4menu::sub4_menu() {
  print_sub4_menu();
  int input = get_sub4_input();
  select_sub4_item(input);
}

int Sub4menu::get_sub4_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 2;

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

void Sub4menu::select_sub4_item(int input) {
  switch (input) {
    case 1:
      sub4_item_1();
      break;
    case 2:
      sub4_item_2();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub4menu::print_sub4_menu() {
  std::cout << "\n--------------- Chebyshev Filters ---------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. 0.5 dB Ripple           \t\t|\n";
  std::cout << "|\t\t\t 2. 2 dB Ripple             \t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
  cout << "For Chebyshev Fielts calaulator, we using the Equal Component approach, R1 = R2 = R, C1 = C2 = C" << endl;
}

void Sub4menu::go_back_to_sub4_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub4_menu();
}

bool Sub4menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}
