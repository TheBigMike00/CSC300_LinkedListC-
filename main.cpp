#include "LinkedList.hpp"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));

    LinkedList* mylist = new LinkedList();
    std::cout<<"Initial List: "<<"\n";
    mylist->addFront(71);
    mylist->addEnd(6);
    mylist->addEnd(3);
    mylist->addEnd(5);
    mylist->addEnd(4);
    mylist->addEnd(2);
    mylist->addEnd(1);
    mylist->display();
    mylist->sort();
    //std::cout<<"Number of elements: "<< <<"\n";
    std::cout<<"After sort: "<<"\n";
    mylist->display();
    //std::cout<<"After removal: "<<"\n";
    //mylist->display();

    /*
    std::cout<<"Add value to end: "<<"\n";
    mylist->addEnd(100);
    mylist->display();
    std::cout<<"Last Value: "<<mylist->getEnd()<<"\n";
    std::cout<<"Remove last value: ("<<mylist->removeEnd()<<")\n";
    mylist->display();
    */
    delete mylist;
}