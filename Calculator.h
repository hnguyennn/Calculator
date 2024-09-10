// Calculator.h

#ifndef Calculator_h
#define Calculator_h
#include <string>

//History_Log.cpp
class History_Log {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };
    Node *_head, *_tail, *_prev_to_current;
    size_t _size;
    bool exit;
public:
    History_Log();
    ~History_Log();
    History_Log *insert_into_memory(std::string expression);
    size_t get_size();
    void clear(size_t start, size_t end, bool& exit);
    std::string print_memory();
    double get_previous_answer_memory();
};

//Calculator.cpp
using namespace std;
double calculate(string user_input, History_Log& memory_log);
double calculate_expression(double num1, double num2, std::string sign);
double convert_to_digits(std::string string_num, double previous_answer_memory, bool& success);
void help();
void update_log();
void history_log(History_Log& memory_log);
void program(History_Log& memory_log, bool& exit);



#endif /* Calculator_h */