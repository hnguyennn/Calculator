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
    
}

History_Log::~History_Log(){
// Destructor, uses clear() and then deletes the head. Completely erases the history log.
    clear();
    delete _head;
    
}

History_Log* History_Log::insert_into_memory(std::string expression){
// Creates a new node for the expressoin and adds the new expression at the end of the linked list (tail). 
// Returns a pointer to this new node. If it hits the max amount of nodes (expressions), 
// output an error message before the user can input anymore expressions in Calculator.cpp.
// '_prev_to_current' in this context, is the node before the tail

    Node* new_node = new Node(expression); // turn the expression into a new node

    new_node->next = _prev_to_current->next; //new node points to current
    _prev_to_current->next = new_node; // previous points to new node
    _tail = new_node; // new_node is automatically the tail now

    _size += 1;

    // advance _prev_to_current to the next node.
    // if only one node currently exists, _prev_to_current should just stay at _head.
    if (_size > 1){
        _prev_to_current = _prev_to_current->next;
    }

    // Output a warning message if the maximum capacity is reached.
    if (_size == 20){
        std::cout << "Warning: Maximum capacity reached. Head to 'History Log' to manage storage.";
    }

    _prev_to_current = _head;
    return this;
}

size_t History_Log::get_size(){
// Gets the total number of nodes (expressions) that the history log currently holds. Will cap around a certain amount.
    return _size;
}

void History_Log::clear(){
// Resets the history log to 0 nodes (expressions).
// '_prev_to_current' will be the node before '_current', where '_current' is the node being deleted.

    // Empty Memory
    if (_size == 0){
        std::cout << "Error: Memory is already empty.";
        return;
    }

    _prev_to_current = _head; // reset _prev_to_current so _current is on the first node

    Node *_current = _prev_to_current->next, *after;

    for (size_t i = 1; i <= _size; i++){
        after = _current->next;
        delete _current;
        _current = after;
        
    }
    // Reset all pointers to _head
    _tail = _head;
    _prev_to_current = _head;
    _head->next = nullptr;
    _size = 0;
}

std::string History_Log::print_memory(){
// Outputs all expressions, starting from oldest (head) to newest (tail).
    std::stringstream stream;
    std::string stream_string;
    size_t counter = 1;
    Node *_current = _prev_to_current->next;

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

