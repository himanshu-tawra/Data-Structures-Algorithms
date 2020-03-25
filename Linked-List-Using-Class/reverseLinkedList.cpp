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


void reverseLinkedList(Node * &head)
{
    Node *current = head;
    Node *prev = NULL;
    while(current)
    {
        Node *newNode = current->next;
        current->next = prev;
        prev = current;
        current = newNode;
    }

    head = prev;

}



int main()
{
    Node * head = NULL;

    insertionAtFront(head,10);
    insertionAtFront(head,8);
    insertionAtFront(head,5);
    insertionAtFront(head,2);
    insertionAtFront(head,1);

    displayLinkedList(head);

    reverseLinkedList(head);

    displayLinkedList(head);

    return 0;
}