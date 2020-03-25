#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
};

class Linkedlist
{
    public:
        Node* head;
        Linkedlist();
        void backInsertion(int);
        void frontInsertion(int);
        void backDeletion();
        void frontDeletion();
        void displayLinkedList();
};


Linkedlist :: Linkedlist()
{
    head = NULL;
}

void Linkedlist :: backInsertion(int element)
{
    Node * newNode = new Node(element);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


void Linkedlist :: frontInsertion(int element)
{
    Node * newNode = new Node(element);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void Linkedlist :: backDeletion()
{
    Node *temp = head;
    if(temp == NULL)
    {
        cout<<"Linkedlist is already empty"<<endl;
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
    Node *currentNode = temp->next;
    temp->next = NULL;
    delete currentNode;
    return;

}

void Linkedlist :: frontDeletion()
{
    Node *temp = head;
    if(head == NULL)
    {
        cout<<"Linkedlist is already empty"<<endl;
        return;
    }
    head = temp->next;
    temp = NULL;
    delete temp;
    return;

}

void Linkedlist :: displayLinkedList()
{
    Node *temp = head;
    if(temp == NULL)
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    cout<<"<---------Linkedlist----------->"<<endl;
    while (temp)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}


int main()
{
    Linkedlist object;

    int choice;
    while(1)
    {
        cout<<"<-----------Menu----------->"<<endl<<"1.Insert at Back"<<endl<<"2.Insert at Front"<<endl<<"3.Delete from Back"<<endl<<"4.Delete from Front"<<endl<<"5.Display"<<endl<<"6.Exit"<<endl<<"Enter your choice"<<endl;
        cin>>choice;
    

        switch (choice)
        {
        case 1:
            int element;
            
            cout<<"Enter the element "<<endl;
            cin>>element;
            object.backInsertion(element);
            break;

        case 2:
            cout<<"Enter the element "<<endl;
            cin>>element;
            object.frontInsertion(element);
            break;

        case 3:
            object.backDeletion();
            break;

        case 4:
            object.frontDeletion();
            break;

        case 5:
            object.displayLinkedList();
            break;

        case 6:
            exit(0);

        
        default:
            cout<<"Enter a valid choice"<<endl;
        }
    }

    return 0;
}