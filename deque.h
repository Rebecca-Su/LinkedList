//Written by: Rebecca Su
//Student ID: 20760868

#include <iostream>
class Node {
    friend class List;
public:
    Node(int input);
private:
    int i;
    Node *p_next; 
    Node *p_prev;
};

class List {
public:
    List();
    ~List();
    void enqueue_front(int input);
    void enqueue_back(int input);
    void dequeue_front();
    void dequeue_back();
    void clear();
    int front();
    int back();
    void empty();
    void get_size();
    void print();
private:
    Node *head;
    Node *tail;
    int size;
};

class DequeError
{
};

