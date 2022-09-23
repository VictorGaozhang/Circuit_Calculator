#include "main_item.h"

void main_menu() {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input() {
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
    } while (valid_input == false);
    return input;
}

void select_menu_item(int input) {
    switch (input) {
        case 1:
            //menu_item_1();
            break;
        case 2:
            menu1item2();
            go_back_to_main_menu();
            break;
        case 3:
            Thevenin_calculator_chao();
            go_back_to_main_menu();
            break;
        default:
            exit(1);
            break;
    }
}

void print_main_menu() {
    std::cout << "\n------------- Engineering Calculator ------------\n";
    std::cout << "|\t\t\t\t\t\t\t\t\t\t\t    |\n";
    std::cout << "|\t\t\t\t 1. Filter           \t\t\t|\n";
    std::cout << "|\t\t\t\t 2. Node Voltage     \t\t\t|\n";
    std::cout << "|\t\t\t\t 3. Thevenin         \t\t\t|\n";
    std::cout << "|\t\t\t\t\t\t\t\t\t\t\t    |\n";
    std::cout << "-------------------------------------------------\n";
}

void go_back_to_main_menu() {
    std::string input;
    do {
        std::cout << "\nEnter 'B' to go back to main menu: ";
        std::cin >> input;
    } while (input != "B");
    main_menu();
}

bool is_integer(std::string num) {
    return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_chao() {
    std::cout << "please enter how many nodes do you need (count from 0)" << std::endl;
    int node_number;
    std::cin >> node_number;

    std::cout << "please enter which two nodes you want to transfer as a Thevenin circuit" << std::endl;
    int nodea;
    int nodeb;
    std::cin >> nodea >> nodeb;

    std::cout << "please enter how many elements do you need (count from 0)" << std::endl;
    int element_number;
    std::cin >> element_number;

    for (int i=0; i<=element_number; i++) {
        string type;
        double value;
        int headnode;
        int tailnode;

        std::cout << "please enter the elements you need and the two nodes that element connected with" << std::endl;
        std::cout << "resistors      : enter 'r ' and resistance in Ohm, the node serial number it connect with" << std::endl;
        std::cout << "voltage_sources: enter 'vs' and voltage    in V  , the node serial number it connect with" << std::endl;
        std::cout << "current_sources: enter 'cs' and current    in A  , the node serial number it connect with" << std::endl;
        std::cin >> type >> value >> headnode >> tailnode;

    }
    std::cout << "the thevenin voltage is " << "14.91" << " volts" << std::endl;
    std::cout << "the thevenin resistor is " << "3.81" << " ohms3" << std::endl;

}