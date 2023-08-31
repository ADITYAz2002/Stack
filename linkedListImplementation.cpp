/*
    Head of the Linked List is the top of the stack in this implementation!

*/

#include<iostream>
using namespace std;

struct Node
{
    int data;

    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node* head;

    int sz;

    MyStack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);    //makes new element
        newNode -> next = head;
        head = newNode;
        sz++;                           // increments the value of the stack size 
    }

    int pop()
    {
        if(head == NULL)
            return INT_MAX;

        int val = head -> data;     //takes the value of the top element
        Node* newNode = head;
        head = head -> next;        //Moves to the next element
        delete(head);               
        sz--;                       // Decrements the size of the element
        return val;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int peek()
    {
        if(head == NULL)
            return INT_MAX;
        
        return head -> data;
    }

}