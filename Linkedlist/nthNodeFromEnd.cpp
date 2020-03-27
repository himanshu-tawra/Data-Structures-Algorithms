#include<iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node<T>*next;

        Node(T d)
        {
            data = d;
            next = NULL;
        }
};


template<class T>
class Linkedlist
{
    Node<T>* head;
    public:
        Linkedlist();
        
        void insertionAtEnd(T element);
        
        void displayLinkedlist();

        void nthNode(T n);
      

};
// constructor 

template<class T>
Linkedlist<T> :: Linkedlist()
{
    head = NULL;
}

// Function to insert the node in a linkedlist from the end.

template<class T>
void Linkedlist<T> :: insertionAtEnd(T element)
{
    if(head == NULL)
    {
        head = new Node<T>(element);
        return;
    }
    Node <T>*temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node<T> *newNode = new Node<T>(element);

    temp->next = newNode;

}



// Function to print the linkedlist

template<class T>
void Linkedlist<T> :: displayLinkedlist()
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    Node <T>*temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



// nth node from the end using two pointers

template<class T>

void Linkedlist<T> :: nthNode(T n)
{
    if(head == NULL)
    {
        cout<<"Lnkedlist is empty"<<endl;
        return;
    }

    Node<T>* slow = head;
    Node<T>*fast = head;

    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }


    cout<<n<<"th node from the end : "<<slow->data<<endl;


}

int main()
{
    Linkedlist <int> object;

    for(int i = 0; i < 7; i++)
    {
        object.insertionAtEnd(i);
    }

    object.displayLinkedlist();

    object.nthNode(3); // 3rd node from the end

    return 0;

}