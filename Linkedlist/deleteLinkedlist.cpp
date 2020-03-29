// Program to delete whole linkedlist

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

void deleteLinkedlist(Node* &head)
{ 
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    Node* current = head;
    Node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL;
    cout<<"Linkedlist is deleted"<<endl;
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
    cout<<"Created Linkedlist"<<endl;

    display(head);

    deleteLinkedlist(head);


    return 0;
}