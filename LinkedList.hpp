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
        int getFront();
        int removeFront();
        void addEnd(int payload);
        int getEnd();
        int removeEnd();
        void display();
        void addAtIndex(int index, int payload);
        int getIndex(int index);
        int removeIndex(int index);
        void sort();
        bool isSorted();

    };
#endif /* LinkedList_hpp */