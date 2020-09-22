//Written by: Rebecca Su
//Student ID: 20760868

#include <iostream>
#include "deque.h"

//Node constructor : Initializes all Node member variables
Node::Node(int input)
{
    i = input;
    p_next = nullptr;
    p_prev = nullptr;
}

//List constructor : Initializes all List member variables
List::List()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

//List destructor : Removes all nodes from the list
List::~List()
{
    this->clear();
}

//Inserts a node at the front of the list
void List::enqueue_front(int input)
{
    Node* new_node = new Node(input);
    Node* next_node;
    
    if(head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        next_node = head;
        new_node->p_next = next_node;
        next_node->p_prev = new_node;
        head = new_node;
    }
    
    size += 1;
    std::cout << "success" << std::endl;
}

//Inserts a node at the back of the list
void List::enqueue_back(int input)
{
    Node* new_node = new Node(input);
    Node* prev_node;
    
    if(head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        prev_node = tail;
        new_node->p_prev = prev_node;
        prev_node->p_next = new_node;
        tail = new_node;
    }
    
    size +=1;
    std::cout << "success" << std::endl;
}

//Removes the node at the front of the list
void List::dequeue_front()
{
    if(head == nullptr)
        throw DequeError();
    
    if(head->p_next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size -= 1;
        std::cout << "success" << std::endl;
        return;
    }
    
    Node* current = head;
    
    head = head->p_next;
    head->p_prev = nullptr;
    
    delete current;
    current = nullptr;
    
    size -= 1;
    std::cout << "success" << std::endl;
}

//Removes the node at the back of the list
void List::dequeue_back()
{
    if(tail == nullptr)
        throw DequeError();
    
    if(head->p_next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size -= 1;
        std::cout << "success" << std::endl;
        return;
    }
    
    Node* current = tail;
    
    tail = tail->p_prev;
    tail->p_next = nullptr;
    
    delete current;
    current = nullptr;
    
    size -= 1;
    std::cout << "success" << std::endl;
}

//Removes all nodes of the list
void List::clear()
{
    Node *current = nullptr;
    Node *traverse = nullptr;
    
    current = head;
    while(current != nullptr)
    {
        traverse = current->p_next;
        delete current;
        current = traverse;
    }
    delete current;
    current = nullptr;
    delete traverse;
    traverse = nullptr;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Returns the integer stored in the first node
int List::front()
{
    if(head == nullptr)
        throw DequeError();
    
    return head->i;
}

//Returns the integer stored in the last node
int List::back()
{
    if(tail == nullptr)
        throw DequeError();
    
    return tail->i;
}

//Checks if the list is empty
void List::empty()
{
    if(head == nullptr)
        std::cout << "success" << std::endl;
    if(head != nullptr)
        std::cout << "failure" << std::endl;
}

//Gets the size of the list
void List::get_size()
{
    std::cout << "size is " << size << std::endl;
}

//Prints out the list from front to back, then in reverse
void List::print()
{
    Node *front;
    Node *back;
    front = head;
    back = tail;
    
    while(front != nullptr)
    {
        if(front->p_next == nullptr)
        {
            std::cout << front->i << std::endl;
            break;
        }
        std:: cout << front->i << " ";
        front = front->p_next;
    }
    
    while(back != nullptr)
    {
        if(back->p_prev == nullptr)
        {
            std::cout << back->i << std::endl;
            break;
        }
        std:: cout << back->i << " ";
        back = back->p_prev;
    }
}
