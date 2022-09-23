#include "sub3menu1.h"
#include <fstream>

ofstream fout3;

void Sub3menu::sub3_menu() {
  print_sub3_menu();
  int input = get_sub3_input();
  select_sub3_item(input);
}

int Sub3menu::get_sub3_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 3;

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

void Sub3menu::select_sub3_item(int input) {
  switch (input) {
    case 1:
      sub3_item_1();
      break;
    case 2:
      sub3_item_2();
      break;
    case 3:
      sub3_item_3();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub3menu::print_sub3_menu() {
  std::cout << "\n-------------- ButterWorth Filters --------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. Order N Calculator      \t\t|\n";
  std::cout << "|\t\t\t 2. Poles P Calculator      \t\t|\n";
  std::cout << "|\t\t\t 3. Amplitude Calculator    \t\t|\n"; 
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
}

void Sub3menu::go_back_to_sub3_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub3_menu();
}

bool Sub3menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub3menu::sub3_item_1() {
  float Sa, Pa, Sb, Pb;
  int N;
  cout << "\nPlease put in the value of Stopband Attenuation: ";
  cin >> Sa;
  cout << "\nPlease put in the value of Passband Attenuation: ";
  cin >> Pa;
  cout << "\nPlease put in the value of Stopband: ";
  cin >> Sb;
  cout << "\nPlease put in the value of Passband: ";
  cin >> Pb;
  N = ceil(0.5*( log10 (( pow (10, Sa/10) - 1)/( pow (10, Pa/10) - 1)) / log10 (Sb/Pb) ));
  if (N <= 0) {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub3_menu();
  }
  cout << "The value of N equals: " << N << endl;
  fout3.open("history.txt", ios::app);
  fout3 << "The solution of ButterWorth (Order N): " << N << "\n" << "\n"; 
  fout3.close();
  go_back_to_main_menu();
}

void Sub3menu::sub3_item_2() {
  int N, count = 0;
  vector<float> poles_y;
  vector<float> poles_x;
  float cutoff;   
  cout << "\nPlease put in the value of Cutoff band (Hz): ";
  cin >> cutoff;
  cout << "\nPlease put in the order N: ";
  cin >> N;
  if (N > 0) {
    for(int k = 0; k <= ((2*N)-1) ; k++) {
      if(cutoff*cos((2*k+N-1)*(pi/(2*N))) < 0.0) {	   
        poles_x.push_back (-cutoff*cos((2*k+N-1)*(pi/(2*N))));
        poles_y.push_back (-cutoff*sin((2*k+N-1)*(pi/(2*N)))); 
        count++;
        if (count == N) break;
      }    
    }
    cout << "\nThe poles of Butterworth are: " << endl;
    for (int i = 0; i < N; i++) {      
      cout << " (" << poles_x[i] << " , " << poles_y[i] << ") ";
      cout << endl;
    }
    for (int i = 0; i < N; i++) { 
      fout3.open("history.txt", ios::app);
      fout3 << "The solution of ButterWorth (Poles): " << " (" << poles_x[i] << " , " << poles_y[i] << ") " << "\n";        
    }
    cout << "\n";
    fout3.close(); 
  }
  else {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub3_menu();
  }
  go_back_to_main_menu();
}

void Sub3menu::sub3_item_3() {
  int N;
  float w, wc, Gn;
  cout << "\nPlease put in the value of frequency w(Hz): ";
  cin >> w;
  cout << "\nPlease put in the value of cutoff-frequency wc(Hz): ";
  cin >> wc;
  cout << "\nPlease put in the value of order N: ";
  cin >> N;
  if (N > 0) {
    Gn = 1/ (sqrt(1 + pow((w/wc), 2)));
    cout << "\nThe value of Amplitude equals: " << Gn << endl;
    fout3.open("history.txt", ios::app);
    fout3 << "The solution of ButterWorth (Amplitude): " << Gn << "\n" << "\n"; 
    fout3.close();
  }
  else {
    cout << "\nThe parameters input error, Please enter again!";
    go_back_to_sub3_menu();
  }
  go_back_to_main_menu();
}
