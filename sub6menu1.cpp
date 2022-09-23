#include "sub6menu1.h"
#include <fstream>

ofstream fout; 

void Sub6menu::sub6_menu() {
  print_sub6_menu();
  int input = get_sub6_input();
  select_sub6_item(input);
}

int Sub6menu::get_sub6_input() {
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

void Sub6menu::select_sub6_item(int input) {
  switch (input) {
    case 1:
      sub6_item_1();
    case 2:
      sub6_item_2();
    case 3:
      sub6_item_3();
    case 4:
      sub6_item_4();
    default:
      exit(1);
      break;
  }
}

void Sub6menu::go_back_to_sub6_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub6_menu();
}

void Sub6menu::print_sub6_menu() {
  std::cout << "For general topology, we expline all components (R1, R2, C1, C2) as Z1, Z2, Z3, Z4 respectively, and we could also choose one of the pass filter to design, we will only consider Sallen_Key filters designed with op-amps, we just provide some simple calculator here, more information could be found in 3 types of filter above: ";
  std::cout << "\n------------------ Sallen-Key -------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. General topology        \t\t|\n";
  std::cout << "|\t\t\t 2. Low-pass Circuit        \t\t|\n";  
  std::cout << "|\t\t\t 3. High-pass Circuit       \t\t|\n";
  std::cout << "|\t\t\t 4. Band-pass Circuit       \t\t|\n";  
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";  
}

bool Sub6menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub6menu::sub6_item_1() {
  float Z1, Z2, Z3, Z4, A;
  std::cout << "\nPlease put in the value of Z1, Z2, Z3, Z4 respectively: ";
  std::cin >> Z1;
  std::cin >> Z2;
  std::cin >> Z3;
  std::cin >> Z4;  
  A = Z3*Z4/(Z1*Z2 + Z3*(Z1+Z2) + Z3*Z4);
  if (A <= 0) {
    cout << "Something wrong about the values input" << endl;
    go_back_to_sub6_menu();    
  } else {
    std::cout << "\nThe value of Vout / Vin equals: " << A << endl;
    fout.open("history.txt", ios::app);
    fout << "The solution of Sallen-Key (General topology): " << "\nThe value of Vout / Vin equals: " <<  A << "\n" << "\n"; 
    fout.close();
    go_back_to_main_menu();
  } 
}

void Sub6menu::sub6_item_2() {
  float Z1, Z2, Z3, Z4, A;
  std::cout << "\nPlease put in the value of R1, R2(Ohm), C1, C2(uF) respectively: ";
  std::cin >> Z1;
  std::cin >> Z2;
  std::cin >> Z3;
  std::cin >> Z4;
  A = Z3*Z4/(Z1*Z2 + Z3*(Z1+Z2) + Z3*Z4);
  if (A <= 0) {
    cout << "Something wrong about the values input" << endl;
    go_back_to_sub6_menu();    
  } else {
    std::cout << "\nThe value of Vout / Vin equals: " << A << endl;  
    fout.open("history.txt", ios::app);
    fout << "The solution of Sallen-Key (Low-pass Circuit): " << "\nThe value of Vout / Vin equals: " << A << "\n" << "\n";
    fout.close();
  }
  go_back_to_main_menu();
}

void Sub6menu::sub6_item_3() {
  float Z1, Z2, Z3, Z4, A;
  std::cout << "\nPlease put in the value of C1, C2(uF), R1, R2(Ohm) respectively: ";
  std::cin >> Z1;
  std::cin >> Z2;
  std::cin >> Z3;
  std::cin >> Z4;
  A = Z3*Z4/(Z1*Z2 + Z3*(Z1+Z2) + Z3*Z4);
  if (A <= 0) {
    cout << "Something wrong about the values input" << endl;
    go_back_to_sub6_menu();    
  } else {
    std::cout << "\nThe value of Vout / Vin equals: " << A << endl;
    fout.open("history.txt", ios::app);
    fout << "The solution of Sallen-Key (High-pass Circuit): " << "\nThe value of Vout / Vin equals: " << A << "\n" << "\n";
    fout.close();
  }
  go_back_to_main_menu();
}

void Sub6menu::sub6_item_4() {
  float Z1, Z2, Z3, A;
  std::cout << "\nPlease put in the value of w0, w1, w2 respectively: ";
  std::cin >> Z1;
  std::cin >> Z2; 
  std::cin >> Z3; 
  A = Z1/(Z3-Z2);
  if (A <= 0) {
    cout << "Something wrong about the values input" << endl;
    go_back_to_sub6_menu();    
  } else {
    std::cout << "\nThe value of Q equals: " << A << endl;   
    fout.open("history.txt", ios::app);
    fout << "The solution of Sallen-Key (Band-pass Circuit): " << A << "\n" << "\n";
    fout.close();
  }
  go_back_to_main_menu();
}
