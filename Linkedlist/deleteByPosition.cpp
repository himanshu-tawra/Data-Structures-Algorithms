// Linked List Deletion (Deleting a key at given position)

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

void deleteKey(Node* &head,int pos)
{ 
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    Node* temp = head;
    if(pos == 0)
    {
        head = head->next;
        delete temp;
    }

    for(int i = 0; i < pos - 1 && temp!= NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        return;
    }

    Node* nextNode = temp->next->next;

    delete temp->next;

    temp->next = nextNode;

    
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

    cout<<"After deletion"<<endl;

    deleteKey(head,3);

    display(head);




    return 0;
}