// Calculator.h

#ifndef Calculator_h
#define Calculator_h
#include <string>


using namespace std;
double calculate(string user_input);
double calculate_expression(double num1, double num2, std::string sign);
void help();
void update_log();
void history_log();
void program();


#endif /* Calculator_h */