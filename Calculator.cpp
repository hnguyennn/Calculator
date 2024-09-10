// Calculator.cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Calculator.h"
#include "History_Log.cpp"



double calculate(std::string string_input, History_Log& memory_log){
    // todo: testing, fix logic to include 'ans', fix error where if only 1 num, num1 = 0
    double num1 = 0.0, num2 = 0.0, result = 0.0, previous_answer_memory = memory_log.get_previous_answer_memory();
    std::string sign = "+", test = "", stringNum;
    bool success = true;
    stringstream stream;

    stream << string_input;

    // Check the first number if its a digit or 'Ans'
    stream >> stringNum;
    //cout << "First attempt to saving number: " <<  stringNum << "\n\n";
    num1 = convert_to_digits(stringNum, previous_answer_memory, success);
    if (success == false){ // Not a valid number
        std::cout << "Error: Invalid input, check 'Help' for the proper format.\n\n";
        return 0.0; //find a way to cancel
    }
    //cout << "**num1 is " << num1 << "\n and num2 is " << num2;

    while (stream >> sign){
        stream >> stringNum; // Check if next input is a number
        num2 = convert_to_digits(stringNum, previous_answer_memory, success);
        //cout << "\nnum2 is " << num2 << "\n\n";
        if (success == false){
            std::cout << "Error: Invalid input, check 'Help' for the proper format.\n\n";
            return 0.0; //find a way to cancel
        }

        // Calculate
        result = calculate_expression(num1, num2, sign);
        //cout << "result is: " << result << "\n\n";
        num1 = result;
        //cout << "num1 is" << num1 << "\n\n";  
    }
    //cout << "returning num1: " << num1 << "\n\n";
    return num1;
    
}


double calculate_expression(double num1, double num2, std::string sign){
    double result = 0.0;
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
        if (num2 == 0){
            cout << "\nNumbers cannot be divided by 0";
        }
        else {
        result = num1 / num2;
        }
        return result;
    }
    else { // case when invalid sign
        cout << "Error: Invalid sign.\n\n";
        return 0.0;
    }
}

double convert_to_digits(std::string string_num, double previous_answer_memory, bool& success){
// Check if it is digits or 'ans' and if it is, return appropriate value. if not, assign success = false and return.
    if (!((all_of(string_num.begin(), string_num.end(), ::isdigit)) || string_num == "Ans" || string_num == "ans")){
        success = false;
        return 0.0;
    }
    else { // Valid input
        if ((all_of(string_num.begin(), string_num.end(), ::isdigit))){ //stringNum is a double value
            success = true;
            return std::stod(string_num);
        }
        else if (string_num == "Ans" || string_num == "ans"){ //stringNum is trying to access previous answer memory
            success = true;
            return previous_answer_memory;
        }
    }
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
        << "Limitations:\n-> Can only perform simple functions (addition, subtraction, multiplication, division)\n"
        << "-> Expression is evaluated from left to right.\n"
        << "-> Does not support parentheses or PEMDAS\n\n"
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
        << "This will print out all previous calculations oldest to newest. "
        << "There will also be an option to clear the history.\n\n"
        << "To use the 'Previous Answer Memory' function, when typing in your expression, represent your "
        << "previous answer value with the words 'Ans' or 'ans'. Only these two variations of the word work. "
        << "If the history log is currently empty, previous answer memory's value will be 0.\n"
        << "Ex: If the 'previous answer memory' value is 10, and the expression inputted is '25 + Ans', "
        << "then, the result will be 35.\n\n"
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
    << "9/2/2024\n"
    << "-----\n"
    << "-> 'Calculate' can now handle more than 2 numbers at a time.\n"
    << "-> Logic is updated and covers more wrong cases, including division by zero.\n"
    << "-> The 'Calculate' section under 'Help' has also been updated.\n"
    << "-----\n"
    << "9/8/2024\n"
    << "-----\n"
    << "-> 'History log' feature has been added. This feature serves to hold memory of 20 expressions maximum. "
    << "It can currently only allow the user to view the memory, from oldest to newest, and will have a 'clear' feature in the future.\n"
    << "-> 'Calculate' has been updated to save the inputted expression to the history log. There is a known error where it will attempt"
    << " to save the expression, even if it is an invalid one. Will be fixed in the future."
    << "-----\n"
    << "\nMore detailed updates can be found on https://github.com/hnguyennn/Calculator \n"
    << "----------------\n\n"
    << "Returning to homescreen now.\n\n";
}

void history_log(History_Log& memory_log){
    // todo: use a link list and print out the history. add extra option to clear if wanted.
    std::string user_input="A", view_memory_string = "";
    std::cout << "How would you like to manage the calculator's memory?\n";
    std::cout << "V - View Memory\nP - Previous Answer Memory\nC - Clear Memory\nB - Back to homescreen\n\n";
    std::getline(std::cin, user_input);

    if (user_input == "V" || user_input == "v"){
        view_memory_string = memory_log.print_memory();
        std::cout << view_memory_string << "\n\nPress Enter to continue.";

        std::string temp;
        std::getline(std::cin, temp);

    }
    else if (user_input == "P" || user_input == "p"){
        double ans = memory_log.get_previous_answer_memory();
        std::cout << "Your most recent answer is " << ans << ".\n"
        << "Refer to the 'History Log' section under 'Help' to see how to use it."
        << view_memory_string << "\n\nPress Enter to continue.";

        std::string temp;
        std::getline(std::cin, temp);
    }
    else if (user_input == "C" || user_input == "c"){
        //insert instructions to clearing memory
    }
    else if (user_input == "B" || user_input == "b"){
        std::cout << "Returning to homescreen now.\n\n";
    }

}
void program(History_Log& memory_log){
    std::string user_input="A", expression_input, expression_string, result_string;
    double result=0;
    size_t memory_size = 0;

    while (user_input != "Q" && user_input != "q"){
        std::cout << "What would you like to do next?\n";
        std::cout << "C - Calculate \nH - Help\nL - History log\nU - Update Log\nQ - Quit\n\n";
        std::getline(std::cin, user_input);

        if (user_input == "C" || user_input == "c"){
            // todo: get the most recent answer
            //       fix error with the history log saving incorrect inputs
            if (memory_log.get_size() < 20){
                std::cout << "Please enter a valid expression: ";
                std::getline(std::cin, expression_input);
                result = calculate(expression_input, memory_log);
                result_string = to_string(result);
                expression_string = expression_input + " = " + result_string;

                // Fix error with saving incorrect inputs
                std::cout << expression_input << " = " << result << "\n\n"
                << "Attempting to save to memory...\n";
                memory_log.insert_into_memory(expression_string);
                std::cout << "Saved to memory successfully! Returning to homescreen now.\n\n"; 
            }
            else if (memory_log.get_size() == 20){
                std::cout << "Warning: Maximum capacity reached. Head to 'History Log' to manage storage.\n\n";
            }
        }

        else if (user_input == "H" || user_input =="h"){
            help();
        }

        else if (user_input == "L" || user_input == "l"){
            history_log(memory_log);
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
    // run the program and create linked list for the history log
    History_Log memory_history;
    program(memory_history);
    return 0;
}