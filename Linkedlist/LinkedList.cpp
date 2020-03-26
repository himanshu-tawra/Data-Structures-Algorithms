// Implementation of Linkedlist

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
        void insertionAtFront(T element);
        void insertionAtEnd(T element);
        void deletionFromFront();
        void deletionFromEnd();
        void displayLinkedlist();
        void lengthOfLinkedlist();

};
// constructor 

template<class T>
Linkedlist<T> :: Linkedlist()
{
    head = NULL;
}

// Function to insert the node at the begining of the linkedlist

template<class T>
void Linkedlist<T> :: insertionAtFront(T element)
{
    if(head == NULL)
    {
        head = new Node<T>(element);
        return;
    }
    if(head != NULL)
    {
        Node <T>*temp = new Node<T>(element);
        temp->next = head;
        head = temp;
    }
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

// Function to delete the node from the front of a linkedlist

template<class T>
void Linkedlist<T> :: deletionFromFront()
{
    if(head == NULL)
    {
        cout<<"Linkedlist is already empty..!!"<<endl;
        return;
    }
    Node <T>*temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the node from the end of the linkedlist

template<class T>
void Linkedlist<T> :: deletionFromEnd()
{
    Node <T>*temp = head;
    if(temp == NULL)
    {
        cout<<"Linkedlist is already empty..!!"<<endl;
        return;
    }
    if(temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next; 
    }
    Node<T> *targetDelete = temp->next;

    temp->next = NULL;

    delete targetDelete;
    return;
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

// Function to find the length of the linkedlist

template<class T>
void Linkedlist<T> :: lengthOfLinkedlist()
{
    int count = 0;
    Node <T> *temp = head;
    if(temp == NULL)
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    cout<<"Length of linkedlist : "<<count<<endl;

}




//main function

int main()
{

    Linkedlist <int> object;
    
    int choice;
    while(1)
    {
        cout<<"<-------------Linkedlist------------->"<<
        endl<<"Enter your choice"<<endl<<"1.Insert from front"<<endl<<"2.Insert from back"<<endl
        <<"3.Delete from front"<<endl<<"4.Delete from back"<<endl<<"5.Check length of Linkedlist"<<endl
        <<"6.Print the Linkedlist"<<endl<<"7.Exit"<<endl;

        cin>>choice;
        int element;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element"<<endl;
            cin>>element;
            object.insertionAtFront(element);
            break;

        case 2:
            cout<<"Enter the element"<<endl;
            cin>>element;
            object.insertionAtEnd(element);
            break;

        case 3:
            object.deletionFromFront();
            break;

        case 4:
            object.deletionFromEnd();
            break;

        case 5:
            object.lengthOfLinkedlist();
            break;

        case 6:
            object.displayLinkedlist();
            break;
        
        case 7:
            exit(0);

        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}