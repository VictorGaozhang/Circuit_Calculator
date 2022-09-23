#include "sub5menu1.h"

void Sub5menu::sub5_menu() {
  print_sub5_menu();
  int input = get_sub5_input();
  select_sub5_item(input);
}

int Sub5menu::get_sub5_input() {
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

void Sub5menu::select_sub5_item(int input) {
  switch (input) {
    case 1:
      sub5_item_1();
    case 2:
      sub5_item_2();
    default:
      exit(1);
      break;
  }
}

void Sub5menu::go_back_to_sub5_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub5_menu();
}

void Sub5menu::print_sub5_menu() {
  std::cout << "\n---------------- Bessel Filters -----------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. Polynomial search       \t\t|\n";
  std::cout << "|\t\t\t 2. coefficient search      \t\t|\n";    
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
  cout << "Bessel filter unlike the amplitude response of Butterworth, Chebyshev and Elliptic filters, there is no simple method and formula to determine the root of B_{n}(s)=0, i.e. the pole of Bessel amplitude response, so we don't provide the calculator for it" << endl;
}

bool Sub5menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub5menu::sub5_item_1() {
  cout << "Bn(s) = s^n + a(n-1)*s^(n-1) + a(n-2)*s^(n-2) + ... + a1*s + a0; (an = 1)" << endl;
  go_back_to_main_menu();
}

void Sub5menu::sub5_item_2() {
  int n;
  cout << "Please put in the value of n";
  cin >> n;
  if (n <= 0) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub5_menu();
  }
  else if(n > 7) {
    cout << "\nInput out of range, Please enter again!";
    go_back_to_sub5_menu();
  }
  else {
    if (n == 1) {
      cout << "a0 = 1" << endl;
    }
    else if (n == 2) {
      cout << "a0 = 3 \na1 = 3" << endl;
    }
    else if (n == 3) {
      cout << "a0 = 15 \na1 = 15 \na2 = 6" << endl;
    }
    else if (n == 4) {
      cout << "a0 = 105 \na1 = 105 \na2 = 45 \na3 = 10" << endl;
    }
    else if (n == 5) {
      cout << "a0 = 945 \na1 = 945 \na2 = 420 \na3 = 105 \na4 = 15" << endl;
    }
    else if (n == 6) {
      cout << "a0 = 10395 \na1 = 10395 \na2 = 4725 \na3 = 1260 \na4 = 210 \na5 = 21" << endl;
    }
    else if (n == 7) {
      cout << "a0 = 135135 \na1 = 135135 \na2 = 62370 \na3 = 17325 \na4 = 3150 \na5 = 378 \na6 = 28" << endl;
    }
    else if (n == 8) {
      cout << "a0 = 2027025 \na1 = 2027025 \na2 = 945945 \na3 = 270270 \na4 = 51975 \na5 = 6930 \na6 = 630 \na7 = 36" << endl;
    }
  }
  go_back_to_main_menu();
}
