#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{ 
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    //creates node to be added to front
    Node* newNode = new Node(payload);
    
    if(!this->head)
    {
        //if the head does not point anywhere, 
        //set the head to the new node
        this->head = newNode;
    }
    else
    {
        //otherwise adjust affected pointers and
        //lastly set the head
        newNode->setNextNode(this->head);
        this->head = newNode;
    }    

    //increase count once node is added
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload();
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

void LinkedList::addEnd(int payload)
{
    Node* newNode = new Node(payload);
    Node* temp = this->head;
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
        for(int i = 1; i<=this->count-1; i++) //while(temp->getNextNode())
        {
            temp = temp->getNextNode(); //(*temp).getNextNode();
        }
    }
    temp->setNextNode(newNode);
    this->count++;
}

int LinkedList::getEnd()
{
    Node* traverse = this->head;
    for(int i = 1; i<=this->count-1; i++)
    {
        traverse = traverse->getNextNode();
    }
    return traverse->getPayload();
}

int LinkedList::removeEnd()
{
    int val;
    if (!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        Node* firstTraverse = this->head;
        while(firstTraverse->getNextNode() != 0)
        {
            firstTraverse = firstTraverse->getNextNode();

        }

        Node* secondTraverse = this->head;
        while(secondTraverse->getNextNode() != firstTraverse)
        {
            secondTraverse = secondTraverse->getNextNode();
        }
        firstTraverse->setNextNode(0);
        secondTraverse->setNextNode(0);
        val = firstTraverse->getPayload();
        delete firstTraverse;
        this->count--;
        return val;
    }
}

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else if (index == this->count)
    {
        this->addEnd(payload);
    }
    else
    {
        Node* newNode = new Node(payload);
        Node* firstPoint = this->head->getNextNode();
        Node* beforePoint = this->head;

        for(int i = 1; i<index; i++)
        {
            firstPoint = firstPoint->getNextNode();
            beforePoint = beforePoint->getNextNode();
        }

        beforePoint->setNextNode(newNode);
        newNode->setNextNode(firstPoint);
        this->count++; 
    } 
}

int LinkedList::removeIndex(int index)
{
    int val;
    if(index == 0)
    {
        val = this->removeFront();
    }
    else if (index == this->count-1)
    {
        val = this->removeEnd();
    }
    else
    {
        Node* firstPoint = this->head->getNextNode();
        Node* beforePoint = this->head;

        for(int i = index-1; i>0; i--)
        {
            firstPoint = firstPoint->getNextNode();
            beforePoint = beforePoint->getNextNode();
        }
        val = firstPoint->getPayload();
        beforePoint->setNextNode((firstPoint->getNextNode()));
        firstPoint->setNextNode(0);
        this->count--;
    } 
    return val;
}

int LinkedList::getIndex(int index)
{
    Node* traverse = this->head;
    for(int i = index; i>0; i--)
    {
        traverse = traverse->getNextNode();
    }
    return traverse->getPayload();
}

bool LinkedList::isSorted()
{
    Node* first = this->head->getNextNode();
    Node* second = this->head;
    for(int i = 0; i<this->count-1; i++)
    {
       if(first->getPayload()>second->getPayload())
       {
           first = first->getNextNode();
           second = second->getNextNode();
       }
       else if (first->getPayload()<second->getPayload())
       {
           return false;
       }
    }
    return true;
}

void LinkedList::sort()
{
    Node* firstPoint;
    Node* secondPoint;
    while(isSorted() == false)
    {
        firstPoint = this->head->getNextNode();
        secondPoint = this->head;
        for(int j = 0; j<this->count-1; j++)
        {
            if (firstPoint->getPayload()<secondPoint->getPayload())
            {
                Node* tempNode = new Node(firstPoint->getPayload());
                secondPoint->setNextNode(firstPoint->getNextNode());
                firstPoint->setNextNode(0);
                if(secondPoint==this->head)
                {
                    addFront(tempNode->getPayload());
                }
                else
                {
                    addAtIndex(getIndex(j-1), tempNode->getPayload());
                }
                //removeIndex(getIndex(j));
                this->count--;
                firstPoint = this->head->getNextNode();
                secondPoint= this->head;
                j=0;

            }
            else
            {
                std::cout<<"count: "<< this->count<<"\n";
                std::cout<<"Before payload: "<< secondPoint->getPayload()<<"\n";
                std::cout<<"Current payload: "<< firstPoint->getPayload()<<"\n";
            }

            if (firstPoint->getNextNode()!=0)
            {
                firstPoint = firstPoint->getNextNode();
                secondPoint = secondPoint->getNextNode();
            }
        }
        std::cout<<"is sorted? "<< isSorted() <<"\n";
    }

}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i<this->count; i++)
    {
        std::cout<<currNode->getPayload()<<"\n";
        currNode = currNode->getNextNode();
    }
}