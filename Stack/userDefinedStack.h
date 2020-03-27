#include<iostream>
#include "Node.h"
using namespace std;


template<class T>
class Stack
{
    Node <T>*head;
    public:
        Stack();
        void push(T);
        void pop();
        void top();
        bool isEmpty();
        void display();

};

template<class T>
Stack<T> :: Stack()
{
    head = NULL;
}


template<class T>
void Stack<T> :: push(T element)
{
    Node<T> *temp = new Node<T>(element);
    if(head == NULL)
    {
        head = temp;
        return;
    }

    temp ->next = head;
    head = temp;
}


template<class T>
void Stack<T> :: pop()
{
    if(head == NULL)
    {
        cout<<"Stack is already empty"<<endl;
        return;
    }

    Node <T>* temp = head;
    head = head->next;
    delete temp;

}


template<class T>
void Stack<T> :: top()
{
    if(head == NULL)
    {
        cout<<"Stack is empty..!"<<endl;
    }
    else
    {
        cout<<"Top element : "<<head->data<<endl;
    }
    
}

template<class T>
bool Stack <T>:: isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


template<class T>
void Stack<T> :: display()
{
    Node <T>*temp = head;
    if(temp == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

