#include "sub1menu1.h"

void Sub1menu::sub1_menu() {
  print_sub1_menu();
  int input = get_sub1_input();
  select_sub1_item(input);
}

int Sub1menu::get_sub1_input() {
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

void Sub1menu::select_sub1_item(int input) {
  switch (input) {
    case 1:
      sub_item_1();
      break;
    case 2:
      sub_item_2();
      break;
    case 3:
      sub_item_3();
      break;
    case 4:
      sub_item_4();
      break;
    case 5:
      sub_item_5();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub1menu::print_sub1_menu() {
  cout << "Welcome use Filter Calculator!" << endl;
  std::cout << "\n------------------ Filter type ------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t   1. Basic Filters           \t\t|\n";
  std::cout << "|\t\t\t   2. Butterworth             \t\t|\n";
  std::cout << "|\t\t\t   3. Chebyshev               \t\t|\n";
  std::cout << "|\t\t\t   4. Bessel                  \t\t|\n";
  std::cout << "|\t\t\t   5. Sallen-Key              \t\t|\n";  
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease select the type of filter calaulation in generally: \n";
}

void Sub1menu::go_back_to_sub1_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  }
  while (input != "b" && input != "B");
  sub1_menu();
}

bool Sub1menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}
