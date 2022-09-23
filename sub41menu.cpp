#include "sub41menu1.h"
#include <fstream>

ofstream fout2;

void Sub41menu::sub41_menu() {
  print_sub41_menu();
  int input = get_sub41_input();
  select_sub41_item(input);
}

int Sub41menu::get_sub41_input() {
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

void Sub41menu::select_sub41_item(int input) {
  switch (input) {
    case 1:
      sub41_item_1();
      break;
    case 2:
      sub41_item_2();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub41menu::print_sub41_menu() {
  std::cout << "\n--------------- Chebyshev Filters ---------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. High-Pass Filter        \t\t|\n";
  std::cout << "|\t\t\t 2. Low-Pass Filter         \t\t|\n";   
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
}

void Sub41menu::go_back_to_sub41_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub41_menu();
}

bool Sub41menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub41menu::sub41_item_1() {
  int pole;
  cout << "\nPlease select the ploes of the Circuit (2 or 4 or 6): ";
  cin >> pole;
  if (pole != 2 && pole != 4 && pole != 6) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub41_menu();
  }
  else {
    if (pole == 2) {
      float k = 1.842, c = 0.812, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the circuit equals: " << wc*2*pi*k << "(Hz)" << endl;
      cout << "\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << endl;
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (High-pass)" << "\nThe value of w of the circuit equals: " << wc*2*pi*k << "(Hz)\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << "\nwhen you design the circuit, and the value of gain(K) equals: " << k << "\n" << "\n";
      fout2.close();     
    }
    if (pole == 4) {
      float k1 = 1.582, k2 = 2.66, c1 = 1.675, c2 = 0.97, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (High-pass)" << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\n" << "\n";
      fout2.close(); 
    }
    if (pole == 6) {
      float k1 = 1.537, k2 = 2.448, k3 = 2.846, c1 = 2.525, c2 = 1.302, c3 = 0.989, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      cout << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << endl;
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (High-pass)" << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << "\n" << "\n";
      fout2.close();
    }
  }
  go_back_to_main_menu(); 
}

void Sub41menu::sub41_item_2() {
  int pole;
  cout << "\nPlease select the ploes of the Circuit (2 or 4 or 6): ";
  cin >> pole;
  if (pole != 2 && pole != 4 && pole != 6) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub41_menu();
  }
  else {
    if (pole == 2) {
      float k = 1.842, c = 1.231, wc;
      cout << "\nPlease put in the value of cut-off frequency: ";
      cin >> wc;
      cout << "\nThe value of w of the circuit equals: " << wc*2*pi*k << endl;
      cout << "\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << endl; 
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (Low-pass)" << "\nThe value of w of the circuit equals: " << wc*2*pi*k << "\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << "\n" << "\n";
      fout2.close();     
    }
    if (pole == 4) {
      float k1 = 1.582, k2 = 2.66, c1 = 0.597, c2 = 1.031, wc;
      cout << "\nPlease put in the value of cut-off frequency: ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (Low-pass)" << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\n" << "\n";
      fout2.close();
    }
    if (pole == 6) {
      float k1 = 1.537, k2 = 2.448, k3 = 2.846, c1 = 0.396, c2 = 0.768, c3 = 1.011, wc;
      cout << "\nPlease put in the value of cut-off frequency: ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << endl;
      cout << "\nThe value of w of the third stage equals: " << wc*2*pi*k3 << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      cout << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << endl;
      fout2.open("history.txt", ios::app);
      fout2 << "The solution of Chebyshev 0.5 (Low-pass)" << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << "\n" << "\n";
      fout2.close();
    }
  }
  go_back_to_main_menu(); 
}