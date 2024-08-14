// Calculator.cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Calculator.h"



double calculate(std::string string_input, bool boolvalue){
    // todo: testing
    double num1 = 0.0, num2 = 0.0, result = 0.0;
    std::string sign = "", test = "";
    stringstream stream;

    stream << string_input;
    stream >> num1;
    stream >> sign;
    stream >> num2;

    // testing for too many inputs
    if (!stream.eof() || stream.fail()){
        cout << "Error, invalid input.\n\n";
        boolvalue = false;
        return 0.0;
    }

    //Checking operations
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
        cout << "Invalid sign.\n\n";
        boolvalue = false;
        return 0.0;
    }

    return 0.0;
}

void help(){
    std::string user_input;
    std::cout << "What would you like help on?\n" << "C - Calculator\nU - Update Log\nL - History Log\n";
    std::getline(std::cin, user_input);

    if (user_input == "C" || user_input == "c"){
        std::cout << "----------------\n\n"
        << "A simple program that can only perform basic arithmetic\n\n"
        << "How to use:\n"
        << "Enter input in the following format: (num1) (operation sign) (num2)\n"
        << "Example: '2 + 4' is a valid argument, but '9 0 / 1' and '8 minus 9' are not.\n\n"
        << "Valid operations: \n"
        << "'+' : Addition\n'-' : Subtraction\n'*' : Multiplication\n'/' : Division\n\n"
        << "Limitations:\nCan only perform simple functions (addition, subtraction, multiplication, division\n)"
        << "Can only perform arithmetic on two numbers max.\n"
        << "Does not support parentheses or PEMDAS\n\n"
        << "----------------\n\n"
        << "Returning to homescreen now.\n\n";
    }
    else if (user_input == "U" || user_input == "u"){
        std::cout << "----------------\n\n"
        << "A log with version updates if any. Will add new features or fix old bugs.\n\n"
        << "----------------\n\n"
        << "Returning to homescreen now.\n\n";
    }
    else if (user_input == "L" || user_input == "l"){
        std::cout << "----------------\n\n"
        <<"A history of all previous calculations."
        << "This will print out all previous calculations oldest to newest."
        << " There is also an option to clear the history.\n\n"
        << "----------------\n\n"
        << "Returning to homescreen now.\n\n";
    }
    else {
        std::cout << "Invalid input, going back to homescreen.\n\n";
    }

}

void update_log(){
    std::cout << "----------------\n\n"
    << "Update Log:\n"
    << "No updates as of now, still in development. Will give general updates here,"
    << " but detailed updates can be found on https://github.com/hnguyennn/Calculator \n\n"
    << "----------------\n\n"
    << "Returning to homescreen now.\n\n";
}

void history_log(){
    // todo: use a link list and print out the history. add extra option to clear if wanted.
    std::cout << "Still in development. \n\n";
}
void program(){
    std::string user_input="A", expression_input;
    bool boolexpression=true;
    double result=0;

    while (user_input != "Q" && user_input != "q"){
        std::cout << "What would you like to do next?\n";
        std::cout << "C - Calculate \nH - Help\nL - History log\nU - Update Log\nQ - Quit\n\n";
        std::getline(std::cin, user_input);

        if (user_input == "C" || user_input == "c"){
            boolexpression = true; //currently not working
            std::cout << "Please enter a valid expression: ";
            std::getline(std::cin, expression_input);
            result = calculate(expression_input,boolexpression);
            if (boolexpression == true){
                std::cout << expression_input << " = " << result << "\n\n";
            }
            //save to history log

    
        }

        else if (user_input == "H" || user_input =="h"){
            help();
        }

        else if (user_input == "L" || user_input == "l"){
            history_log();
        }

        else if (user_input == "U" || user_input == "u"){
            update_log();
        }

        else if (user_input == "Q" || user_input == "q"){
            std::cout << "Ok, see you next time!\n\n";
        }

        else {
            std::cout << "Invalid input, try again.\n\n";
        }
    }
}

int main(){
    // run the program and create linked list
    program();
    return 0;
}