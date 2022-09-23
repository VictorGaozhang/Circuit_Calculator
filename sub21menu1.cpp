#include "sub21menu1.h"
#include <fstream>

ofstream fout5;

void Sub21menu::sub21_menu() {
  print_sub21_menu();
  int input = get_sub21_input();
  select_sub21_item(input);
}

int Sub21menu::get_sub21_input() {
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

void Sub21menu::select_sub21_item(int input) {
  switch (input) {
    case 1:
      sub21_item_1();
      break;
    case 2:
      sub21_item_2();
      break;
    case 3:
      sub21_item_3();
      break;
    case 4:
      sub21_item_4();
      break;
    default:
      exit(1);
      break;
  }
}

void Sub21menu::print_sub21_menu() {
  std::cout << "\n---------------- Passive Filters ----------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "|\t\t\t 1. High-Pass Filter        \t\t|\n";
  std::cout << "|\t\t\t 2. Low-Pass Filter         \t\t|\n";  
  std::cout << "|\t\t\t 3. Band-Pass Filter        \t\t|\n";  
  std::cout << "|\t\t\t 4. Band-Stop Filter        \t\t|\n";  
  std::cout << "|\t\t\t\t\t\t\t\t\t\t        |\n";
  std::cout << "-------------------------------------------------\n";  
}

void Sub21menu::go_back_to_sub21_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' to go back to last menu: ";
    std::cin >> input;
  }
  while (input != "b");
  sub21_menu();
}

