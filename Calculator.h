// Calculator.h

#ifndef Calculator_h
#define Calculator_h
#include <string>

//Calculator.cpp
using namespace std;
double calculate(string user_input);
double calculate_expression(double num1, double num2, std::string sign);
void help();
void update_log();
void history_log();
void program();

//History_Log.cpp
class History_Log {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };
    Node *_head, *_tail, *_prev_to_current;
    size_t _size = 0;
public:
    History_Log();
    ~History_Log();
    History_Log *insert_into_memory(std::string expression);
    size_t get_size();
    void clear();
    std::string print_memory();
};

#endif /* Calculator_h */