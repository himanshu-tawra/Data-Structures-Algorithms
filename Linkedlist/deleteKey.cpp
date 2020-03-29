//Linked List Deletion (Deleting a given key)

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


//Insertion at the end
void insertionFromBack(Node* &head , int element)
{
    Node* temp = head;
    if(temp == NULL)
    {
        head = new Node(element);
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(element);

    temp->next = newNode;


}

void deleteKey(Node* &head,int key)
{ 
    Node *temp = head, *previous;

    if(temp->data == key && temp != NULL)
    {
        head = head->next;
        delete temp;
        return;
    }
    
    while(temp->data != key && temp != NULL)
    {
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout<<"Node not found in the linkedlist"<<endl;
        return;
    }
    previous->next = temp->next;
    delete temp;
}

void display(Node *head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;

    }
    cout<<"NULL"<<endl;
}


int main()
{

    Node *head;

    insertionFromBack(head,10);
    insertionFromBack(head,8);
    insertionFromBack(head,12);
    insertionFromBack(head,15);
    insertionFromBack(head,21);
    insertionFromBack(head,5);

    display(head);

    deleteKey(head,15);

    display(head);




    return 0;
}