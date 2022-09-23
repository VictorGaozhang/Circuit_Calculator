#include "sub42menu1.h"
#include <fstream>

ofstream fout1;

void Sub42menu::sub42_menu() {
  print_sub42_menu();
  int input = get_sub42_input();
  select_sub42_item(input);
}

int Sub42menu::get_sub42_input() {
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

void Sub42menu::select_sub42_item(int input) {
  switch (input) {
    case 1:
      sub42_item_1();
      break;
    case 2:
      sub42_item_2();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub42menu::print_sub42_menu() {
  std::cout << "\n--------------- Chebyshev Filters ---------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. High-Pass Filter        \t\t|\n";
  std::cout << "|\t\t\t 2. Low-Pass Filter         \t\t|\n";   
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
}

void Sub42menu::go_back_to_sub42_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub42_menu();
}

bool Sub42menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub42menu::sub42_item_1() {
  int pole;
  cout << "\nPlease select the ploes of the Circuit (2 or 4 or 6): ";
  cin >> pole;
  if (pole != 2 || pole != 4 || pole != 6) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub42_menu();
  }
  else {
    if (pole == 2) {
      float k = 2.114, c = 1.103, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the circuit equals: " << wc*2*pi*k << "(Hz)" << endl;
      cout << "\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << endl;
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (High-Pass): " <<  "\nThe value of w of the circuit equals: " << wc*2*pi*k<< "(Hz)\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << "\n" << "\n";
      fout1.close();    
    }
    if (pole == 4) {
      float k1 = 1.924, k2 = 2.782, c1 = 2.123, c2 = 1.037, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;      
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (High-Pass): " <<  "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\n" << "\n";
      fout1.close(); 
    }
    if (pole == 6) {
      float k1 = 1.891, k2 = 2.648, k3 = 2.904, c1 = 3.165, c2 = 1.370, c3 = 0.983, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      cout << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << endl;
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (High-Pass): " << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << "\n" << "\n";
      fout1.close();
    }
  }  
  go_back_to_main_menu(); 
}

void Sub42menu::sub42_item_2() {
  int pole;
  cout << "\nPlease select the ploes of the Circuit (2 or 4 or 6): ";
  cin >> pole;
  if (pole != 2 || pole != 4 || pole != 6) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub42_menu();
  }
  else {
    if (pole == 2) {
      float k = 2.114, c = 0.907, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the circuit equals: " << wc*2*pi*k << "(Hz)" << endl;
      cout << "\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << endl;
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (Low-Pass): " <<  "\nThe value of w of the circuit equals: " << wc*2*pi*k << "(Hz)\nThe value of RC should be " << 1/((wc*2*pi*k)*c) << " when you design the circuit, and the value of gain(K) equals: " << k << "\n" << "\n";
      fout1.close();       
    }
    if (pole == 4) {
      float k1 = 1.924, k2 = 2.782, c1 = 0.471, c2 = 0.946, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (Low-Pass): " <<  "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\n" << "\n";
      fout1.close(); 
    }
    if (pole == 6) {
      float k1 = 1.891, k2 = 2.648, k3 = 2.904, c1 = 0.316, c2 = 0.730, c3 = 0.983, wc;
      cout << "\nPlease put in the value of cut-off frequency(Hz): ";
      cin >> wc;
      cout << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)" << endl;
      cout << "\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)" << endl;
      cout << "\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)" << endl;
      cout << "\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << endl;
      cout << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << endl;
      cout << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << endl;
      fout1.open("history.txt", ios::app);
      fout1 << "The solution of Chebyshev (Low-Pass): " << "\nThe value of w of the first stage equals: " << wc*2*pi*k1 << "(Hz)\nThe value of w of the seconnd stage equals: " << wc*2*pi*k2 << "(Hz)\nThe value of w of the third stage equals: " << wc*2*pi*k3 << "(Hz)\nThe value of RC in first stage should be " << 1/((wc*2*pi*k1)*c1) << " when you design the circuit, and the value of gain(K) equals: " << k1 << "\nThe value of RC in second stage should be " << 1/((wc*2*pi*k2)*c2) << " when you design the circuit, and the value of gain(K) equals: " << k2 << "\nThe value of RC in third stage should be " << 1/((wc*2*pi*k3)*c3) << " when you design the circuit, and the value of gain(K) equals: " << k3 << "\n" << "\n";
      fout1.close(); 
    }
  }
  go_back_to_main_menu(); 
}