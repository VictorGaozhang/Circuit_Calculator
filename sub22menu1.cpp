#include "sub22menu1.h"
#include <fstream>

ofstream fout4;

void Sub22menu::sub22_menu() {
  print_sub22_menu();
  int input = get_sub22_input();
  select_sub22_item(input);
}

int Sub22menu::get_sub22_input() {
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

void Sub22menu::select_sub22_item(int input) {
  switch (input) {
    case 1:
      sub22_item_1();
      break;
    case 2:
      sub22_item_2();
      break;
    case 3:
      sub22_item_3();
      break;
    case 4:
      sub22_item_4();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub22menu::print_sub22_menu() {
  std::cout << "\n---------------- Active Filters -----------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. High-Pass Filter        \t\t|\n";
  std::cout << "|\t\t\t 2. Low-Pass Filter         \t\t|\n";  
  std::cout << "|\t\t\t 3. Band-Pass Filter        \t\t|\n";  
  std::cout << "|\t\t\t 4. Band-Stop Filter        \t\t|\n";  
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";
}

void Sub22menu::go_back_to_sub22_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub22_menu();
}

bool Sub22menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub22menu::sub22_item_1() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R1, R2, C, L, A, s;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor Rg(series with power)(Ohm): ";
      cin >> R1;
      cout << "Please put in the value of resistor Rf(parallel with capacitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of capatitor C(uF): ";
      cin >> C;   
      cout << "\nPlease put in the value of s(jw): ";
      cin >> s;
      if (R1 <= 0 || R2 <= 0 || C <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        A = -(R2/R1)*(1/(R2*C))/(s+1/(R2*C));
        cout << "\nThe value of cut-off frequency equals: " << 1/(6.283*R2*C) << "(Hz)" << endl;
        cout << "\nThe value of Vout/Vin Av equals: " << A << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Hign-pass Active filter (RC): " << "\nThe value of cut-off frequency equals: " << 1/(6.283*R2*C) << "\n(Hz)The value of Vout/Vin Av equals: " << A << "(Hz)\n" << "\n"; 
        fout4.close();
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor Rg(series with power)(Ohm): ";
      cin >> R1;
      cout << "Please put in the value of resistor Rf(parallel with capacitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of induction L(uH): ";
      cin >> L;
      cout << "\nPlease put in the value of s(jw): ";
      cin >> s;
      if (R1 <= 0 || R2 <= 0 || L <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        A = -(R2/R1)*(L/R2)/(s+L/R2);
        cout << "\nThe value of cut-off frequency equals: " << L/(6.28*R2) << "(Hz)" << endl;  
        cout << "\nThe value of Vout/Vin Av equals: " << A << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Hign-pass Active filter (RL): " << "\nThe value of cut-off frequency equals: " << L/(6.28*R2) << "\n(Hz)The value of Vout/Vin Av equals: " << A << "(Hz)\n" << "\n"; 
        fout4.close();
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub22menu::sub22_item_2() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R, C, L, A, w;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of capatitor C(uF): ";
      cin >> C;   
      cout << "\nPlease put in the value of w(Hz): ";
      cin >> w;
      if (R <= 0 || C <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        A = 1/sqrt(1+pow(R*w*C,2));
        cout << "\nThe value of cut-off frequency equals: " << 1/(6.283*R*C) << "(Hz)" << endl;
        cout << "\nThe value of Vout/Vin Av equals: " << A << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Low-pass Active filter (RC): " << "\nThe value of cut-off frequency equals: " << 1/(6.28*R*C) << "(Hz)" << "\nThe value of Vout/Vin Av equals: " << A << "(Hz)\n" << "\n"; 
        fout4.close();
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of capatitor C(uF): ";
      cin >> L;   
      cout << "\nPlease put in the value of w: ";
      cin >> w;
      if (R <= 0 || L <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        A = 1/sqrt(1+pow(R*w*(1/L),2));
        cout << "\nThe value of cut-off frequency equals: " << L/(6.283*R) << "(Hz)" << endl;
        cout << "\nThe value of Vout/Vin Av equals: " << A << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Low-pass Active filter (RL): " << "\nThe value of cut-off frequency equals: " << L/(6.28*R) << "(Hz)\nThe value of Vout/Vin Av equals: " << A << "(Hz)\n" << "\n"; 
        fout4.close();
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub22menu::sub22_item_3() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R1, R2, R3, R4, Rf, C, L, f, A, BW, w;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor R1(series with power)(Ohm): ";
      cin >> R1;
      cout << "\nPlease put in the value of resistor R2(partial pressure for power and capatitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of resistor R3(parallel with capatitor)(Ohm): ";
      cin >> R3;        
      cout << "\nPlease put in the value of resistor R4(parallel with the whole circuit)(Ohm): ";
      cin >> R4;
      cout << "\nPlease put in the value of resistor Rf(Ohm): ";
      cin >> Rf;
      cout << "\nPlease put in the value of capatitoor C(C1=C2=C)(uF): ";
      cin >> C;
      if (R1 <= 0 || R2 <= 0 || R3 <= 0 || R4 <= 0 || Rf <= 0 || C <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        w = sqrt((1/R1+1/R2)/(R3*pow(C,2)));
        BW = 1/C*(1/R1+2/R2-Rf/(R3*R4));
        f = sqrt((1/R1+1/R2)/R2*pow(C,2))/6.283;
        A = (R4+Rf)/(R4*R1*C*BW);
        cout << "\nThe value of center angular frequency equals: " << w << endl;
        cout << "\nThe value of center frequency f equals: " << f << endl;
        cout << "\nThe value of the pass band gain Av equals: " << A << endl;
        cout << "\nThe value of bandwidth equals: " << BW << endl;
        cout << "\nThe value of quality factor Q equals: " << w/BW << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Low-pass Active filter (RC): " << "\nThe value of center angular frequency equals: " << w << "(Hz)\nThe value of center frequency f equals: " << f << "(Hz)\nThe value of the pass band gain Av equals: " << A << "\nThe value of bandwidth equals: " << BW << "(Hz)\nThe value of Q equals: " << w/BW << "\n" << "\n"; 
        fout4.close();
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor R1(series with power)(Ohm): ";
      cin >> R1;
      cout << "\nPlease put in the value of resistor R2(partial pressure for power and capatitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of resistor R3(parallel with capatitor)(Ohm): ";
      cin >> R3;        
      cout << "\nPlease put in the value of resistor R4(parallel with the whole circuit)(Ohm): ";
      cin >> R4;
      cout << "\nPlease put in the value of resistor Rf(Ohm): ";
      cin >> Rf;
      cout << "\nPlease put in the value of capatitoor L(L1=L2=L)(uH): ";
      cin >> L;
      if (R1 <= 0 || R2 <= 0 || R3 <= 0 || R4 <= 0 || Rf <= 0 || L <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        w = sqrt((1/R1+1/R2)/(R3*pow(C,2)));
        BW = L*(1/R1+2/R2-Rf/(R3*R4));
        f = sqrt((1/R1+1/R2)/R2*pow(1/L,2))/6.283;
        A = L*(R4+Rf)/(R4*R1*BW);
        cout << "\nThe value of center angular frequency equals: " << w << "(Hz)" << endl;
        cout << "\nThe value of center frequency f equals: " << f << "(Hz)" << endl;
        cout << "\nThe value of the pass band gain Av equals: " << A << endl;
        cout << "\nThe value of bandwidth equals: " << BW << "(Hz)" << endl;
        cout << "\nThe value of quality factor Q equals: " << w/BW << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Low-pass Active filter (RC): " << "\nThe value of center angular frequency equals: " << w << "(Hz)\nThe value of center frequency f equals: " << f << "(Hz)\nThe value of the pass band gain Av equals: " << A << "\nThe value of bandwidth equals: " << BW << "\nThe value of Q equals: " << w/BW << "\n" << "\n"; 
        fout4.close();
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub22menu::sub22_item_4() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R1, R2, R3, R4, Rf, C, L, f, A, BW, w;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor R1(series with power)(Ohm): ";
      cin >> R1;
      cout << "\nPlease put in the value of resistor R2(partial pressure for power and capatitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of resistor R3(parallel with capatitor)(Ohm): ";
      cin >> R3;        
      cout << "\nPlease put in the value of resistor R4(parallel with the whole circuit)(Ohm): ";
      cin >> R4;
      cout << "\nPlease put in the value of resistor Rf(Ohm): ";
      cin >> Rf;
      cout << "\nPlease put in the value of capatitoor C(C1=C2=C)(uF): ";
      cin >> C;
      if (R1 <= 0 || R2 <= 0 || R3 <= 0 || R4 <= 0 || Rf <= 0 || C <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        w = sqrt((1/R1+1/R2)/(R3*pow(C,2)));
        BW = 1/C*(1/R1+2/R2-Rf/(R3*R4));
        f = sqrt((1/R1+1/R2)/R2*pow(C,2))/6.283;
        A = (R4+Rf)/(R4*R1*C*BW);
        cout << "\nThe value of center angular frequency equals: " << w << "(Hz)" << endl;
        cout << "\nThe value of center frequency f equals: " << f << endl;
        cout << "\nThe value of the elimination band gain Av equals: " << A << endl;
        cout << "\nThe value of bandwidth equals: " << BW << "(Hz)" << endl;
        cout << "\nThe value of quality factor Q equals: " << w/BW << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Band-pass Active filter (RC): " << "\nThe value of center angular frequency equals: " << w << "(Hz)\nThe value of center frequency f equals: " << f << "(Hz)\nThe value of the pass band gain Av equals: " << A << "\nThe value of bandwidth equals: " << BW << "\nThe value of Q equals: " << w/BW << "\n" << "\n"; 
        fout4.close();
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor R1(series with power)(Ohm): ";
      cin >> R1;
      cout << "\nPlease put in the value of resistor R2(partial pressure for power and capatitor)(Ohm): ";
      cin >> R2;
      cout << "\nPlease put in the value of resistor R3(parallel with capatitor)(Ohm): ";
      cin >> R3;        
      cout << "\nPlease put in the value of resistor R4(parallel with the whole circuit)(Ohm): ";
      cin >> R4;
      cout << "\nPlease put in the value of resistor Rf(Ohm): ";
      cin >> Rf;
      cout << "\nPlease put in the value of capatitoor L(L1=L2=L)(uF): ";
      cin >> L;
      if (R1 <= 0 || R2 <= 0 || R3 <= 0 || R4 <= 0 || Rf <= 0 || C <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub22_menu();
        break;
      } else {
        w = sqrt((1/R1+1/R2)/(R3*pow(C,2)));
        BW = L*(1/R1+2/R2-Rf/(R3*R4));
        f = sqrt((1/R1+1/R2)/R2*pow(1/L,2))/6.283;
        A = L*(R4+Rf)/(R4*R1*BW);
        cout << "\nThe value of center angular frequency equals: " << w << "(Hz)" << endl;
        cout << "\nThe value of center frequency f equals: " << f << "(Hz)" << endl;
        cout << "\nThe value of the elimination band gain Av equals: " << A << endl;
        cout << "\nThe value of bandwidth equals: " << BW << "(Hz)" << endl;
        cout << "\nThe value of quality factor Q equals: " << w/BW << endl;
        fout4.open("history.txt", ios::app);
        fout4 << "The solution of Band-stop Active filter (RC): " << "\nThe value of center angular frequency equals: " << w << "(Hz)\nThe value of center frequency f equals: " << f << "(Hz)\nThe value of the pass band gain Av equals: " << A << "\nThe value of bandwidth equals: " << BW << "(Hz)\nThe value of Q equals: " << w/BW << "\n" << "\n"; 
        fout4.close(); 
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}