bool Sub21menu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Sub21menu::sub21_item_1() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t3. LC Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose, order;
  float R1, C1, R, C, L, L1;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the order of the Filter (1 or 2): ";
      cin >> order;
      if (order == 1) {
        cout << "\nPlease put in the value of resistor R(Ohm) : ";
        cin >> R;
        cout << "\nPlease put in the value of capatitor C(uF) : ";
        cin >> C;
        if (R <= 0 || C <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals: (Hz)" << 1/(6.283*R*C) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of High-pass Passive filter N=1 (RC): " << "\nThe value of cut-off frequency equals: " << 1/(6.283*R*C) << "(Hz)\n" << "\n";
          fout5.close();
        }
      } else if (order == 2) {
        cout << "\nPlease put in the value of resistor R1(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of resistor R2(Ohm): ";
        cin >> R1;
        cout << "\nPlease put in the value of capatitor C1(uF): ";
        cin >> C;
        cout << "\nPlease put in the value of capatitor C2(uF): ";
        cin >> C1;
        if (R <= 0 || R1 <= 0 || C <= 0 || C1 <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals(Hz): " << 1/sqrt(6.283*R*C*R1*C1) << "Hz" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of High-pass Passive filter N=2 (RC): " << "\nThe value of cut-off frequency equals: " << 1/sqrt(6.283*R*C*R1*C1) << "(Hz)\n" << "\n";
          fout5.close();
        }        
      } else {
        cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
      }
      break;
    case 2:
      cout << "\nPlease put in the order of the Filter (1 or 2): ";
      cin >> order;
      if (order == 1) {
        cout << "\nPlease put in the value of resistor R(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of inductior L(uH): ";
        cin >> L;
        if (R <= 0 || L <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals: " << R/(6.28*L) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of High-pass Passive filter N=1 (RL): " << "\nThe value of cut-off frequency equals: " << R/(6.28*L) << "(Hz)\n" << "\n";
          fout5.close();
        }        
      } else if (order == 2) {
        cout << "\nPlease put in the value of resistor R1(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of resistor R2(Ohm): ";
        cin >> R1;
        cout << "\nPlease put in the value of inductior L1(uH): ";
        cin >> L;
        cout << "\nPlease put in the value of inductior L2(uH): ";
        cin >> L1;
        if (R <= 0 || R1 <= 0 || L <= 0 || L1 <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals: " << sqrt((R1*R)/(6.28*L*L1)) << "Hz" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of High-pass Passive filter (RL): " << "\nThe value of cut-off frequency equals: " << sqrt((R1*R)/(6.28*L*L1)) << "(Hz)\n" << "\n";
          fout5.close();
        }        
      } else {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      }
      break;
    case 3:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of inductior L(uH): ";
      cin >> L;
      if (R <= 0 || L <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        cout << "\nThe value of cut-off frequency equals: " << 1/(6.28*sqrt(R*L)) << "Hz" << endl;
        fout5.open("history.txt", ios::app);
        fout5 << "The solution of High-pass Passive filter (LC): " << "\nThe value of cut-off frequency equals: " <<  1/(6.28*sqrt(R*L)) << "(Hz)\n" << "\n";
        fout5.close();
      }      
      default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub21menu::sub21_item_2() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t3. LC Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose, order;
  float R1, C1, R, C, L, L1;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the order of the Filter (1 or 2): ";
      cin >> order;
      if (order == 1) {
        cout << "\nPlease put in the value of resistor R(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of capatitor C(uF): ";
        cin >> C;
        if (R <= 0 || C <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals: " << 1/(6.283*R*C) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Low-pass Passive filter N=1 (RC): " << "\nThe value of cut-off frequency equals: " << 1/(6.283*R*C) << "(Hz)\n" << "\n";
          fout5.close();
        }        
      }
      else {
        cout << "\nPlease put in the value of resistor R1(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of resistor R2(Ohm): ";
        cin >> R1;
        cout << "\nPlease put in the value of capatitor C1(uF): ";
        cin >> C;
        cout << "\nPlease put in the value of capatitor C2(uF): ";
        cin >> C1;
        if (R <= 0 || R1 <= 0 || C <= 0 || C1 <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else if (order == 2) {
          cout << "\nThe value of cut-off frequency equals: " << 1/sqrt(6.283*R*C*R1*C1) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Low-pass Passive filter N=2 (RC): " << "\nThe value of cut-off frequency equals: " << 1/sqrt(6.283*R*C*R1*C1) << "(Hz)\n" << "\n";
          fout5.close();
        } else {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      }     
      }
      break;
    case 2:
      cout << "\nPlease put in the order of the Filter (1 or 2): ";
      cin >> order;
      if (order == 1) {
        cout << "\nPlease put in the value of resistor R(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of inductior L(uH): ";
        cin >> L;
        if (R <= 0 || L <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else if (order == 2) {
          cout << "\nThe value of cut-off frequency equals: " << R/(6.283*L) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Low-pass Passive filter N=1 (RL): " << "\nThe value of cut-off frequency equals: " << R/(6.28*L) << "(Hz)\n" << "\n";
          fout5.close();
        } else {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      }
      }
      else {
        cout << "\nPlease put in the value of resistor R1(Ohm): ";
        cin >> R;
        cout << "\nPlease put in the value of resistor R2(Ohm): ";
        cin >> R1;
        cout << "\nPlease put in the value of inductior L1(uH): ";
        cin >> L;
        cout << "\nPlease put in the value of inductior L2(uH): ";
        cin >> L1;
        if (R <= 0 || R1 <= 0 || L <= 0 || L1 <= 0) {
          cout << "Something error of value input, Please enter again !" << endl;
          go_back_to_sub21_menu();
          break;
        } else {
          cout << "\nThe value of cut-off frequency equals: " << sqrt((R*R1)/(6.283*L*L1)) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of HLow-pass Passive filter (RL): " << "\nThe value of cut-off frequency equals: " << sqrt((R1*R)/(6.28*L*L1)) << "(Hz)\n" << "\n";
          fout5.close();
        }        
      }
      break;
    case 3:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of inductior L(uH): ";
      cin >> L;
      if (R <= 0 || L <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        cout << "\nThe value of cut-off frequency equals: " << 1/(6.283*sqrt(R*L)) << "(Hz)" << endl;
        fout5.open("history.txt", ios::app);
        fout5 << "The solution of Low-pass Passive filter (LC): " << "\nThe value of cut-off frequency equals: " <<  1/(6.28*sqrt(R*L)) << "(Hz)\n" << "\n";
        fout5.close();
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub21menu::sub21_item_3() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t3. LC Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R, C1, C2, L1, L2, f, fH, fL, Q;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of capatitor C1(uF): ";
      cin >> C1;
      cout << "\nPlease put in the value of capatitor C2(uF): ";
      cin >> C2;        
      cout << "\nPlease put in the center frequency f0(Hz): ";
      cin >> f;
      if (R <= 0 || C1 <= 0 || C2 <= 0 || f <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = 1/(6.283*R*C1);
        fH = 1/(6.283*R*C2);
        if (fL < fH) {
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" <<  endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << "(Hz)" << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL)<< "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-pass Passive filter (RC): " << "\nThe value of higher frequency fH equals: " << fL << "(Hz)\nThe value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "\n(Hz)The value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
        } else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of inductior L1(uH): ";
      cin >> L1;
      cout << "\nPlease put in the value of inductior L2(uH): ";
      cin >> L2;        
      cout << "\nPlease put in the center frequency f0(Hz): ";
      cin >> f;
      if (R <= 0 || L1 <= 0 || L2 <= 0 || f <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = R/(6.283*L1);
        fH = R/(6.283*L2);
        if (fL < fH) {
          cout << "\nSolution: " << endl;
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" << endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << "(Hz)" << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-pass Passive filter (RL): " << "\nThe value of higher frequency fH equals: " << fL << "(Hz)\nThe value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "(Hz)\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
          }
        else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    case 3:      
      cout << "\nPlease put in the value of capatitor C1(uF): ";
      cin >> C1;
      cout << "\nPlease put in the value of capatitor C2(uF): ";
      cin >> C2;  
      cout << "\nPlease put in the value of capatitor L1(uH): ";
      cin >> L1;
      cout << "\nPlease put in the value of capatitor L2(uH): ";
      cin >> L2;        
      cout << "\nPlease put in the center frequency f0(Hz): ";
      cin >> f;
      if (C1 <= 0 || C2 <= 0 || L1 <= 0 || L2 <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = 1/(6.283*L1*C1);
        fH = 1/(6.283*L2*C2);
        if (fL < fH) {
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" << endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL) << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-pass Passive filter (LC): " << "\nThe value of higher frequency fH equals: " << fL << "(Hz)\nThe value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "(Hz)\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
        }
        else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}

void Sub21menu::sub21_item_4() {
  cout << "------------------ Filter Type ------------------\n";
  cout << "|\t\t\t\t1. RC Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t2. RL Circuit  \t\t\t\t\t|\n";
  cout << "|\t\t\t\t3. LC Circuit  \t\t\t\t\t|\n";
  cout << "-------------------------------------------------\n";
  cout << "Please select the type of filter circuit: \n" << endl;
  int typechoose;
  float R, C1, C2, L1, L2, f, fH, fL, Q;
  cin >> typechoose;
  switch(typechoose) {
    case 1:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of capatitor C1(uF): ";
      cin >> C1;
      cout << "\nPlease put in the value of capatitor C2(uF): ";
      cin >> C2;        
      cout << "\nPlease put in the center frequency f0(uH): ";
      cin >> f;
      if (R <= 0 || C1 <= 0 || C2 <= 0 || f <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = 1/(6.283*R*C1);
        fH = 1/(6.283*R*C2);
        if (fL < fH) {
          cout << "\nSolution: " << endl;
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" << endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << "(Hz)" << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-stop Passive filter (RC): " << "\nThe value of higher frequency fH equals: " << fL << "(Hz)\nThe value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "(Hz)\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
        }
        else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    case 2:
      cout << "\nPlease put in the value of resistor R(Ohm): ";
      cin >> R;
      cout << "\nPlease put in the value of inductior L1(uH): ";
      cin >> L1;
      cout << "\nPlease put in the value of inductior L2(uH): ";
      cin >> L2;
      if (R <= 0 || L1 <= 0 || L2 <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = R/(6.283*L1);
        fH = R/(6.283*L2);
        if (fL < fH) {
          cout << "\nSolution: " << endl;
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" << endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << "(Hz)" << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-stop Passive filter (RL): " << "\nThe value of higher frequency fH equals: " << fL << "(Hz)\nThe value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "(Hz)\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
        }
        else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    case 3:      
      cout << "\nPlease put in the value of capatitor C1(Ohm): ";
      cin >> C1;
      cout << "\nPlease put in the value of capatitor C2(Ohm): ";
      cin >> C2;  
      cout << "\nPlease put in the value of capatitor L1(uH): ";
      cin >> L1;
      cout << "\nPlease put in the value of capatitor L2(uH): ";
      cin >> L2;        
      cout << "\nPlease put in the center frequency f0(Hz): ";
      cin >> f;
      if (C1 <= 0 || C2 <= 0 || L1 <= 0 || L2 <= 0) {
        cout << "Something error of value input, Please enter again !" << endl;
        go_back_to_sub21_menu();
        break;
      } else {
        fL = 1/(6.283*L2*C2);
        fH = 1/(6.283*L1*C1);
        if (fL < fH) {
          cout << "\nThe value of higher frequency fH equals: " << fL << "(Hz)" << endl;
          cout << "\nThe value of lower frequency fL equals: " << fH << "(Hz)" << endl;      
          cout << "\nThe value of bandwidth equals: " << fH-fL << "(Hz)" << endl;
          cout << "\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)" << endl;
          fout5.open("history.txt", ios::app);
          fout5 << "The solution of Band-stop Passive filter (LC): " << "\nThe value of higher frequency fH equals: " << fL << "\n(Hz)The value of lower frequency fL equals: " << fH << "(Hz)\nThe value of bandwidth equals: " << fH-fL << "(Hz)\nThe value of quality factor equals: " << f/(fH-fL) << "(Hz)\n" << "\n";
          fout5.close();
        }
        else {
          cout << "\nIncorrect input parameter" << endl;
          go_back_to_sub21_menu();
        }
        break;
      }      
    default:
      exit(1);
      break;
  }
  go_back_to_main_menu(); 
}
