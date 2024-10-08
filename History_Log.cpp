// History_Log.cpp
#include "Calculator.h"
#include <iostream>
#include <sstream>


History_Log::History_Log(){
// Constructor. Creates and initializes the history log.
    _head = new Node("_SENTINEL_");
    _tail = _head;
    _head->next = nullptr;
    _prev_to_current = _head;
    _size = 0;
    exit = true;
    
}

History_Log::~History_Log(){
// Destructor, uses clear() and then deletes the head. Completely erases the history log.
    clear(1, _size, exit);
    delete _head;
    
}

History_Log* History_Log::insert_into_memory(std::string expression){
// Creates a new node for the expressoin and adds the new expression at the end of the linked list (tail). 
// Returns a pointer to this new node. If it hits the max amount of nodes (expressions), 
// output an error message before the user can input anymore expressions in Calculator.cpp.
// _prev_to_current is not used here.


    Node* new_node = new Node(expression); // turn the expression into a new node

    if (_size == 0){
        _head->next = new_node;
    }
    else{
        _tail->next = new_node; // new_node is automatically the tail now
    }
    _tail = new_node;
    _size += 1;

    // Output a warning message if the maximum capacity is reached.
    if (_size == 20){
        std::cout << "Warning: Maximum capacity reached. Head to 'History Log' to manage storage.";
    }

    return this;
}

size_t History_Log::get_size(){
// Gets the total number of nodes (expressions) that the history log currently holds. Will cap around a certain amount.
    return _size;
}

void History_Log::clear(size_t start, size_t end, bool& exit){
// Resets the history log to 0 nodes (expressions).
// '_prev_to_current' will be the node before '_current', where '_current' is the node being deleted.

    // Empty Memory
    if (_size == 0 && exit == false){
        std::cout << "Error: Memory is already empty.\n\n";
        return;
    }

    _prev_to_current = _head; // reset _prev_to_current so _current is on the first node

    Node *_current = _prev_to_current->next, *_marker = _head, *after;

    // Advance _marker to be the node before the start position.
    for (size_t i = 1; i < start; i++){
        _marker = _current;
        _current = _current->next;  
    }

    // At the start position, delete all nodes until the end position (inclusive).
    for (size_t j = start; j <= end; j++){
        after = _current->next;
        delete _current;
        _current = after;
        _size -= 1;
        
    }

    // Reset pointers to correct spots
    _tail = _head;
    _marker->next = _current; // Reattach the list together if the section removed was in the middle.
    for (size_t k = 1; k <= _size; k++){ // Fix _tail's spot if the section removed was in the middle.
        _tail = _tail->next;
    }
    _prev_to_current = _head; // Reset for future use
    
}

std::string History_Log::print_memory(){
// Outputs all expressions, starting from oldest (head) to newest (tail).
    std::stringstream stream;
    std::string stream_string;
    size_t counter = 1;
    Node *_current = _head->next;

    stream << "# " << "         Expression\n"
    << "------------------------------\n";
    while (_current != nullptr){
        stream << counter << "          " << _current->data << "\n";
        _current = _current->next;
        counter += 1;
    }

    stream_string = stream.str();
    return stream_string;
}

double History_Log::get_previous_answer_memory(){
// Finds and returns the most recent answer from the expression inputted by the user.
    std::string expression = _tail->data, character;
    std::stringstream stream;
    double previous_answer = 0.0;

    // If there are currently no expressions saved to memory:
    if (_size == 0){
        return previous_answer;
    }
    // The expression should be the most recent one (at the tail of this linked list).
    stream << expression;

    // Attempting to find the "=" sign. The answer of this expression should be directly after this sign.
    while (stream >> character){
        if (character == "="){
            stream >> previous_answer;
            return previous_answer;
        }
    }
}

