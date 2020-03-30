#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
};

void insertionAtFront(Node* &head,int element)
{
    if(head == NULL)
    {
        head = new Node(element);
        return;
    }

    Node* temp = new Node(element);
    temp->next = head;
    head = temp;

}

void displayLinkedlist(Node* head)
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    cout<<"Created Linkedlist "<<endl;
    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


void searchNode(Node* head,int key)
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    while(head != NULL)
    {
        if(head->data == key)
        {
            cout<<"Node Found (Iterative) "<<endl;
            return;
        }
        head = head->next;
    }
    cout<<"Node not found (Iterative)"<<endl;

}

void searchRecursive(Node* head,int key)
{
    if(head == NULL)
    {
        cout<<"Node not found (Recursive)"<<endl;
        return;    
    }
    if(head->data == key)
    {
        cout<<"Node Found (Recursive) "<<endl;
        return;
    }

    return searchRecursive(head->next,key);
}

int main()
{
    Node* head;

    insertionAtFront(head,10);
    insertionAtFront(head,8);
    insertionAtFront(head,6);
    insertionAtFront(head,4);
    insertionAtFront(head,2);
    insertionAtFront(head,1);

    displayLinkedlist(head);

    searchNode(head,6);

    searchRecursive(head,11);





    return 0;
}