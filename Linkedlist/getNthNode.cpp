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


int getNode(Node* head,int n)
{
    Node* temp = head;

    int count = 0;

    while(temp != NULL)
    {
        if(count == n)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return -1;
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

    if(getNode(head,3) != 1)
    {
        cout<<getNode(head,3)<<endl;
    }
    else
    {
        cout<<"Node not found"<<endl;
    }
    
    
 





    return 0;
}