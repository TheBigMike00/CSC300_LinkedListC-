#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

class LinkedList
{
    //declares fields for LinkedList.cpp
    //Head points to fist node and count number of 
    //elements in the list
    private: 
        Node* head;
        int count;

    //declares methods for LinkedList.cpp
    public: 
        LinkedList(); 
        void addFront(int payload);
        void display();
};
#endif /* LinkedList_hpp */