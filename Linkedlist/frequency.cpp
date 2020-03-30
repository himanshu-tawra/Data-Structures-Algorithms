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


int count(Node* head,int n)
{
    Node* temp = head;
    int check = 0;

    while(temp)
    {
        if(temp->data == n)
        {
            check++;
        }
        temp = temp->next;
    }

    return check;
}


int main()
{
    Node* head;

    insertionAtFront(head,1);
    insertionAtFront(head,8);
    insertionAtFront(head,1);
    insertionAtFront(head,4);
    insertionAtFront(head,1);
    insertionAtFront(head,1);

    displayLinkedlist(head);
    cout<<"Frequency : ";
    cout<<count(head,1);
  
    
    
    return 0;
}