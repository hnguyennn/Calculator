// Calculator.cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Calculator.h"


double calculate(std::string string_input){
    // todo: do logic for main calculator, max 2 numbers
    double num1 = 0.0, num2 = 0.0, result = 0.0;
    std::string sign = "", test = "";
    stringstream stream;

    stream << string_input;
    stream >> num1;
    stream >> sign;
    stream >> num2;

    // testing for too many inputs
    test = stream.str();
    if (test != ""){
        cout << "Error, invalid input.";
        return 0.0;
    }

    // dont forget to write instructions for the signs
    if (sign == "+"){
        result = num1 + num2;
        return result;
    }
    else if (sign == "-"){
        result = num1 - num2;
        return result;
    }
    else if (sign == "*"){
        result = num1 * num2;
        return result;
    }
    else if (sign == "/"){
        result = num1 / num2;
        return result;
    }
    else { // case when invalid sign
        cout << "Invalid sign.";
        return 0.0;
    }

    return 0.0;
}

void help(){
    // todo: print out instructions and examples of expected inputs

}

std::string history_log(){
    // todo: use a link list and print out the history. add extra option to clear if wanted.
    return "";
}
void program(){
    std::string user_input="A";
    double result=0;

    std::cout << "What would you like to do next?";


    while (user_input != "Q"){
        std::cout << "C - Calculate \nH - Help\nL - History log\nQ - Quit";
        std::getline(std::cin, user_input);
        if (user_input == "C"){
            result = calculate(user_input);
        }
        else if (user_input == "H"){
            help();
        }
        else if (user_input == "L"){
            history_log();
        }
        else if (user_input == "Q"){
            std::cout << "Ok, see you next time!";
        }
        else {
            std::cout << "Invalid input, try again.";
        }
    }
}

int main(){
    // run the program and create linked list
    return 0;
}