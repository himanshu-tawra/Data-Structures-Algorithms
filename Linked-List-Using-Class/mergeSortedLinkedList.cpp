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

void insertionAtFront(Node * &head,int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
}

void displayLinkedList(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        cout<<head->data<<"-->";
        head = head ->next;
    }
    cout<<"NULL"<<endl;
}


Node *mergeSortedLinkedList(Node * h1,Node * h2)
{
    if(h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }

    Node *newhead;
    
    if(h1->data < h2->data)
    {
        newhead = h1;
        newhead->next = mergeSortedLinkedList(h1->next,h2);
    }
    else
    {
        newhead = h2;
        newhead->next = mergeSortedLinkedList(h1,h2->next);
    }

    return newhead;
    
}


int main()
{
    Node * h1 = NULL;

    Node * h2 = NULL;

    for(int i = 10; i >= 1; i-=2)
    {
        insertionAtFront(h1,i);
    }
    
    for(int i = 9; i >= 1; i-=2)
    {
        insertionAtFront(h2,i);
    }
    cout<<"Before Merging Linked Lists"<<endl;

    displayLinkedList(h1);
    
    displayLinkedList(h2);

    Node *newHeadOfLinkedList = mergeSortedLinkedList(h1,h2);

    cout<<"After Merging Linked Lists"<<endl;

    displayLinkedList(newHeadOfLinkedList);


    return 0;
}