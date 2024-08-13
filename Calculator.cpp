// Calculator.cpp
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int calculate(){
    return 0;
}

void help(){

}

string history_log(){
    return "";
}
void calculator(){
    string user_input="A";

    cout << "What would you like to do next?";


    while (user_input != "Q"){
        cout << "C - Calculate \nH - Help\nL - History log\nQ - Quit";
        getline(cin, user_input);
        if (user_input == "C"){
            calculator();
        }
        else if (user_input == "H"){
            help();
        }
        else if (user_input == "L"){
            history_log();
        }
        else if (user_input == "Q"){
            cout << "Ok, see you next time!";
        }
        else {
            cout << "Invalid input, try again.";
        }
    }
}