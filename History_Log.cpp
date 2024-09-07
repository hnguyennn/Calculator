// History_Log.cpp
#include "Calculator.h"


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
// Returns a pointer to this new node. If it hits the max amount of nodes (expressions), output an error message.
}

size_t History_Log::get_size(){
// Gets the total number of nodes (expressions) that the history log currently holds. Will cap around a certain amount.
    return 0;
}

void History_Log::clear(){
// Resets the history log to 0 nodes (expressions).
}

void History_Log::print_memory(){
// Outputs all expressions, starting from oldest (head) to newest (tail).
}

