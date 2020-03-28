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

        void middleElement();
      

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



template<class T>
void Linkedlist<T> :: middleElement()
{
    if(head == NULL)
    {
        cout<<"Linkedllist is empty..!"<<endl;
        return;
    }

    Node<T>*slow = head;
    Node<T>*fast = head->next;

    int count = 0;
    while(fast != NULL)
    {
        if(count % 2 != 0)
        {
            slow = slow->next;
        }
        count++;
        fast = fast->next;

    }
    cout<<slow->data<<endl;
}




int main()
{
    Linkedlist <int> object;

    for(int i = 0; i < 8; i++)
    {
        object.insertionAtEnd(i);
    }

    object.displayLinkedlist();

    object.middleElement();

    return 0;
}
