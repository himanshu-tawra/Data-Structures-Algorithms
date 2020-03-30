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


void displayLinkedlist(Node* head)
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!"<<endl;
        return;
    }

    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void insertionAtBack(Node* &head,int element)
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

    Node* newNode = new Node(element);

    temp->next = newNode;
}

int countNode(Node* head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int countRecursive(Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    int count = countRecursive(head->next) + 1;
    return count;
}


int main()
{
    Node* head = NULL;
    insertionAtBack(head,10);
    insertionAtBack(head,20);
    insertionAtBack(head,30);
    insertionAtBack(head,40);
    insertionAtBack(head,50);

    displayLinkedlist(head);

    int nodes = countNode(head);

    cout<<"Number of nodes (iterative) : "<<nodes<<endl;

    int nodesRecursive = countRecursive(head);

    cout<<"Number of nodes (recursive) : "<<nodesRecursive<<endl;



    return 0;
}